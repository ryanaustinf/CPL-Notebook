#include <cmath>

/**
 * Checks if p is in circle with center c and radius r.
 * Returns 0 if inside, 1 if on border, and 2 if outside.
 */
int insideCircle(Point p, Point c, double r) {
	double dx = p.x - c.x, dy = p.y - c.y;
	double dist = hypot(dx,dy);
	return dist < r - 1e-10 ? 0 : (dist < r + 1e-10 ? 1 : 2);
}

double getPI() {
	return acos(-1.0);
}

/**
 * returns area of circle with radius r
 */
double circleArea(double r) {
	return getPI() * r * r;
}

/**
 * returns arc length of circle with radius r and vertex angle theta (in radians)
 */
double arcLength(double r, double theta) {
	return theta * r;
}

/**
 * returns chord length of circle with radius r and vertex angle theta (in radians)
 */
double chordLength(double r, double theta) {
	return sqrt(2 * r * r * (1 - cos(theta)));
}

/**
 * returns area of sector of circle with radius r and vertex angle theta (in radians)
 */
double sectorArea(double r, double theta) {
	return r * r * theta / 2;
}

/**
 * returns area of segment of circle with radius r and vertex angle theta (in radians)
 * segment is section between chord and arc
 */
double segmentArea(double r, double theta) {
	return sectorArea(r,theta) - r * cos(theta / 2.0) * r * sin(theta / 2.0);
}

/**
 * given two points p1 and p2, find the center of circles, c, with radius r.
 */
bool circle2PtsRad(Point p1, Point p2, double r, Point &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true; 
}

