#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

class Point2D{
    public:
        Point2D(double x, double y);
        string toString();
        double distanceTo(Point2D that);
    private:
        double x;
        double y;
};

Point2D::Point2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

string Point2D::toString()
{
    stringstream sstm;
    sstm << "x: " << this->x << ", y: " << this->y;
    return sstm.str();
}

double Point2D::distanceTo(Point2D point)
{
    return sqrt((this->x - point.x) * (this->x - point.x) + (this->y - point.y) * (this->y - point.y));
}

int main()
{
    double x, y;
    cout << "Enter (x, y) for first point:" << endl;
    cin >> x >> y;
    Point2D p1(x, y);

    cout << "Enter (x, y) for second point:" << endl;
    cin >> x >> y;
    Point2D p2(x, y);

    cout << "Output" << endl << p1.distanceTo(p2) << endl;
    return 0;
}
