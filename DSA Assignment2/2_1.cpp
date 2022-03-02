#include<iostream>
using  namespace std;
void Display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
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
int Append(int x[],int n,int y)
{
    n++;
    x[n-1]=y;
    Display(x,n);
    return n;
}
int linearSearch(int x[],int n,int n1)
{
    for(int i=0;i<n;i++)
    {
        if(n1==x[i])
        {
            cout<<"Element found and is at index no. "<<i;
            return 1;
            break;
        }
    }                                              
    return 0;
}
void Get(int x[],int y,int n)
{
    if(y<n)
    cout<<"The value at index "<<y<<" is "<<x[y]<<endl;
    else
    cout<<"index number is invalid\n";
}
int Max(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
        {
            if (arr[i] > max)
           {max = arr[i];
           }
        }
    return max;
}
void Min(int arr[], int n)
{
    int min = arr[0];
    for(int i =1;i<n;i++)
   {
       min=arr[i]<min?arr[i]:min;
   } 
   cout<<"Minimum value of the array is "<<min<<endl;
}
void shift(int x[],int n)
{
    int last = x[n-1];
    for(int i=n-2;i>=0;i--)
    {
        x[i+1]=x[i];
    }
    x[0]=last;
}
int Insert(int arr[],int n,int y,int index)
{
    if(index>=n)
    {
        cout<<"INVALID INDEX\n";
        return n;
    }
    n++;
    for(int i=n-2;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=y;
    
    Display(arr,n);
    return n;
}
int Delete(int arr[],int n,int index)
{
    if(index>=n)
    {
        cout<<"INVALID INDEX\n";
        return n;
    }
    for(int i =index;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    Display(arr,n);
    return n;
}
void rotate(int arr[],int n,int x)
{
    int i = 1;
    while(i<=x)
    {
        shift(arr,n);
        i++;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    //Display 
    Display(arr, n);
    //Append
    cout<<"Enter the number you wish to append\n";
    int z;
    cin>>z;
    n = Append(arr,n,z);
    cout<<endl;
    cout<<"After adding a term the array as "<<n<<" elements"<<endl;
    Display(arr,n);
    //Linear Search
    int e;
    cout<<"Enter the element you want to find \n";
    cin>>e;
    int check = linearSearch(arr,n,e);
    if(!check)
    cout<<"Element not found\n";
    cout<<endl;
    //Get
    int n1;
    cout<<"Enter the index at whose position you want to find the element \n";
    cin>>n1;
    cout<<endl;
    Display(arr,n);
    Get(arr,n1,n);
    //Max
    int max=Max(arr,n);
    cout<<"Maximum element of the array is "<<max<<endl;
    cout<<endl;
    Display(arr,n);
    //Min
    Min(arr,n);
    cout<<endl;
    Display(arr,n);
    //Reverse
    reverseArray(arr, 0, n-1); // since address of the array is sent, direct changes in the array are made.
    cout<<endl;
    cout << "Reversed array is" << endl;
    Display(arr,n);
    shift(arr,n);
    cout<<endl;
    Display(arr,n);
    //Insert
    int num;
    cout<<"Enter the number which you want to insert\n";
    cin>>num;
    int pos;
    cout<<"Enter the index at which you want to insert the num"<<endl;
    cin>>pos;
    n = Insert(arr,n,num,pos);
    cout<<endl;
    //Delete
    cout<<"Enter the index number whose element you want to delete\n";
    cin>>pos;
    n=Delete(arr,n,pos);
    cout<<endl;
    Display(arr,n);
     cout<<endl;
    //Rotate
    int num1;
    cout<<"Enter the number of times you want the array to get rotated\n";
    cin>>num1;
    rotate(arr,n,num1);
    cout<<"The rotated array is\n";
    Display(arr,n);
    return 0;
}