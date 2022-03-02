#include <iostream>

using namespace std;

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
    // int i,j,k,key,exists;
    // int arr_2[100]={0};

    //     for(i =0,j=0;i<n;i++)
    //     {
    //         key = arr[i];
    //         exists=0;
    //         for(int k =0;k<i;k++)
    //         {
    //             if(arr_2[k]==key)
    //             {
    //                 exists=1;
    //             }
    //         }
    //         if(!exists)
    //         {
    //             arr_2[j]=arr[i];
    //             j++;
    //         }
    //     }

    // cout<<endl;
    // for(i=0;i<j;i++)
    // {
    //     cout<<arr_2[i]<<" ";
    // }
    cout<<endl;
    n = unsorted_duplicate(arr,n);
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}