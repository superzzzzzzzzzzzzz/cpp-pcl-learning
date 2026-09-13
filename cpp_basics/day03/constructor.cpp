#include<iostream>
using namespace std;
#include<vector>

class Point
{
public:
    float x;
    float y;
    float z;
    Point(float x_, float y_, float z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
};

void printPoints(const vector<Point>& points)
{
    for(const auto& point : points)
    {
        cout << "Point (" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
    }
}

void addPoint(vector<Point>& points)
{
    for(auto& point : points)
    {
        point.x += 1.0f;
        point.y += 1.0f;
        point.z += 1.0f;
    }
}

int main()
{
    vector<Point> points;
    points.push_back(Point(1.0f, 2.0f, 3.0f));
    points.push_back(Point(4.0f, 5.0f, 6.0f));
    points.push_back(Point(7.0f, 8.0f, 9.0f));
    points.push_back(Point(10.0f, 11.0f, 12.0f));
    points.push_back(Point(13.0f, 14.0f, 15.0f));

    printPoints(points);
    addPoint(points);
    cout << "After adding 1 to each coordinate:" << endl;
    printPoints(points);
    return 0;   
}