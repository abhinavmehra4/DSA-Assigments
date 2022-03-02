#include<iostream>
using namespace std;
int find(int n1, int n2)
{   int gcd;
    if(n2>n1)
        {
            int temp;
            temp;n1;
            n1=n2;
            n2=temp;    
        }

    for (int i = 1; i <=  n2; ++i) {
        if (n1 % i == 0 && n2 % i ==0) {
        gcd = i;
        }
    }
    return gcd;
}
int main()
{
    int n1, n2, gcd;

    cout<<"Enter the two numbers\n";
    cin>>n1>>n2;
cout<<"The GCD is "<<find(n1,n2);
    return 0;

}