#include<iostream>
using namespace std;
class rectangle{
  public:
  rectangle(int l,int b)
  {
      length = l;
      breadth = b;
  }
    int length,breadth;
    int perimeter()
    {
        return 2*(length+breadth);
    }
    int area()
    {
        return length*breadth;
    }
};
int main()
{
    int x,y;
    cout<<"Enter the length and breadth of the rectangle\n";
    cin>>x>>y;
    rectangle r(x,y);
    cout<<"The perimeter of the rectangle is "<<r.perimeter()<<endl;
    cout<<"The area of the rectangle is "<<r.area()<<endl;
    return 0;
}