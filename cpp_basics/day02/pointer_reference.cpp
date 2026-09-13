#include <iostream>

using namespace std;

class Point
{
public:
    float x;
    float y;
    float z;
};

// 引用方式修改
void changeByReference(Point& p)
{
    p.x = 100.0f;
}

// 指针方式修改
void changeByPointer(Point* p)
{
    p->x = 200.0f;
}

void moveByReference(Point&p)
{
    p.x+= 1.0f;
    p.y+= 1.0f;
    p.z+= 1.0f;
}

void moveByPointer(Point* p)
{
    p->x+= 1.0f;
    p->y+= 2.0f;
    p->z+= 3.0f;
}
int main()
{
    Point p1;
    p1.x = 1.0f;
    p1.y = 2.0f;
    p1.z = 3.0f;

    moveByReference(p1);
    cout << "After moveByReference: p1.x = " << p1.x << ", p1.y = " << p1.y << ", p1.z = " << p1.z << endl;

    moveByPointer(&p1);
    cout << "After moveByPointer: p1.x = " << p1.x << ", p1.y = " << p1.y << ", p1.z = " << p1.z << endl;


    return 0;
}