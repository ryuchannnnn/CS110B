/*
Write a simple class named Circle, with three private variables: doubles named x, y and radius.  The center of the circle is denoted by coordinates (x,y), and the radius of the circle is denoted by radius.
*/

#ifndef Circle_h
#define Circle_h
class Circle
{
private:
    double x;
    double y;
    double radius;
    double pi = 3.14;
public:
    void setRadius(double);
    void setX(double);
    void setY(double);
    double getRadius() const;
    double getX() const;
    double getY() const;
    double getArea() const;
    bool containsPoint(double xValue, double yValue);
};
#endif
