#include<iostream>
using namespace std;

//UNIVERSALLY DECLARING THE ARRAY AND ITS SIZE;
int arr[]={2,6,19,-3,45,77,12,1,0,4};
int n = sizeof(arr)/sizeof(arr[0]); //stores number of elements in an array

void Display(int x[],int n )
{
    for(int i =0; i<n;i++)
    {
        cout<<x[i]<<" ";//outputing array values.
    }
}
void Append(int x[],int n1,int y)
{
    y++;//increasing size of an array by 1;
    cout<<n;
    cout<<y<<endl;
    x[y-1]=n1; //element is appended
    cout<<y<<endl;
    cout<<"The appended array is \n";
    Display(x,y);
    cout<<endl<<y;
}

void Insert(int x[],int n1,int n)
{
    n++;//increasing size if the array

}

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
} 

int main()
{
    //int arr[]={2,6,19,-3,45,77,12,1,0,4};
    //int n = sizeof(arr)/sizeof(arr[0]); //stores number of elements in an array
    cout<<"The array is\n";
    Display(arr,n);//displays all the elements of the array.
    cout<<endl<<n;
    cout<<endl;
    int n1;
    cout<<"Enter the element you want to add at the end of the array\n";
    cin>>n1;
    //n++;//increasing size of an array by 1;
    Append(arr,n1,n);
    //cout<<"Enter the the position at which you want the element\n";
    //int pos;
    //cin>>pos;
    //cout<<"Enter the value which you want to add\n";
    //cin>>n1;
    
    cout<<endl;
    cout<<n<<endl;
    reverseArray(arr,0,n-1);
    

    return 0;
}