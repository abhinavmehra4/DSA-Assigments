#include<iostream>
using namespace std;
int fac(int n)
{
    if(n==0)
        return 1;
    return n*fac(n-1);
}
int main()
{   int x;
    cout<<"Enter the number whose factorial you want\n";
    cin>>x;
    cout<<fac(x)<<endl;
    return 0;
}