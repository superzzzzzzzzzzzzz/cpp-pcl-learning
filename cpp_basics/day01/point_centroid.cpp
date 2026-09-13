#include <iostream>
#include <vector>

using namespace std;

class Point
{
public:
    float x;
    float y;
    float z;
};

void printPoints(const vector<Point>& points)
{
    for (int i = 0; i < points.size(); i++)
    {
        cout << "Point " << i << ": ("
             << points[i].x << ", "
             << points[i].y << ", "
             << points[i].z << ")"
             << endl;
    }
}

void printZhixin(const vector<Point>& points)
{
    float sum_x = 0.0f;
    float sum_y = 0.0f;
    float sum_z = 0.0f;

    for (int i = 0; i < points.size(); i++)
    {
        sum_x += points[i].x;
        sum_y += points[i].y;
        sum_z += points[i].z;
    }

    cout << "质心坐标为: ("
         << sum_x / points.size() << ", "
         << sum_y / points.size() << ", "
         << sum_z / points.size() << ")"
         << endl;
}

int main()
{
    vector<Point> points;

    points.push_back({1.0f, 2.0f, 3.0f});
    points.push_back({4.0f, 5.0f, 6.0f});
    points.push_back({7.0f, 8.0f, 9.0f});
    points.push_back({10.0f, 11.0f, 12.0f});
    points.push_back({13.0f, 14.0f, 15.0f});

    printPoints(points);
    printZhixin(points);

    return 0;
}