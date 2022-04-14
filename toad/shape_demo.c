#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  configureClocks();
  lcd_init();

  // clear the screen in case something is already on there
  clearScreen(COLOR_BLUE);
  //height, width, row, col, blue, green, red
  draw_rectangle(15, 41, 45, 64 , 0, 0, 255);//top red part
   draw_rectangle(30, 60, 55, screenWidth/2, 0, 0, 255);//middle red part
  draw_rectangle(20, 5, 65, 31, 0, 0, 0); //left side black
  draw_rectangle(5, 44, 80, 63, 0, 0, 0 ); //middle black
  draw_rectangle(20, 4, 65, 96, 0, 0, 0); //right side black
  draw_rectangle(18, 42, 85, 64, 153, 180, 251); //for now skin
  draw_rectangle(5, 15, 85, 40, 0, 0, 0); //horizontal line next to left eye
  draw_rectangle(5, 15, 85, 86, 0, 0, 0); //horizontal line next to right eye
  draw_rectangle(8, 5, 90, 40, 0, 0, 0); //vertical line next to left eye
  draw_rectangle(8, 5, 90, 87, 0, 0, 0); //vertical line next to right eye
  draw_rectangle(5, 5, 98, 45, 0, 0, 0);// bottom left tiny square
  draw_rectangle(5, 5, 98, 82, 0, 0, 0); //bottom right tiny square
  draw_rectangle(5, 33, 103, 63, 0, 0, 0);//bottom horizontal line
  draw_rectangle(9, 5, 84, 55, 0, 0, 0); //left eye
  draw_rectangle(9, 5, 84, 70, 0, 0, 0); //right eye
  draw_rectangle(10, 5, 55, 36, 0, 0, 0); //top left vertical black line
  draw_rectangle(10, 4, 55, 92, 0, 0, 0); //top right vertical black line
  draw_rectangle(5, 5, 50, 41, 0, 0, 0); //top left tiny square
  draw_rectangle(5, 5, 50, 87, 0, 0, 0); //top right tiny square
  draw_rectangle(5, 10, 45, 49, 0, 0, 0);//top left horizontal line
  draw_rectangle(5, 10, 45, 80, 0, 0, 0);//top right horizontal line
  draw_rectangle(5, 22, 40, 64, 0, 0, 0);//top horizontal black line
  draw_rectangle(15, 30, 60, screenWidth/2, 255, 255, 255);//horizontal middle white line
  draw_rectangle(25, 20, 55, screenWidth/2, 255, 255, 255);//vertical middle white line
  draw_rectangle(10, 3, 70, 35, 255, 255, 255);//bottom left white line
  draw_rectangle(10, 3, 70, 92, 255, 255, 255);//bottom right white line
  draw_rectangle(10, 5, 55, 41, 255, 255, 255);//left vertical white line
  draw_rectangle(10, 4, 50, 46, 255, 255, 255);//2nd left vertical white line
  draw_rectangle(10, 5, 55, 87, 255, 255, 255);//right vertical white line
  draw_rectangle(10, 4, 50, 83, 255, 255, 255);//2nd right vertical white line
  draw_rectangle(5, 6, 50, 78, 255, 255, 255);//tiny white square on the right side

  //  draw_triangle();
  //  draw_circle();
  or_sr(0x10);	/**< CPU OFF */
}
