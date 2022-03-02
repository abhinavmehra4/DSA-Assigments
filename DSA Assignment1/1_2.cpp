#include<iostream>
using namespace std;
int goal(int g)
{
    int sum=0,n;
    for(int i=0;;i++)
    {
        sum=sum+i;
        n=i;
        if(sum>=g)
        break;
    }
    return n;
}
int main()
{

    int g;
    cout<<"Enter the value of the goal ";
    cin>>g;
    cout<<"The value of n is "<<goal(g);
    return 0;

}