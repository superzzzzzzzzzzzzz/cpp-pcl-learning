#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

struct Point{
    float x;
    float y;
    float z;
};

Point computeCenter(const vector<Point>& points)
{
    float sumx = 0.0f;
    float sumy = 0.0f;
    float sumz = 0.0f;
    for(const auto& point : points)
    {
        sumx += point.x;
        sumy += point.y;
        sumz += point.z;
    }
    Point center;
    center.x = sumx / points.size();
    center.y = sumy / points.size();
    center.z = sumz / points.size();

}

int main()
{
    vector<Point> points;

    points.push_back({0.01f, 0.02f, 0.03f});
    points.push_back({0.02f, 0.01f, 0.04f});
    points.push_back({0.03f, 0.04f, 0.02f});

    points.push_back({0.06f, 0.07f, 0.08f});
    points.push_back({0.08f, 0.06f, 0.09f});
    points.push_back({0.09f, 0.08f, 0.07f});

    float leaf_size = 0.05f;

    vector<Point> voxel0;
    vector<Point> voxel1;

    for (const auto& point : points)
    {
        int ix = floor(point.x / leaf_size);
        int iy = floor(point.y / leaf_size);
        int iz = floor(point.z / leaf_size);

        if (ix == 0 && iy == 0 && iz == 0)
        {
            voxel0.push_back(point);
        }
        else if (ix == 1 && iy == 1 && iz == 1)
        {
            voxel1.push_back(point);
        }
    }

    cout << "voxel0: "
        << voxel0.size()
        << " points" << endl;

    cout << "voxel1: "
        << voxel1.size()
        << " points" << endl;
    
        Point center0 = computeCenter(voxel0);
    Point center1 = computeCenter(voxel1);

    cout << "Center of voxel0: "
        << center0.x << " "
        << center0.y << " "
        << center0.z << endl;

    cout << "Center of voxel1: "
        << center1.x << " "
        << center1.y << " "
        << center1.z << endl;
 }
