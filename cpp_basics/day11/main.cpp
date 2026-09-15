#include <iostream>
#include <cstdlib>
#include <thread>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>


using namespace std;


int main()
{

    setenv(
        "LIBGL_ALWAYS_SOFTWARE",
        "1",
        1
    );


    // 1. 创建点云对象
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(
        new pcl::PointCloud<pcl::PointXYZ>
    );


    // 2. 读取pcd文件

    string filename =
        "data/table_scene_lms400.pcd";


    if(pcl::io::loadPCDFile<pcl::PointXYZ>(
        filename,
        *cloud
    ) == -1)
    {
        cerr<<"Failed to load PCD"<<endl;
        return -1;
    }


    cout<<"Loaded cloud!"<<endl;

    cout<<"Points: "
        <<cloud->points.size()
        <<endl;



    // 3. 创建viewer

    pcl::visualization::PCLVisualizer viewer(
        "Point Cloud Viewer",
        false
    );


    viewer.createInteractor();


    viewer.setBackgroundColor(
        0,
        0,
        0
    );


    viewer.getRenderWindow()
          ->SetMultiSamples(0);



    // 4. 添加点云

    viewer.addPointCloud<pcl::PointXYZ>(
        cloud,
        "cloud"
    );


    cout<<"Cloud added"<<endl;



    // 5. 渲染循环

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