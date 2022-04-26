#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"


void
draw_moving_shapes(int height, int width, int row, int col, u_int blue, u_int green, u_int red)
{
  row+=55;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int color = (blue << 11) | (green << 5) | red;
  
  // blank out the old rectangle
  fillRectangle(left_col, top_row, width, height, color);
  moving_rectangle(height, width, row, col, blue, green, red);
}
  
void //int height, int width, int row, int col, u_int blue, u_int green, u_int red
draw_rectangle(int height, int width, int row, int col, u_int blue, u_int green, u_int red)
{
  // int height = 37;
  // int width  = 60;
  // int row = 50
  // int col = screenWidth / 2; //row is up or down, col is left or right
  row+=49;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  // u_int blue = 0, green = 0, red = 255;
  u_int color = (blue << 11) | (green << 5) | red;

  fillRectangle(left_col, row, width, height, color);
}

void
moving_rectangle(int height, int width, int row, int col, u_int blue, u_int green, u_int red)
{
  static int x_vel = 10; //it was 10
  static int y_vel = 5; //it was 5

  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  // unsigned int blue = 16, green = 0, red = 31;
  unsigned int color = (blue << 11) | (green << 5) | red;

  // draw rectangle at current position
  fillRectangle(left_col, top_row, width, height, color);

  // save current position
  // to_draw->old_rect_row = to_draw->rect_row;
  // to_draw->old_rect_col = to_draw->rect_col;

  // update position
  row += y_vel;
  col += x_vel;

  if ( (row + height / 2) >= screenHeight ||   // bottom
       (row - height / 2) <= 0) {              // top
    // top or bottom hit, reverse y velocity
    y_vel = y_vel * -1;
  }
  
}

void
draw_triangle(void)
{
  int height = 40;
  int row = 80, col = screenWidth / 2;

  int step = 0;

  int blue = 31, green = 0, red = 31;

  u_int color = (blue << 11) | (green << 5) | red;

  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < height; step++) {
    // left side of triangle
    u_char start_col = col - (step / 2);
    // right side of triangle
    u_char end_col   = col + (step / 2);
    u_char width     = end_col - start_col;
    fillRectangle(col - (step / 2), row+step, width, 1, color);
  }
}


void
drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR)
{
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void
drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color)
{
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void
draw_circle(void)
{
  int x_coord = screenWidth / 2;
  int y_coord = 60;
  int r = 20;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  u_int color = COLOR_SIENNA;

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
  

