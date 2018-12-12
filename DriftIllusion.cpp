//
//  main.cpp
//  Project2
//
//  Created by Xiaoyi Liu on 10/21/18.
//  Copyright © 2018 Xiaoyi Liu. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include <stdlib.h>
using namespace std;

GLfloat rectangles[4][3]={{4,2,0},{4,18,0},{-4,18,0},{-4,2,0}};
GLfloat rectanglesL[4][3]={{0,0,0},{0,20,0},{-6,20,0},{-6,0,0}};
GLfloat rectanglesR[4][3]={{6,0,0},{6,20,0},{0,20,0},{0,0,0}};
GLfloat colors[3][3]={{0,0,0},{1,1,1},{0.02,0.29,0.52}};

// flag for black and white switching
bool blackORwhite = true;

void drawRectangle(GLfloat rect[][3], GLfloat color[]){
    glBegin(GL_POLYGON);
    glColor3fv(color);
    for(int i=0; i<4; i++){
        glVertex3fv(rect[i]);
    }
    glEnd();
}
void drawRing(float x, float y){
    for(int r=0; r<360; r+=45){
        glPushMatrix();
        // move the ring to x and y;
        glTranslated(x, y, 0);
        glRotated(r, 0, 0, 1);
        glTranslated(0, 40, 0);
        drawRectangle(rectangles, colors[2]);
        if(blackORwhite==true){
            drawRectangle(rectanglesL, colors[0]);
            drawRectangle(rectanglesR, colors[1]);
        }else{
            drawRectangle(rectanglesL, colors[1]);
            drawRectangle(rectanglesR, colors[0]);
        }
        glPopMatrix();
    }
    // control colors of black and white for each ring.
    if(blackORwhite == true){
        blackORwhite = false;
    }else{
        blackORwhite = true;
    }
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    // radius = 40 by increment y + 20 as height of rectalges
    // distance is intergal between rectangles
    float radius = 60, distance = 40;
    float startX = 400-radius-distance, startY = 200-radius-distance;
    for(int row=0; row<2; row++){
        for(int col=0; col<4; col++){
            glPushMatrix();
            drawRing(startX, startY);
            startX = startX-2*(radius+distance);
            glPopMatrix();
        }
        startY = startY-2*(radius+distance);
        startX = 300;
        // keep opporse colors of black and white when starting a new line.
        if(blackORwhite == true){
            blackORwhite = false;
        }else{
            blackORwhite = true;
        }
    }
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Project2");
    glClearColor(0.51, 0.58, 0.04, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-400.0, 400.0, -200.0, 200.0, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
