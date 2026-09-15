#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


struct Point
{
    float x;
    float y;
    float z;
};


struct Voxel
{
    float sum_x = 0.0f;
    float sum_y = 0.0f;
    float sum_z = 0.0f;

    int count = 0;
};


int main()
{
    vector<Point> points;

    // -------------------------
    // 1. 生成1000个原始点
    // -------------------------
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            for (int z = 0; z < 10; z++)
            {
                Point p;

                p.x = x * 0.01f;
                p.y = y * 0.01f;
                p.z = z * 0.01f;

                points.push_back(p);
            }
        }
    }

    cout << "Original points: "
         << points.size()
         << endl;


    // -------------------------
    // 2. 设置体素大小
    // -------------------------
    float leaf_size = 0.05f;


    // -------------------------
    // 3. 创建 2×2×2 个 voxel
    // -------------------------
    Voxel voxels[2][2][2];


    // -------------------------
    // 4. 把每个点放入对应 voxel
    // -------------------------
    for (const auto& point : points)
    {
        int ix = floor(point.x / leaf_size);
        int iy = floor(point.y / leaf_size);
        int iz = floor(point.z / leaf_size);

        voxels[ix][iy][iz].sum_x += point.x;
        voxels[ix][iy][iz].sum_y += point.y;
        voxels[ix][iy][iz].sum_z += point.z;

        voxels[ix][iy][iz].count++;
    }


    // -------------------------
    // 5. 每个 voxel 求质心
    // -------------------------
    int output_count = 0;

    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            for (int z = 0; z < 2; z++)
            {
                Voxel& voxel = voxels[x][y][z];

                if (voxel.count > 0)
                {
                    float center_x =
                        voxel.sum_x / voxel.count;

                    float center_y =
                        voxel.sum_y / voxel.count;

                    float center_z =
                        voxel.sum_z / voxel.count;

                    cout << "Voxel ("
                         << x << ", "
                         << y << ", "
                         << z << ")"
                         << endl;

                    cout << "  Number of points: "
                         << voxel.count
                         << endl;

                    cout << "  Center: ("
                         << center_x << ", "
                         << center_y << ", "
                         << center_z << ")"
                         << endl;

                    output_count++;
                }
            }
        }
    }


    cout << "Filtered points: "
         << output_count
         << endl;

    return 0;
}