
# Computer Graphics and Multimedia Lab – Assignment 2

## Student Information

| Detail | Information |
|---|---|
| **Name** | Aasi Mishra |
| **Roll Number** | IC-2K24-03 |
| **Course** | Integrated MCA |
| **Subject** | Computer Graphics and Multimedia |
| **Lab** | Lab 2 |

---

## Practical 1: Digital Differential Analyzer (DDA) Line Drawing Algorithm

**File Name:** `dda_line.cpp`

### Aim
To implement the Digital Differential Analyzer (DDA) Line Drawing Algorithm in C++ to draw a straight line between two given points using a graphics library.

### Logic
The DDA algorithm generates intermediate points between two endpoints to draw a straight line.

1. Accept the starting point `(x1, y1)` and ending point `(x2, y2)` from the user.
2. Calculate the differences:
   - `dx = x2 - x1`
   - `dy = y2 - y1`
3. Calculate the number of steps using the maximum absolute difference:
   - `steps = max(|dx|, |dy|)`
4. Calculate the increments:
   - `xIncrement = dx / steps`
   - `yIncrement = dy / steps`
5. Start from the initial point and increment the x and y coordinates in each iteration.
6. Round off the coordinates and plot each pixel using `putpixel()`.
7. Mark the starting and ending points and display the calculated values.

**Special Case:** If both endpoints are identical, the algorithm plots only that single point.

### Formula

\[
steps = \max(|dx|, |dy|)
\]

\[
xIncrement = \frac{dx}{steps}
\]

\[
yIncrement = \frac{dy}{steps}
\]

### Sample Input

```text
Enter starting point (x1 y1): 100 150
Enter ending point (x2 y2): 300 250
```

### Sample Output

```text
=== DDA Line Drawing Algorithm ===
Drawing area: x = 20 to 620, y = 110 to 430

Enter starting point (x1 y1): 100 150
Enter ending point (x2 y2): 300 250

dx = 200, dy = 100, steps = 200
x_increment = 1.000, y_increment = 0.500
```

### Graphical Output

The program displays:
- A rectangular drawing boundary.
- A white line generated using the DDA algorithm.
- Yellow circles marking the starting and ending points.
- The coordinates of both endpoints.
- Calculated values of `dx`, `dy`, and `steps`.

### Concepts Used
- DDA Line Drawing Algorithm
- Graphics Programming in C++
- Pixel Plotting using `putpixel()`
- Loops and Conditional Statements
- Floating-Point Arithmetic
- Coordinate Geometry

---

## Technologies Used

- **Programming Language:** C++
- **Graphics Library:** `graphics.h`
- **Header Files:** `conio.h`, `stdio.h`, `stdlib.h`, `math.h`

## Learning Outcomes

- Understanding the working of the DDA Line Drawing Algorithm.
- Learning how to calculate intermediate coordinates.
- Understanding pixel-based line generation.
- Implementing basic computer graphics using C++.

---

**Submitted By:** Aasi Mishra  
**Roll Number:** IC-2K24-03
