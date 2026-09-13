#include <iostream>

#include "Point.h"

using namespace std;


int main()
{

    Point p1(1,2,3);


    cout << p1.getX()
         << endl;


    p1.setX(100);


    cout << p1.getX()
         << endl;


    return 0;
}