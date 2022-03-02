#include<iostream>
#include<string>
using namespace std;
int main()
{
    string numbers[9] = { "one","two","three","four","five","six","seven","eight","nine"};
    int num;
    cout<<"Enter number between 1 to 9\n";
    cin>>num;
    cout<<numbers[num-1];
    return 0;
}