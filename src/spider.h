#ifndef SPIDER
#define SPIDER

#include <GL/glut.h>
#include "point.h"
#include "circle.h"
#include "leg.h"

#define PI 3.14159265359

//Parâmetros do corpo e das pernas da aranha
#define BODY_SIZE1 10
#define BODY_SIZE2 15
#define EXT_LEG_SIZE1 75
#define EXT_LEG_SIZE2 50
#define INT_LEG_SIZE1 50
#define INT_LEG_SIZE2 75
#define EXT_LEG_ANGLE 70
#define INT_LEG_ANGLE1 30
#define INT_LEG_ANGLE2 10
#define INT_LEG_ANGLE3 -10
#define INT_KNEE_ANGLE -80
#define EXT_KNEE_ANGLE -40

class Spider : public DrawableObject{
    private:
        Point pos, center, destiny;
        Circle body1, body2;
        Leg ext_leg_r, ext_leg_l;
        Leg int_leg_r1, int_leg_l1;
        Leg int_leg_r2, int_leg_l2;
        Leg int_leg_r3, int_leg_l3;

    public:
        Spider();
        Spider(Point pos);
        void walkTo(Point destiny);
        void update(GLfloat delta_temp);
        void draw();
};

#endif
