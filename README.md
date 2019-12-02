# C++ Project - *DriftIllusion*

## Overview:

The program works to create a illusional image by implementing c++ and OpenGL framework.

## Purpose:

The program was created for Computer Graph course.

## Process:
1. sets background color by using glClearColor().
2. starts drawing a rectangular by using glVertex3fv(x, y, z).
3. Uses the drawn rectangular to create three copies of the rectangular, which are filled with blue, white and black. The blue one will place at the center. The white and black ones scale their heights and translate their positions to left/right by using glTranslated().
4. repeats step 3 by using glRotated() to constructs a ring of compounded rectangulars
5. integrates step 4 with using glTranslated() to merge 4x2 rings to the final image.

## Image Display:

The illusion occurs rings rotating as counterclockwise or clockwise when viewers are staring at one of rings.

<img src='https://github.com/lxy878/Illusion_Image/blob/master/image_demo.png' width="450" height="225" title='Video Walkthrough' width='' alt='Video Walkthrough' />
