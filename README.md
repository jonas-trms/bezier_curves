# A graphic Bézier curve generator

This algorithm calculates a given number of points belonging to the curve parameterized by the points provided as input, then generates a plot made up of the calculated points.

The user interface in the console offers the possibility to add and delete points, to generate the Bézier curve parameterized by the the entered points and to generate a ppm image of the canvas.

# Execution
Argument : path for the generated image in ppm format

The program will ask the user to set a canvas size

# Commands
**add x y**: adds a point at _relative_ coordinates (x, y) on the canvas, with x, y in [0,1]

**generate n**: generates a plot made of n points on the curve parameterized by the points provided as input, with n being a natural number

**blank**: clears the canvas, deletes all points

**quit**

# Example
![](https://i.imgur.com/WRhWo9Q.png) \
A curve parametrized by the points (0.1; 0.4), (0.7; 0.6), (0.4; 0.2), (0.2; 0.9)
