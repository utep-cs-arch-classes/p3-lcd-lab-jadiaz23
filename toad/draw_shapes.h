#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <lcdutils.h>

/* draws a rectangle */
void draw_rectangle(int height, int width, int row, int col ,u_int blue, u_int green, u_int red);
/* draws an equaleral triangle by starting at the top with a 
   width of 1 and increasing the width by 1
   for every row */

void draw_moving_shapes(int height, int width, int row, int col, u_int blue, u_int green, u_int red);

void moving_rectangle(int height, int width, int row, int col, u_int blue, u_int green, u_int red);

void draw_triangle(void);
/* draws a circle using bresenham's algorithm */
void draw_circle(void);

#endif // _DRAW_SHAPES_H_
