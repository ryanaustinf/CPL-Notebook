#include <cmath>

class Point{
	public:
	double x, y;
	Point() { x = y = 0; }
	Point(double _x, double _y) : x(_x), y(_y) {}

	bool operator<(const Point &p) const {
		if(fabs(x - p.x) > 1e-10) {
			return x < p.x;
		} else {
			return y < p.y;
		}
	}

	bool operator==(const Point &p) const {
		return (fabs(x - p.x) < 1e-10 && fabs(y - p.y) < 1e-10);
	}

	/**
	 * theta in radians
	 */
	Point rotate(double theta) {
		return Point(cos(theta) * x - sin(theta) * y,
						sin(theta) * x + cos(theta) * y);
	}

	double dist(const Point &p) const {
		return hypot(x - p.x, y - p.y);
	}
};

class Line{
	public:
	double a, b, c;

	Line(Point from, Point to) {
		if(fabs(from.x - to.x) < 1e-10) {
			a = 1;
			b = 0;
			c = -from.x;
		} else {
			a = (to.y - from.y) / (to.x - from.x);
			b = 1;
			c = -(a * from.x) - from.y;
		}
	}

	bool areParallel(const Line &l2) const {
		return (fabs(a - l2.a) < 1e-10 && fabs(b - l2.b) < 1e-10);
	}

	bool areSame(const Line &l2) const {
		return areParallel(l2) && fabs(c - l2.c) < 1e-10;
	}

	bool areIntersect(const Line &l2, Point &p) {
		if(areParallel(l2)) {
			return false;
		}
		p.x = (l2.b * c - b * l2.c) / (l2.a * b - a * l2.b);
		if(fabs(b) > 1e-10) {
			p.y = -(a * p.x + c);
		} else {
			p.y = -(l2.a * p.x + l2.c);
		}
		return true;
	}
};

class Vector {
	public:
	double x, y;

	Vector(double _x, double _y) : x(_x), y(_y) {}
	Vector(Point src, Point dest) {
		x = dest.x - src.x;
		y = dest.y - src.y;
	}
	Vector scale(double c) {
		return Vector(x * c,y * c);
	}
	Point translate(Point p) {
		return Point(p.x + x,p.y + y);
	}

	double dot(const Vector &b) const {
		return x * b.x + y * b.y;
	}

	double norm() const {
		return x * x + y * y;
	}
};

/**
 * distance of point p from line AB
 */
double distToLine(Point p, Point a, Point b, Point &c) {
	Vector ap = Vector(a,p), ab = Vector(a,b);
	double u = ap.dot(ab) / ab.norm();
	ab.scale(u).translate(a);
	return p.dist(c);
}