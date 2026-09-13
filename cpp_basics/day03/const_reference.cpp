#include <iostream>
using namespace std;
#include <vector>

class Point
{
public:
    float x;
    float y;
    float z;
    
    Point(float x_,float y_,float z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
};

void printPoints(vector<Point>& points)
{
    for (const auto& point : points)
    {
        cout<< "Point  (" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
    }
}




int main()
{

    vector<Point> points;

    points.push_back(Point(1.0f, 2.0f, 3.0f));
    points.push_back(Point(4.0f, 5.0f, 6.0f));
    points.push_back(Point(7.0f, 8.0f, 9.0f));
    printPoints(points);
    return 0;
}