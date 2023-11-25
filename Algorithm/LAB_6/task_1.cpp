#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


struct Point {
    int x, y;
};
Point referencePoint,p1,p2;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

int distSq(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return dx * dx + dy * dy;
}

bool comparePoints(Point p1, Point p2, Point referencePoint) {
    int orientationVal = orientation(referencePoint, p1, p2);
    if (orientationVal == 0) {
        return distSq(referencePoint, p2) >= distSq(referencePoint, p1);
    }
    return orientationVal == 2;
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull not possible with less than 3 points

    // Find the point with the lowest y-coordinate (or leftmost point in case of a tie)
    int minY = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < minY) || (y == minY && points[i].x < points[minIndex].x)) {
            minY = y;
            minIndex = i;
        }
    }

    // Set the reference point as the point with the lowest y-coordinate
    Point referencePoint = points[minIndex];

    // Sort the remaining points based on their polar angle with respect to the reference point
    sort(points.begin(), points.end(), [referencePoint](const Point& p1, const Point& p2) {
        return comparePoints(p1, p2, referencePoint);
    });

    // Initialize an empty stack and push the first three points onto the stack
    stack<Point> hullStack;
    hullStack.push(points[0]);
    hullStack.push(points[1]);
    hullStack.push(points[2]);

    // Iterate through the remaining points
    for (int i = 3; i < n; i++) {
        // While the top two points on the stack and the current point form a non-left turn, pop the top point from the stack
        while (orientation(hullStack.top(), hullStack.top(), points[i]) != 2) {
            hullStack.pop();
        }
        // Push the current point onto the stack
        hullStack.push(points[i]);
    }

    // Convert the stack to a vector and return it
    vector<Point> convexHullPoints;
    while (!hullStack.empty()) {
        convexHullPoints.push_back(hullStack.top());
        hullStack.pop();
    }
    return convexHullPoints;
}

int main() {
    std::vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    std::vector<Point> convexHullPoints = convexHull(points);

    std::cout << "Convex Hull Points:\n";
    for (Point p : convexHullPoints) {
        std::cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
