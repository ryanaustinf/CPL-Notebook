#include <cmath>

/**
 * returns area of triangle with base b and height h.
 */
double area(double b, double h) {
	return b * h * 0.5;
}

/**
 * returns perimeter of triangle with sides a, b, and c.
 */
double perimeter(double a, double b, double c) {
	return a + b + c;
}

/**
 * returns semiperimeter of triangle with sides a, b, and c.
 */
double semiperimeter(double a, double b, double c) {
	return (a + b + c) / 2.0;
}

/**
 * returns area of triangle with sides a, b, and c.
 */
double area(double a, double b, double c) {
	double s = semiperimeter(a,b,c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

/**
 * returns radius of incircle of triangle with sides a, b, and c.
 */
double incircleradius(double a, double b, double c) {
	return area(a,b,c) / semiperimeter(a,b,c);
}

/**
 * returns radius of incircle of triangle with sides a, b, and c.
 */
double rInCircle(Point p1, Point p2, Point p3) {
	return incircleradius(p1.dist(p2),p2.dist(p3),p3.dist(p1));
}

// assumption: the required points/lines functions have been written
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(Point p1, Point p2, Point p3, Point &ctr, double &r) {
	r = rInCircle(p1, p2, p3);
	if (fabs(r) < 1e-10) 
		return 0; // no inCircle center
	double ratio = p1.dist(p2) / p1.dist(p3);
	Vector p2p3(p2, p3);
	Point p = p2p3.scale(ratio / (1 + ratio)).translate(p2);
	Line l1(p1,p);
	ratio = p2.dist(p1) / p2.dist(p3);
	Vector p1p3(p2, p3);
	p = p1p3.scale(ratio / (1 + ratio)).translate(p1);
	Line l2(p2, p);
	l1.areIntersect(l2, ctr); // get their intersection point
	return 1; 
}

/**
 * returns radius of circumcircle of triangle with sides a, b, and c.
 */
double circumcircleradius(double a, double b, double c) {
	return a * b * c / 4 * area(a,b,c);
}

/**
 * returns radius of incircle of triangle with sides a, b, and c.
 */
double rCircumCircle(Point p1, Point p2, Point p3) {
	return circumcircleradius(p1.dist(p2),p2.dist(p3),p3.dist(p1));
}