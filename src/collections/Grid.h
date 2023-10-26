//
// Created by Tomasz Stachowiak on 25.10.23.
//

#ifndef FRACTALS3_FIELD_H

#define FRACTALS3_FIELD_H

#include <type_traits>
#include <tuple>
#include <algorithm>
#include <functional>


template<typename TElement>
class Grid {
public:
    const int width;
    const int height;

    typedef TElement element;
    typedef TElement *iterator;
    typedef const TElement *const_iterator;

    Grid(int width, int height) : width(width), height(height), data{new element[width * height]} {
    }

    element operator[](int x, int y) const {
        return this->data[indexOf(x, y)];
    }

    element &operator[](int x, int y) {
        return this->data[indexOf(x, y)];
    }

    iterator begin() {
        return data;
    }

    iterator end() {
        return data + width * height;
    }

    const_iterator begin() const {
        return data;
    }

    const_iterator end() const {
        return data + width * height;
    }

    template<typename Func>
    [[nodiscard]]
    auto map(Func f) -> Grid<std::invoke_result_t<Func, element>> && {
        auto newGrid = new Grid<std::invoke_result_t<Func, element>>{width, height};

        std::transform(this->begin(), this->end(), newGrid->begin(), f);

        return std::move(*newGrid);
    }

    template<typename Func>
    void forEach(Func f) {
        for (int x = 0; x < width; x++)
            for (int y = 0; y < height; y++)
                f(this->operator[](x, y), std::make_tuple(x, y));
    }

private:
    TElement *const data;

    [[nodiscard]] int indexOf(int x, int y) const {
        return x + y * width;
    }
};

#endif //FRACTALS3_FIELD_H
