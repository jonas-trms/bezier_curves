# A graphic Bézier curve generator

This algorithm calculates a given number of points belonging to the curve parameterized by the points provided as input, then generates a plot made up of the calculated points.

The user interface in the console offers the possibility to add and delete points, to generate the Bézier curve parameterized by the entered points and to clear the canvas. A PPM image is generated at each change operated on the canvas.

# Compilation
You can compile with GCC by running the following command:

```
$ gcc -o bezier_curves main.c bezier_computations.c canvas_operations.c linked_lists.c -lm
```

# Execution
Argument: path for the generated image.

The program will ask the user to set a canvas size.

# Commands
When the progam is running, you can interact with it by writting commands. Here is the list of available commands:
- **add _x_ _y_**: adds a point at _relative_ coordinates _(x, y)_ on the canvas, with _x_, _y_ in [0,1]
- **generate _n_**: generates a plot made of _n_ points on the curve parameterized by the points provided as input, with _n_ being a natural number
- **blank**: clears the canvas, deletes all points
- **quit**

# Example
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
