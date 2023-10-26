# Description

This is my training project for C++23 and CMake. It draws fractals using the grid of complex numbers.
There's a substantial boilerplate code in the project, it may seem as an overkill for such a simple task.
However, I wanted to try out some of the C++ features and CMake.

# Building (Linux, MacOS, WSL2)

Run in the main project folder

```shell
cmake .
make
```

# Running

```shell
./fractals3
```

# Configuration

Please check the `config-*.json` files in the config folder as examples.
Currently, the `config.json` file in the main folder is used for the configuration.

## Configuring the grid

The grid is not much more than a 2D array of complex values. Each value is a complex number from the range
set in the configuration file.

To set the grid range, use the `grid` section in the configuration file. The `center` specifies
the central value on the grid while the `scale` tells how much the value changes on the grid points.
By the fault, the grid will have the `width` and `height` equal to the ouput image resolution.

Example.

```json
{
  ...,
  "grid": {
    "center": {
      "re": 0.0,
      "im": 0.0
    },
    "scale": 0.01
  },
  "output": {
    ...,
    "resolution": {
      "width": 800,
      "height": 600
    }
  }
}
```

Would draw the fractal in 800x600 resolution in the range from `-400 * 0.01` to `400 * 0.01` horizontally
and from `-i300 * 0.01` to `i300 * 0.01` vertically.

## Configuring the fractal

There are two versions available: "julia" and "mandelbrot". The "julia" version is a bit more
complex and allows to specify the "c" parameter of the function. The "mandelbrot" version
is a bit simpler and does not require the "c" parameter.

To set the fractal type, use the `fractal` section in the configuration file. The `type` specifies
the fractal type. The `c` parameter is only used for the "julia" type.
The `maxIterations` specifies the maximum number of iterations to perform for each point on the grid.

To change the transformations generating the fractals check the `AlgorithmFactory`. Currently, both fractal types
use the standard `z -> z * z + c` function.

## Configuring the output

The `output` section in the configuration file specifies
the output file name and the resolution of the output image.
Currently only Bitmap output is supported. 
