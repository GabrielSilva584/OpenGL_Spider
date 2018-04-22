#include "leg.h"

Leg::Leg(){}

Leg::Leg(Point a, GLfloat angleA, GLfloat angleB, GLfloat sizeA,
    GLfloat sizeB, GLboolean leftLeg, GLboolean invertAnim) :
        a(a), angleA(angleA), angleB(angleB),
        leftLeg(leftLeg), invertAnim(invertAnim)
{
    if(leftLeg == true){
        this->angleA = 180 - angleA;
        this->angleB = - angleB;
    }

    b = c = a;
    b.setX(b.getX() + sizeA);
    c.setX(c.getX() + sizeA + sizeB);
}

void Leg::update(GLfloat delta_ms){
    //Good luck, i think cos/sin is a good idea for the anim loop

}

void Leg::draw(){
    glPushMatrix();

    //Prepara para desenhar a primeira divisão da perna
    glTranslated(a.getX(), a.getY(), 0);
    glRotated(angleA, 0.0, 0.0, -1.0);
    glTranslated(-a.getX(), -a.getY(), 0);

    //Desenha a primeira divisão da perna
    glBegin(GL_LINES);
        glVertex2i(a.getX(), a.getY());
        glVertex2i(b.getX(), b.getY());
    glEnd();

    //Prepara para desenhar a segunda divisão da perna
    glTranslated(b.getX(), b.getY(), 0);
    glRotated(angleB, 0.0, 0.0, -1.0);
    glTranslated(-b.getX(), -b.getY(), 0);

    //Desenha a segunda divisão da perna
    glBegin(GL_LINES);
        glVertex2i(b.getX(), b.getY());
        glVertex2i(c.getX(), c.getY());
    glEnd();

    glPopMatrix();
}
