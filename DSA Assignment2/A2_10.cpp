#include <iostream>

using namespace std;

int main()
{
    
    int arr[] = {11,8,8,2,3,12,1,1,8,8,8,8,8,1,1,19,21,2,2,11,11,3,3,19,21};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"after removing the duplicates:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
         {
            if(arr[i]==arr[j])
            {
                while(j<n)
                {
                    arr[j]=arr[j+1];
                    j++;

                }
                --n;
            }
            else{
                continue;
            }

        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}