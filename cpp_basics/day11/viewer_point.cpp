#include <iostream>
#include <thread>
#include <chrono>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>


using namespace std;


int main()
{

    // 创建点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(
        new pcl::PointCloud<pcl::PointXYZ>
    );


    // 创建一个点

    pcl::PointXYZ p1;
    p1.x=0;
    p1.y=0;
    p1.z=0;


    pcl::PointXYZ p2;
    p2.x=2;
    p2.y=2;
    p2.z=2;


    pcl::PointXYZ p3;
    p3.x=0;
    p3.y=1;
    p3.z=0;

    pcl::PointXYZ p4;

    p4.x=0;
    p4.y=0;
    p4.z=1;

    cloud->push_back(p4);


    cloud->push_back(p1);
    cloud->push_back(p2);
    cloud->push_back(p3);


    // 设置点云颜色    



    cout<<"point number: "
        <<cloud->points.size()
        <<endl;



    // 创建viewer

    pcl::visualization::PCLVisualizer viewer(
        "One Point Viewer",
        false
    );


    viewer.createInteractor();
    viewer.addCoordinateSystem(2.0);



    // 添加点云

    viewer.addPointCloud<pcl::PointXYZ>(
        cloud,
        "cloud"
    );

    viewer.setCameraPosition(
        5,5,5,
        0,0,0,
        0,0,1
    );



    // 设置点大小

    viewer.setPointCloudRenderingProperties(
        pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
        10,
        "cloud"
    );



    while(true)
    {

        viewer.getRenderWindow()
              ->Render();


        this_thread::sleep_for(
            chrono::milliseconds(100)
        );

    }


    return 0;
}