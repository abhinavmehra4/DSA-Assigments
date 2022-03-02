#include<iostream>
using namespace std;

void Fill(int* x,int* n)
{
    for(int i =0;i<*n;i++)
    {
        cin>>*(x+i);
    }
    return;
}

void Display(int* x,int* n )
{
    for(int i =0; i<*n;i++)
    {
        cout<<*(x+i)<<" ";//outputing array values.
    }
    return;
}
void Increase(int* x, int* n)
{
    int *q = new int[*n+1];;
    for (int i = 0; i < 5; i++)
    {
        q[i] = x[i];
    }
    delete []x;
    x = q;
    q = NULL;
}

void Append(int* x,int n1,int* y)
{
    
    Increase(x,y);
    x[*y-1]=n1; //element is appended
    cout<<"The appended array is \n";
    Display(x,y);
}

// void Insert(int x[],int n1,int n)
// {
//     n++;//increasing size if the array

// }

// void Reverse(int x[],int n)
// {
    
//     int start=0, end=n ; 
//     while(start<end)
//     {   int temp;
//         temp = x[start];
//         x[start]=x[end];
//         x[end]=temp;
//         start++;
//         end--;
//     }
//     cout<<"Reversed array is "<<endl;
//     Display(x,n);
// }

int main()
{   int num;
    cout<<"How many elements do you want to add \n";
    cin>>num;
    int* arr;
    arr = new int[num];
    cout<<"Add elements to the array";
    Fill(arr,&num);
    Display(arr,&num);
    int n1;
    cout<<"Enter the element you want to add to the end of the array \n";
    cin>>n1;
    Append(arr,n1,&num);
    

    return 0;
}