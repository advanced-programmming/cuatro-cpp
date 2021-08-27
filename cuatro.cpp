#include <iostream>
#include <list>

using namespace std;

class Point {
    public: 
        int x;
        int y;

    public:
        void setX(int newX) {x = newX;}
        void setY(int newY) {y = newY;}
        int getX(){return x;}
        int getY(){return y;}
};

bool validatePoints(Point pointArray[]);
int findDifferent(int value1, int value2, int value3);

int main(){
    int x, y;
    Point pointArray [3];

    for(int i = 0; i < 3; i++){
        cin>>x>>y;
        Point point;
        point.setX(x);
        point.setY(y);
        pointArray[i] = point;
    }

    bool validate = validatePoints(pointArray);
    if (validate) {
        x = findDifferent(pointArray[0].getX(), pointArray[1].getX(), pointArray[2].getX());
        y = findDifferent(pointArray[0].getY(), pointArray[1].getY(), pointArray[2].getY());
        cout<<x<<" "<<y<<endl;
    } else {
        cout<< "ERROR";
    }
    
    return 0;
}

int findDifferent(int value1, int value2, int value3) {
    int different;

    if(value1 == value2) {
        different = value3;
    } else if (value1 == value3) {
        different = value2;
    } else {
        different = value1;
    }

    return different;
}


bool validatePoints (Point pointArray[]) {
    bool result = true;

    if((pointArray[0].getX() == pointArray[1].getX()) && 
        (pointArray[1].getX() == pointArray[2].getX()) &&
        (pointArray[0].getX() == pointArray[2].getX()))
            result = false;

    if((pointArray[0].getY() == pointArray[1].getY()) && 
        (pointArray[1].getY() == pointArray[2].getY()) &&
        (pointArray[0].getY() == pointArray[2].getY()))
            result = false;

    if((pointArray[0].getX() != pointArray[1].getX()) && 
        (pointArray[1].getX() != pointArray[2].getX()) &&
        (pointArray[0].getX() != pointArray[2].getX()))
            result = false;

    if((pointArray[0].getY() != pointArray[1].getY()) && 
        (pointArray[1].getY() != pointArray[2].getY()) &&
        (pointArray[0].getY() != pointArray[2].getY()))
            result = false;

    return result;
}


