#include<bits/stdc++.h>
using namespace std;

// Quick Hull Algorithm

#define iPair pair<int, int>
set<iPair> hull;

int findSide(iPair p1, iPair p2, iPair p) {
	int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

int lineDist(iPair p1, iPair p2, iPair p) {return abs ((p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first));}

void quickHull(iPair a[], int n, iPair p1, iPair p2, int side)  {
	int ind = -1;
	int max_dist = 0;

	for (int i=0; i<n; i++) {
		int temp = lineDist(p1, p2, a[i]);
		if (findSide(p1, p2, a[i]) == side && temp > max_dist) {
			ind = i;
			max_dist = temp;
		}
	}

	if (ind == -1) {
		hull.insert(p1);
		hull.insert(p2);
		return;
	}

	quickHull(a, n, a[ind], p1, - findSide(a[ind], p1, p2));
	quickHull(a, n, a[ind], p2, - findSide(a[ind], p2, p1));
}

void printHull(iPair a[], int n) {

	if (n < 3) {
		cout << "Convex hull not possible\n";
		return;
	}


	int min_x = 0, max_x = 0;
	for (int i=1; i<n; i++) {
		if (a[i].first < a[min_x].first) min_x = i;
		if (a[i].first > a[max_x].first) max_x = i;
	}

	quickHull(a, n, a[min_x], a[max_x], 1);
	quickHull(a, n, a[min_x], a[max_x], -1);
	cout << "The points in Convex Hull are:\n";

	while (!hull.empty()) {
		cout << "(" <<( *hull.begin()).first << ", " << (*hull.begin()).second << ") ";
		hull.erase(hull.begin());
	}
}


// Graham Scan Algorithm

struct Point {
	int x, y;
};

Point p0;

Point nextToTop(stack<Point> &S) {
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

void swap(Point &p1, Point &p2) {
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

int distSq(Point p1, Point p2){return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);}

int orientation(Point p, Point q, Point r) {
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2) {
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;

	int o = orientation(p0, *p1, *p2);
	if (o == 0) return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
	return (o == 2) ? -1 : 1;
}

void convexHull(Point points[], int n) {
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < n; i++) {
		int y = points[i].y;
		if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) ymin = points[i].y, min = i;
	}

	swap(points[0], points[min]);
	p0 = points[0];
	qsort(&points[1], n - 1, sizeof(Point), compare);

	int m = 1;
	for (int i = 1; i < n; i++) {
		while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0) i++;
		points[m] = points[i];
		m++;
	}

	if (m < 3) return;

	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	for (int i = 3; i < m; i++) {
		while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop();
		S.push(points[i]);
	}

	while (!S.empty()) {
		Point p = S.top();
		cout << "(" << p.x << ", " << p.y << ") ";
		S.pop();
	}
}


int main()
{
    
	//srand(time(0));
    int x, y, N;
    cout << "Enter numbers of data point to create: "; 
	cin >> N;
    iPair a[N];
	Point points[N];
    
	for(int i = 0; i < N; i++) {
		x = rand();
		y = rand();
		a[i] = {x, y};
		points[i] = {x, y};
	}
	cout << N << " Points Created." << endl << endl;

    //ios_base::sync_with_stdio(false);

    auto quickHullStart = chrono::high_resolution_clock::now();
	cout << "Convex Hull points using QuickHull Algorithm are: " << endl;
	printHull(a, N);
    auto quickHullEnd = chrono::high_resolution_clock::now();
    long double quickHullTime = chrono::duration_cast<chrono::milliseconds>(quickHullEnd - quickHullStart).count();
    cout << endl << "Time taken by Quick Hull program is: " << quickHullTime << " milliseconds." << endl << endl;

    auto grahamScanStart = chrono::high_resolution_clock::now();
	cout << "Convex Hull points using Graham Scan Algorithm are: " << endl;
	convexHull(points, N);
    auto grahamScanEnd = chrono::high_resolution_clock::now();
    long double grahamScanTime = chrono::duration_cast<chrono::milliseconds>(grahamScanEnd - grahamScanStart).count();
    cout << endl << "Time taken by Quick Hull program is: " << grahamScanTime << " milliseconds." << endl << endl;
	cout << endl;

	return 0;
}
