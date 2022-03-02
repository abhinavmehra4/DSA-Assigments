#include<iostream>
using namespace std;
int fac(int n)
{
    if(n==0)
        return 1;
    return n*fac(n-1);
}
float combination(int n,int r)
{
    if(n>=0&&r>=0)
    {   cout<<"The value of all possible combinations is\n";
        float answer = fac(n)/((fac(n-r))*(fac(r))) ;
        return answer;
    }
    else
    {
        cout<<"Invalid entries";
        return 0;
    }
}
int main()
{   int n,r;
    cout<<"Enter the value of n and r\n";
    cin>>n>>r;
    cout<<endl<<combination(n,r);
    return 0;
}