#include<iostream>
using namespace std;
void Display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
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
int remove_duplicate(int arr[],int n)
{
    if(n==1||n==0)
    {return n;}

    int temp[n];
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=arr[i+1])
        {temp[j++]=arr[i];}
    }
        temp[j++]=arr[n-1];// this step is done to add the last element of the array to temp array
    
        //we feed the elements stored in the temp array back to the original one
        for(int i=0;i<j;i++)
        {
            arr[i]=temp[i];
        }
    return j;// this returns the value of the number of terms in the array without duplicate elements
}


int* sort(int x[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(x[j]>x[j+1])
            {
                int temp;
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    return x;
}

void find_max_min(int arr[],int n)
{
    int max = arr[0], min=arr[0];
    int i,j;
    for(i=1;i<n;i++)
    {
        max = arr[i]>max?arr[i]:max;
        min = arr[i]>min?min:arr[i];
    }
    cout<<"\nThe maximum value in the array is "<<max<<endl;
    cout<<"The minimum value in the array is "<<min<<endl;

}

void pair_sum(int arr[],int n, int sum)
{
    for(int i =0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
            {
                cout<<"Sum of "<<arr[i]<<" and "<<arr[j]<<" is equal to "<<sum<<endl;
                return ;
            }
        }
    }
    cout<<"No pair exits to give the value that you want\n";
}

int unsorted_duplicate(int arr[],int n)
{
    int i,j,k,key,exists;
    int arr_2[100]={0};

        for(i =0,j=0;i<n;i++)
        {
            key = arr[i];
            exists=0;
            for(int k =0;k<i;k++)
            {
                if(arr_2[k]==key)
                {
                    exists=1;
                }
            }
            if(!exists)
            {
                arr_2[j]=arr[i];
                j++;
            }
        }
    n=j;

    for(int z=0;z<n;z++)
    {
        arr[z]=arr_2[z];
    }
    
    return n;
}


int main()
{
    int arr[] = {11,8,8,2,3,12,1,1,8,8,8,8,8,1,1,19,21,2,2,11,11,3,3,19,21};
    int n = sizeof(arr)/sizeof(arr[0]);
    //finding a single element
    cout<<"Enter the element you want to find \n";
    int e;
    cin>>e;
    int check = linearSearch(arr,n,e);
    if(!check)
    cout<<"Element not found\n";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //Removing elements from the sorted array
    int* sorted_arr = sort(arr,n);
    n = remove_duplicate(sorted_arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<*(sorted_arr+i)<<" ";
    }

    cout<<endl;
    //remove duplicate elements from unsorted array
    cout<<"\nRemoving duplicates from unsorted array\n";
    
    //Since the above array is already sorted, take a new array
    int arr1[] = {11,8,8,2,3,12,1,1,8,8,8,8,8,1,1,19,21,2,2,11,11,3,3,19,21};
    int n1 = sizeof(arr)/sizeof(arr[0]); 
    n1 = unsorted_duplicate(arr1,n1);
    Display(arr1,n1);
    cout<<endl;
    //findind the maximum and minimum
    find_max_min(arr,n);
    int sum;
    cout<<"enter the value that you would like to see as the sum of the elements of the array\n";
    cin>>sum;
    pair_sum(arr,n,sum);
    return 0;
}