#ifndef LEG
#define LEG

#include <GL/glut.h>
#include "point.h"

class Leg{
    private:
        Point a, b, c;
        GLfloat angleA, angleB, sizeA, sizeB;
        GLboolean leftLeg, invertAnim;

    public:
        Leg();
        Leg(Point a, GLfloat angleA, GLfloat angleB, GLfloat sizeA,
            GLfloat sizeB, GLboolean leftLeg, GLboolean invertAnim);
        void update(GLfloat delta_ms);
        void draw();
};

#endif
