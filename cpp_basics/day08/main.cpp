#include <iostream>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

using namespace std;

int main()
{
    // 创建一个空点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(
        new pcl::PointCloud<pcl::PointXYZ>
    );

    // 从 PCD 文件读取点云
    int result = pcl::io::loadPCDFile<pcl::PointXYZ>(
        "my_cloud.pcd",
        *cloud
    );

    // 判断读取是否成功
    if (result == -1)
    {
        cout << "Failed to load PCD file!" << endl;
        return -1;
    }

    cout << "PCD file loaded successfully!" << endl;

    cout << "Number of points: "
         << cloud->points.size()
         << endl;

    // 打印所有点
    for (const auto& point : cloud->points)
    {
        cout << "("
             << point.x << ", "
             << point.y << ", "
             << point.z << ")"
             << endl;
    }

    return 0;
}