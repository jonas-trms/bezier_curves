# A graphic Bézier curve generator

This algorithm calculates a given number of points belonging to the curve parameterized by the points provided as input, then generates a plot made up of the calculated points.

The user interface in the console offers the possibility to add and delete points, to generate the Bézier curve parameterized by the entered points and to clear the canvas. A `.ppm` image is generated at each change operated on the canvas.

## Compilation
You can compile with GCC by running the following command:

```
$ gcc -o bezier_curves main.c bezier_computations.c canvas_operations.c linked_lists.c -lm
```

## Usage
The first command line argument expects the path to the `.ppm` output file. The program will ask the user to set a canvas size. From then, the program works like a CLI. There are four commands:
* `add x y` adds a point at _relative_ coordinates (`x`, `y`) on the canvas, with `x`, `y` being `float` values in [0,1]
* `generate n` generates a plot made of `n` points on the curve parameterized by the points provided as input, with `n` being an `int`
* `blank` clears the canvas and deletes all points
* `quit`

## Example
```
$ ./bezier_curves curves.ppm
Please choose width & height
350 350
add 0.1 0.4
add 0.7 0.6
add 0.4 0.2
add 0.2 0.9
generate 400
quit
```

![A curve parametrized by the points (0.1, 0.4), (0.7, 0.6), (0.4, 0.2), (0.2, 0.9)](https://i.imgur.com/WRhWo9Q.png) \
A curve parametrized by the points (0.1, 0.4), (0.7, 0.6), (0.4, 0.2), (0.2, 0.9)
