#include<iostream>
using namespace std;
bool check_sorted(int x[],int n)
{ int y;
    for(int i =0;i<n-1;i++)
    {
        if(x[i]<x[i+1])
        y=1; 
        else
         {
             y=0;
             break;
         }
    }
    return y;
}
int* merge(int x[],int y[],int arr3[],int n1,int n2,int n3)
{
    for(int i=0;i<n1;i++)
    {
        arr3[i]=x[i];
    }
    for(int i=n1,j=0;i<(n3);i++,j++)
    {
        arr3[i]=y[j];
    }
    return arr3;
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

void union_operation(int x[],int y[],int z[],int n1,int n2,int n3)
{
    int* merged_array = merge(x,y,z,n1,n2,n3);
    int* sorted_arr = sort(merged_array,n3);
    n3 = remove_duplicate(merged_array,n3);
    for(int i=0;i<n3;i++)
    {
        cout<<*(sorted_arr+i)<<" ";
    }

}

void intersection(int input1[], int input2[], int size1, int size2) 
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */

    int i,j;
    for(i=0;i<size1;i++){
        
     for(j=0;j<size2;j++){
         if(input1[i]==input2[j]){
             cout<<input1[i];
             cout<<endl;
             input2[j]=-9999999999999999999;
             break;
         }
  
     }
     }
}
int main()
{
    int arr1[] = {23,78,9,11,3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {1,2,3,4,5,9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

//checking if sorted
    int check = check_sorted(arr1,n1);
    if(check==1)
    cout<<"Array 1 is sorted\n";
    else
    cout<<"Array 1 is not sorted\n";

    check = check_sorted(arr2,n2);
    if(check==1)
    cout<<"Array 2 is sorted\n";
    else
    cout<<"Array 2 is not sorted\n";

//merging of array
    int n3=n2+n1;
    int arr3[n3];
    int* merged_arr = merge(arr1,arr2,arr3,n1,n2,n3);
    cout<<"The merged array is \n";
    for(int i=0;i<n3;i++)
    {
        cout<<*(merged_arr+i)<<" ";
    }
    cout<<endl;

//union operation
    int n4=n1+n2;
    int arr4[n3];
    cout<<"Union of the two arrays is\n";
    union_operation(arr1,arr2,arr4,n1,n2,n4);

//intersection operation

    int n5=n1+n2;
    int arr5[n5];
    cout<<"\nIntersection of the two arrays is\n";
    intersection(arr1, arr2, n1, n2);

    return 0;
}