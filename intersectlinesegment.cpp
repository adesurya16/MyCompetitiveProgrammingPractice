#include <bits/stdc++.h>
using namespace std;
#define undefined -999999999

class point
{
public:
    double x;
    double y;
    point()
    {
        this->x = 0;
        this->y = 0;
    }
    point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

class lineSegment
{
public:
    double A, B, C; // Ax + By = C
    point p1, p2;   // boundary points
    lineSegment(point a, point b)
    {
        this->p1 = point(a.x, a.y);
        this->p2 = point(b.x, b.y);
        this->A = b.y - a.y;
        this->B = a.x - a.y;
        this->C = this->A * a.x + this->B * a.y;
    }
    double getGradient()
    {
        if (this->A == 0)
        {
            return undefined;
        }
        return this->B / this->A;
    }

    bool isVertical()
    {
        return this->A == 0;
    }

    bool isHorizontal()
    {
        return this->B == 0;
    }

    bool isOnTheSegment(point p)
    {
        return p.x <= max(this->p1.x, this->p2.x) && p.x >= min(this->p1.x, this->p2.x) && p.y <= max(this->p1.y, this->p2.y) && p.y >= min(this->p1.y, this->p2.y);
    }
};

bool doIntersect(point a, point b, point c, point d)
{
    // calculate the intersection point between 2 segment lines (if exist)
    // if the intersection point is on the segment lines, then return true
    // else return false
    lineSegment l1(a, b);
    lineSegment l2(c, d);
    if (l1.getGradient() == l2.getGradient()) // colinier
    {
        if (l1.isOnTheSegment(c) || l1.isOnTheSegment(d) || l2.isOnTheSegment(a) || l2.isOnTheSegment(b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        double det = l1.A * l2.B - l2.A * l1.B; // colinier
        if (det == 0)
        {
            // this case has been handled above
            return false;
        }
        else
        {
            double x = (l2.B * l1.C - l1.B * l2.C) / det;
            double y = (l1.A * l2.C - l2.A * l1.C) / det;
            if (l1.isOnTheSegment(point(x, y)) && l2.isOnTheSegment(point(x, y)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

double orientation(point a, point b, point c)
{
    // return the orientation of the three points
    // if the three points are colinier, return 0
    // if the three points are clockwise, return 1
    // if the three points are counterclockwise, return -1
    double val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0)
    {
        return 0;
    }
    else if (val > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool onSegment(point a, point b, point c)
{
    // check if point a is on the segment bc
    if (a.x <= max(b.x, c.x) && a.x >= min(b.x, c.x) && a.y <= max(b.y, c.y) && a.y >= min(b.y, c.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool doIntersectUsingOrientation(point a, point b, point c, point d)
{
    // calculate the intersection point between 2 segment lines (if exist)
    // if the intersection point is on the segment lines, then return true
    // else return false
    double o1 = orientation(a, b, c);
    double o2 = orientation(a, b, d);
    double o3 = orientation(c, d, a);
    double o4 = orientation(c, d, b);
    // general case
    if (o1 != o2 && o3 != o4)
    {
        return true;
    }
    // spesial case
    else if (o1 == 0 && onSegment(c, a, b))
    {
        return true;
    }
    else if (o2 == 0 && onSegment(d, a, b))
    {
        return true;
    }
    else if (o3 == 0 && onSegment(a, c, d))
    {
        return true;
    }
    else if (o4 == 0 && onSegment(b, c, d))
    {
        return true;
    }
    // it means no intersection between them
    else
    {
        return false;
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    // two line segment intersect problem
    point a;
    point b;
    cin >> a.x >> a.y >> b.x >> b.y;
    point c;
    point d;
    cin >> c.x >> c.y >> d.x >> d.y;
    cout << (doIntersect(a, b, c, d) ? "yes" : "no") << endl;
    cout << (doIntersectUsingOrientation(a, b, c, d) ? "yes" : "no") << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}