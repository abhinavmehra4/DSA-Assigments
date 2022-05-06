#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=i;j<n;j++)
    {
      if(arr[j]<arr[i])
      {
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
      }
    }
  }
}
int main()
{
  //find minimum element in the unsorted array and swap with the element at the beginning
  int arr[6]={12,45,23,51,19,8};
  selectionSort(arr,6);

  for(int i =0;i<6;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}
