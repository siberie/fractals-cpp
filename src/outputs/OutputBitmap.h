//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_OUTPUT_BITMAP_H
#define FRACTALS3_OUTPUT_BITMAP_H

#include <utility>

#include "../../vendor/EasyBMP/EasyBMP.h"

class OutputBitmap : public Output {
public:
    const std::string filename;
    const int width;
    const int height;

    OutputBitmap(std::string filename, int width, int height)
            : filename(std::move(filename)), width(width), height(height) {}

    void write(Grid<Color> fractal) final {
        BMP Output;

        Output.SetSize(width, height);
        Output.SetBitDepth(32);

        fractal.forEach(
                [&](auto color, auto coords) {
                    uint8_t r, g, b;
                    int x, y;
                    std::tie(r, g, b) = color;
                    std::tie(x, y) = coords;

                    Output.SetPixel(
                            x, y, {
                                    (ebmpBYTE) r,
                                    (ebmpBYTE) g,
                                    (ebmpBYTE) b,
                                    255
                            }
                    );
                }
        );

        Output.WriteToFile(filename.c_str());
    }
};

#endif //FRACTALS3_OUTPUT_BITMAP_H
