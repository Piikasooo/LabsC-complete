#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Point2D{
public:
    Point2D(double x, double y) {this->x = x; this->y = y;}
    string toString() {
        ostringstream s;
        s << x << " " << y;
        return s.str();
    }
    double X() { return x; }
    double Y() { return y; }
private:
    double x;
    double y;
};

class Line2D{
public:
    Line2D(double slope, double y_intercept) {this->slope = slope; this->y_intercept = y_intercept;}
    Line2D(Point2D pointA, Point2D pointB) {
        this->slope = (pointB.Y() - pointA.Y()) / (pointB.X() - pointA.X());
        this->y_intercept = (pointB.X() * pointA.Y() - pointA.X() * pointB.Y()) / (pointB.X() - pointA.X());
    }
    string toString() {
        ostringstream s;
        s << "y = " << slope<<"x";
        if(y_intercept < 0)
            s << " - " << (-y_intercept);
        else
            s << " + " << y_intercept;
        return s.str();
    }
private:
    double slope;
    double y_intercept;
};



int main()
{
    double x1,y1,x2,y2;
    cout << "Enter coordinats point A: ";
    cin >> x1 >> y1;
    cout << "Enter coordinats point B: ";
    cin >> x2 >> y2;

    Line2D line(Point2D(x1,y1),Point2D(x2,y2));
    cout << line.toString();
    return 0;
}
