#include "spider.h"

Spider::Spider(){}

Spider::Spider(Point pos){
    Point tmp, tmp2;

    this->pos = pos;
    this->center = pos;
    this->destiny = pos;

    tmp = Point(pos.getX(), pos.getY() + BODY_SIZE1 + BODY_SIZE2);
    body1 = Circle(pos, BODY_SIZE1);
    body2 = Circle(tmp, BODY_SIZE2);

    tmp = Point(pos.getX() + BODY_SIZE1, pos.getY());

    tmp2 = tmp;
    tmp2.rotate(pos, (180-EXT_LEG_ANGLE)*2*PI/360);
    ext_leg_l = Leg(tmp2, EXT_LEG_ANGLE, EXT_KNEE_ANGLE, EXT_LEG_SIZE1, EXT_LEG_SIZE2, true, false);

    tmp2 = tmp;
    tmp2.rotate(pos, EXT_LEG_ANGLE*2*PI/360);
    ext_leg_r = Leg(tmp2, EXT_LEG_ANGLE, EXT_KNEE_ANGLE, EXT_LEG_SIZE1, EXT_LEG_SIZE2, false, false);

    tmp2 = tmp;
    tmp2.rotate(pos, (180-INT_LEG_ANGLE1)*2*PI/360);
    int_leg_l1 = Leg(tmp2, INT_LEG_ANGLE1, INT_KNEE_ANGLE, INT_LEG_SIZE1, INT_LEG_SIZE2, true, false);

    tmp2 = tmp;
    tmp2.rotate(pos, INT_LEG_ANGLE1*2*PI/360);
    int_leg_r1 = Leg(tmp2, INT_LEG_ANGLE1, INT_KNEE_ANGLE, INT_LEG_SIZE1, INT_LEG_SIZE2, false, false);

    tmp2 = tmp;
    tmp2.rotate(pos, (180-INT_LEG_ANGLE2)*2*PI/360);
    int_leg_l2 = Leg(tmp2, INT_LEG_ANGLE2, INT_KNEE_ANGLE, INT_LEG_SIZE1, INT_LEG_SIZE2, true, false);

    tmp2 = tmp;
    tmp2.rotate(pos, INT_LEG_ANGLE2*2*PI/360);
    int_leg_r2 = Leg(tmp2, INT_LEG_ANGLE2, INT_KNEE_ANGLE, INT_LEG_SIZE1, INT_LEG_SIZE2, false, false);

    tmp2 = tmp;
    tmp2.rotate(pos, (180-INT_LEG_ANGLE3)*2*PI/360);
    int_leg_l3 = Leg(tmp2, INT_LEG_ANGLE3, INT_KNEE_ANGLE, INT_LEG_SIZE1, INT_LEG_SIZE2, true, false);

    tmp2 = tmp;
    tmp2.rotate(pos, INT_LEG_ANGLE3*2*PI/360);
    int_leg_r3 = Leg(tmp2, INT_LEG_ANGLE3, INT_KNEE_ANGLE, INT_LEG_SIZE1, INT_LEG_SIZE2, false, false);
}

void Spider::walkTo(Point destiny){
    this->destiny = destiny;
}

void Spider::update(GLfloat delta_temp){
    if(pos.getX() != destiny.getX() || pos.getY() != destiny.getY()){
        //walk
        //update legs
    }
}

void Spider::draw(){
    glPushMatrix();

    glTranslated(center.getX(), center.getY(), 0);
    glRotated(rot, 0.0, 0.0, -1.0);
    glScaled(sx, sy, 1);
    glTranslated(-center.getX() + tx, -center.getY() + ty, 0);

    body1.draw();
    body2.draw();
    ext_leg_r.draw();
    ext_leg_l.draw();
    int_leg_r1.draw();
    int_leg_l1.draw();
    int_leg_r2.draw();
    int_leg_l2.draw();
    int_leg_r3.draw();
    int_leg_l3.draw();

    glPopMatrix();
}
