#include<iostream>
using namespace std;


class Point
{
    public:
        float x;
        float y;
        float z;
};

int main()
{
    Point p1;
    p1.x = 10;
    Point& a = p1;
    a.x = 20;
    cout << "p1.x = " << p1.x << endl;
    Point* p2 = &p1;
    p2->x = 30;
    cout << "p2->x = " << p2->x << endl;
    return 0;
}