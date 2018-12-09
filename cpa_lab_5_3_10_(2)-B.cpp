#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

class Point2D {
    public:
        Point2D();
        Point2D(double x, double y);
        double distanceTo(Point2D that);
        string toString();
        double getX();
        double getY();
    private:
        double x;
        double y;
};

double Point2D::getX() {
	return x;
}

double Point2D::getY() {
	return y;
}

Point2D::Point2D() {
	x = 0;
	y = 0;
}

Point2D::Point2D(double x1, double y1) {
	x = x1;
	y = y1;
}

double Point2D::distanceTo(Point2D t) {
	return sqrt(pow((this->x - t.x), 2) + pow((this->y - t.y), 2));
}

class Line2D {
    public:
        Line2D();
        Line2D(double slope, double y_intercept);
        Line2D(Point2D pointA, Point2D pointB);
        string toString();
        bool contains(Point2D point) {
            double ri = this->slope * point.getX() + this->y_intercept;
            if (point.getY() < ri+0.00001 && point.getY() > ri - 0.00001)
                return true;
            return false;
        }
    private:
        double slope;
        double y_intercept;
};

Line2D::Line2D() {
	slope = 1;
	y_intercept = 1;
}

Line2D::Line2D(double s, double y) {
	slope = s;
	y_intercept = y;
}

Line2D::Line2D(Point2D pointA, Point2D pointB) {
	Point2D b = pointA;
	Point2D a = pointB;
	y_intercept = -a.getX()*((b.getY() - a.getY()) / (b.getX() - a.getX())) + a.getY();
	slope = (b.getY() - a.getY()) / (b.getX() - a.getX());
}

string to_string(int value){
    stringstream ss;
    ss << value;
    return ss.str();
}

string	Line2D::toString() {
	return ("y = " + to_string(slope) + "x " + to_string(y_intercept));
}

int main()
{
	string coo;
	double x, y;
	getline(cin, coo);
	stringstream ss;
	ss << coo;
	ss >> x;
	ss >> y;
	Point2D p1(x, y);

	getline(cin, coo);
	stringstream q;
	q << coo;
	q >> x;
	q >> y;
	Point2D p2(x, y);
	Line2D l(p2, p1);
	cout.precision(2);

	getline(cin, coo);
	stringstream e;
	e << coo;
	e >> x;
	e >> y;
	Point2D p3(x, y);

	if (l.contains(p3))
		cout << "collinear" << endl;
	else
		cout << "not collinear" << endl;

	return 0;
}
