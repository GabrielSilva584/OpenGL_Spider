#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "point.h"


Point::Point() : X(0), Y(0){}

Point::Point(GLfloat x, GLfloat y) : X(x), Y(y){}

void Point::translate(GLfloat delX, GLfloat delY){
    X += delX;
    Y += delY;
}

void Point::rotate(Point O, GLfloat deg){
    this->translate(-O.getX(), -O.getY());

    GLfloat Xold = X;
    GLfloat Yold = Y;

    X = Xold*cos(PI*deg/180) + Yold*sin(PI*deg/180);
    Y = - Xold*sin(PI*deg/180) + Yold*cos(PI*deg/180);

    this->translate(O.getX(),O.getY());
}

void Point::setX(GLfloat x){
    X = x;
}

void Point::setY(GLfloat y){
    Y = y;
}

GLfloat Point::getX(){
    return X;
}

GLfloat Point::getY(){
    return Y;
}
