#include <iostream>
#include <cmath>
using namespace std;


class point
{
double x;
double y;

public:
point(double xcord , double ycord) : x(xcord) , y(ycord) {}

double getx () {
    return x;
}
double gety (){
    return y;
}
void setx (double newx){
    x=newx;
}
void sety (double newy){
    y = newy;
}
void print () {
    cout<< "("<<x<<","<<y<<")"<<endl;
}
double distance (point point2) {
    double d;
    double xd=x - point2.x;
    double yd=y - point2.y;
    xd=xd*xd;
    yd=yd*yd;
    d=xd+yd;
    d=sqrt(d);
    return d;
}
};

int main()
{
    double x,y,x2,y2;
cout<<"enter your x cordinants for point1: ";
cin>>x;
cout<<endl<<"enter your Y cordinants for point1: ";
cin>>y;
cout<<"enter your x cordinants for point2: ";
cin>>x2;
cout<<endl<<"enter your Y cordinants for point2: ";
cin>>y2;
point point1(x,y);
point point2(x2,y2);
cout<<"the distance between these two points is "<<point1.distance (point2);
return 0;
}
