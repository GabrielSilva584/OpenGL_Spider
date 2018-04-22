#ifndef POINT
#define POINT

class Point{
    private:
        //Coordenadas
        GLfloat X, Y;

    public:
        //Construtores
        Point();
        Point(GLfloat x, GLfloat y);

        //Transformações úteis
        void translate(GLfloat delX, GLfloat delY);
        void rotate(Point O, GLfloat rad);

        //Sets e Gets úteis
        void setX(GLfloat x);
        void setY(GLfloat y);
        GLfloat getX();
        GLfloat getY();
};

#endif
