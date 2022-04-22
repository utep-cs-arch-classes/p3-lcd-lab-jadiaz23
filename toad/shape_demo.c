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
  //0, 0, 7 is brown for the other block we gotta do next
  //0, 63, 127 is a nice yellow

  draw_rectangle(20, 82, 44, 64, 0, 0, 0);
  draw_rectangle(30, 70, 39, 64, 15, 50, 255); //15, 50, 255  shitty orange mess with it later
  draw_rectangle(10, 50, 69, 64, 15, 50, 255);
  draw_rectangle(5, 5, 64, 31, 0, 0, 0);//left tiny black square
  draw_rectangle(5, 5, 69, 36, 0, 0, 0);//2nd tiny black square
  draw_rectangle(5, 10, 74, 44, 0, 0, 0);// tinyish rectangle black
  draw_rectangle(5, 30, 79, 64, 0, 0, 0); //middle black line
  draw_rectangle(5, 10, 74, 84, 0, 0, 0); //right rectangle black
  draw_rectangle(5, 5, 69, 91, 0, 0, 0); //2nd tiny black square right
  draw_rectangle(5, 5, 64, 96, 0, 0, 0); //right tiny black square
  draw_rectangle(10, 15, 34, 36, 0, 0, 0); //left leaf part black *********
  draw_rectangle(5, 5, 39, 46, 0, 0, 0); //tiny leaf part square           *left pedal
  draw_rectangle(5, 10, 39, 39, 15, 50, 255); //orange left leaf           *
  draw_rectangle(5, 5, 34, 36, 15, 50, 255); //tiny orange square          *
  draw_rectangle(5, 5, 29, 36, 0, 0, 0); //tiny black square on top*********
  draw_rectangle(10, 31, 34, 64, 0, 0, 0); // middle black ****************
  draw_rectangle(5, 30, 39, 65, 15, 50, 255); //middle orange             *
  draw_rectangle(10, 20, 29, 65, 15, 50, 255); //other middle orange      *
  draw_rectangle(5, 20, 29, 65, 0, 0, 0); //other middle black            *middle pedal
  draw_rectangle(5, 9, 29, 65, 15, 50, 255); //other other middle orange  *
  draw_rectangle(5, 9, 24, 65, 0, 0, 0); //top middle black ***************
  draw_rectangle(5, 18, 39, 90, 0, 0, 0); //middle black *************
  draw_rectangle(10, 8, 34, 90, 15, 50, 255); //middle other orange  *right pedal
  draw_rectangle(5, 8, 34, 90, 0, 0, 0); //other middle black        *
  draw_rectangle(4, 4, 30, 90, 0, 0, 0); //black *********************
  draw_rectangle(20, 35, 84, 72, 0, 0, 0); //black part in leaf
  draw_rectangle(15, 65, 89, 62, 0, 0, 0); //2nd black part in leaf
  draw_rectangle(10, 75, 94, 62, 0, 0, 0); //3rd black part in leaf
  draw_rectangle(10, 25, 94, 43, 0, 110, 0); //dark green part left
  draw_rectangle(10, 25, 94, 82, 0, 110, 0); //dark green part right
  draw_rectangle(15, 5, 84, 62, 0, 127, 0); //light green part mid
  draw_rectangle(5, 20, 94, 41, 0, 127, 0); //light green part left
  draw_rectangle(5, 20, 94, 80, 0, 127, 0); //light green part right
  draw_rectangle(5, 10, 89, 41, 0, 127, 0); //top light green part left
  draw_rectangle(5, 10, 89, 80, 0, 127, 0); //top light green part right
  draw_rectangle(10, 5, 84, 67, 0, 110, 0); //dark green mid
  draw_rectangle(5, 5, 54, 42, 0, 0, 0); //left tiny square*************
  draw_rectangle(5, 10, 50, 50, 0, 0, 0); //top part ******************>left eye
  draw_rectangle(5, 5, 54, 57, 0, 0, 0); //right tiny square ***********
  draw_rectangle(5, 5, 54, 67, 0, 0, 0); //right tiny square ******
  draw_rectangle(5, 10, 50, 75, 0, 0, 0); //top part **************> right eye
  draw_rectangle(5, 5, 54, 82, 0, 0, 0); //right tiny square ******

  /* brown block
  draw_rectangle(70, 70, 35, 69, 0, 0, 15); //brownish color
  draw_rectangle(60, 5, 40, 31, 0, 0, 0); //left vertical black line       *
  draw_rectangle(5, 5, 35, 36, 0, 0, 0); //top left tiny black square
  draw_rectangle(5, 60, 30, 69, 0, 0, 0); //top horizontal black line
  draw_rectangle(5, 5, 100, 36, 0, 0, 0); //bottom left tiny black square   border
  draw_rectangle(5, 60, 105, 69, 0, 0, 0); //bottom horizontal black
  draw_rectangle(5, 5, 100, 101, 0, 0, 0); //bottom right tiny black square
  draw_rectangle(5, 5, 35, 101, 0, 0, 0); //top right tiny black square
  draw_rectangle(60, 5, 40, 106, 0, 0, 0); // right vertical black line    *
  draw_rectangle(5, 5, 35, 41, 255, 255, 255); //top white square
  draw_rectangle(5, 5, 40, 36, 255, 255, 255); //2nd white square
  draw_rectangle(5, 10, 35, 49, 0, 255, 255); //top horizontal yellow line
  draw_rectangle(5, 5, 40, 41, 0, 255, 255); //tiny yellow square top
  draw_rectangle(10, 5, 45, 36, 0, 255, 255); //vertical yellow line
  draw_rectangle(5, 5, 60, 36, 0, 255, 255); //tiny yellow square bot
  draw_rectangle(5, 5, 60, 46, 0, 0, 0); //tiny black square left eye top*
  draw_rectangle(5, 5, 65, 51, 0, 0, 0); //tiny black square left 2nd top*> left eye
  draw_rectangle(5, 5, 70, 56, 0, 0, 0); //tiny black square left 3rd    *
  draw_rectangle(5, 5, 70, 72, 0, 0, 0); //tiny black square right 3rd *
  draw_rectangle(5, 5, 65, 77, 0, 0, 0); //tiny black square right 2nd * >right eye
  draw_rectangle(5, 5, 60, 82, 0, 0, 0); //tiny black square right top *
  draw_rectangle(5, 60, 100, 69, 0, 0, 0); //bottom horizontal black line
  draw_rectangle(5, 5, 95, 36, 0, 0, 0); // bottom left tiny black square
  draw_rectangle(60, 5, 40, 101, 0, 0, 0); // right vertical line 
  draw_rectangle(5, 5, 95, 96, 0, 0, 0); //bottom right tiny black square
  draw_rectangle(5, 5, 35, 96, 0, 0, 0); //top right tiny black square
  */

  /*  block
  draw_rectangle(70, 70, 35, 69, 0, 20, 20); //outer brown
  draw_rectangle(60, 60, 35, 64, 0, 105, 191);//second outer brown big square for now
  draw_rectangle(5, 55, 95, 66, 0, 105, 191); //second outer brown horizontal bottom line
  draw_rectangle(55, 5, 40, 96, 0, 105, 191); //second outer brown vertical right line
  draw_rectangle(50, 50, 40, 64, 15, 255, 255); //skin like color?
  draw_rectangle(5, 45, 90, 66, 15, 255, 255); //skin like bottom horizontal line
  draw_rectangle(45, 5, 45, 91, 15, 255, 255); //skin like right vertical line
  draw_rectangle(5, 15, 35, 46, 255, 255, 255); //top left white horizontal line
  draw_rectangle(5, 10, 40, 38, 255, 255, 255); //left white horizontal line again
  draw_rectangle(15, 5, 40, 36, 255, 255, 255); //left white vertical line
  draw_rectangle(5, 5, 60, 36, 255, 255, 255); ///tiny white square
  draw_rectangle(20, 45, 45, 66, 255, 255, 255); //white block but its purple 4now
  draw_rectangle(10, 25, 65, 71, 255, 255, 255); //mid white block 4now purple
  draw_rectangle(10, 15, 80, 66, 255, 255, 255); //bottom white block 4now purple
  draw_rectangle(60, 5, 40, 31, 0, 0, 0); //left vertical black line       *
  draw_rectangle(5, 5, 35, 36, 0, 0, 0); //top left tiny black square      *
  draw_rectangle(5, 60, 30, 69, 0, 0, 0); //top horizontal black line      *
  draw_rectangle(5, 5, 100, 36, 0, 0, 0); //bottom left tiny black square  > border
  draw_rectangle(5, 60, 105, 69, 0, 0, 0); //bottom horizontal black       *
  draw_rectangle(5, 5, 100, 101, 0, 0, 0); //bottom right tiny black square*
  draw_rectangle(5, 5, 35, 101, 0, 0, 0); //top right tiny black square    *
  draw_rectangle(60, 5, 40, 106, 0, 0, 0); // right vertical black line    *
  draw_rectangle(10, 5, 50, 41, 0, 0, 0); //top left vertical black line question mark
  draw_rectangle(5, 5, 45, 46, 0, 0, 0); //tiny top left black square
  draw_rectangle(5, 30, 60, 59, 0, 0, 0); //horizontal mid black line
  draw_rectangle(5, 15, 55, 66, 0, 0, 0); //2nd mid horizontal black line
  draw_rectangle(5, 35, 40, 66, 0, 0, 0); //2nd top horizontal black line
  draw_rectangle(5, 5, 45, 86, 0, 0, 0); //tiny top right black square
  draw_rectangle(15, 5, 50, 91, 0, 0, 0); //right vertical black line
  draw_rectangle(10, 5, 65, 56, 0, 0, 0);//left vertical black line
  draw_rectangle(5, 5, 65, 86, 0, 0, 0); //tiny bottom right black square
  draw_rectangle(5, 10, 70, 79, 0, 0, 0); //horizontal right black line
  draw_rectangle(5, 15, 75, 66, 0, 0, 0); //horizontal mid black line 
  draw_rectangle(10, 5, 80, 56, 0, 0, 0); //bottom vertical black line left
  draw_rectangle(10, 5, 80, 76, 0, 0, 0); //bottom vertical black line right
  draw_rectangle(5, 15, 90, 66, 0, 0, 0); //bottom vertical black line
  */
  
  /* Mushroom
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
  */
  
  //  draw_triangle();
  //  draw_circle();
  or_sr(0x10);	/**< CPU OFF */
}
