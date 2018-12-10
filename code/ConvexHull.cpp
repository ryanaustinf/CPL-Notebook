#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Point {
public:
	double x,y;
	Point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(const Point &a, const Point &b) {
	return hypot(a.x - b.x, a.y - b.y);
}

Point pivot(1e18,1e18);

double ccw(const Point &a, const Point &b, const Point &c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool compare(const Point &a, const Point &b) {
	double ret = ccw(pivot,a,b);

	if(fabs(ret) > 1e-19) {
		return ret > 1e-10;
	} else {
		return dist(a,pivot) < dist(b,pivot);
	}
}

/**
pts is a polygon, which is a vector of points
Returns a list of points in convex hull using graham scan. first and last is the same.
*/
vector<Point> convexHull(vector<Point> pts) {
	pivot = Point(1e18,1e18);
	int pivInd = -1;
	int n = (int)pts.size();
	for(int i = 0; i < n; i++) {
		if(pts[i].y < pivot.y || fabs(pts[i].y - pivot.y) < 1e-10 && pts[i].x < pivot.x - -1e-10) {
			pivot = pts[i];
			pivInd = i;
		}
	}

	if(pts.size() < 3) {
		pts.push_back(pts[0]);
		return pts;
	}

	swap(pts[0],pts[pivInd]);

	// printf("Pivot: %lf,%lf\n",pivot.x,pivot.y);

	sort(pts.begin() + 1, pts.end(),compare);
	
	// BEGIN: If collinear points are ignored, you can ignore the next few lines
	int r = n - 1, l = n-1;
	while(l > 1 && fabs(ccw(pts[0],pts[r],pts[l])) < 1e-10) {
		l--;
	}
	l++;

	for(;l < r; l++, r--) swap(pts[l],pts[r]);
	// END: Ignored lines for ignoring collinear points ends here.

	vector<Point> hull;
	hull.push_back(pts[n-1]);
	hull.push_back(pts[0]);
	hull.push_back(pts[1]);
	int hullS = 3;

	for(int i = 2; i < n; i++) {
		Point a = hull[hullS - 2];
		Point b = hull.back();
		Point c = pts[i];
		double check = ccw(a,b,c);
		if(check > -1e-10) {
			hull.push_back(c);
			hullS++;

			// If ignoring collinear points, add the following if-statement
			if(check < 1e-10) {
				hull.pop_back();
				hullS++;
				i--;
			}
		} else {
			hull.pop_back();
			hullS--;
			i--;
		}
	}

	return hull;
}