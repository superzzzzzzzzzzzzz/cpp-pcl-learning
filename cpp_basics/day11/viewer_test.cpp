#include<iostream>
#include <pcl/visualization/pcl_visualizer.h>
#include <thread>
using namespace std;

int main()
{
    pcl::visualization::PCLVisualizer viewer(
        "my first viewer",
        false
    );

    cout << "viewer created" << endl;

    viewer.setBackgroundColor(0, 0, 0);
    cout << "background set" << endl;

    viewer.createInteractor();
    cout << "interactor created" << endl;
    while(true)
    {

        viewer.getRenderWindow()
              ->Render();


        this_thread::sleep_for(
            chrono::milliseconds(100)
        );

    }

}