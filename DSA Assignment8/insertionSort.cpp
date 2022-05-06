#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
  for(int i =0;i<n;i++)
  {
    int current=arr[i];
    int j =i-1;
    while(arr[i]>current && j>=0)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=current;
  }
}
int main()
{
  //insert an element from unsorted array to its correct position in the sorted array
  //correct position means that the elements before it must be lesser in value and the elements after it must be greater in value
  int arr[]={12,45,23,51,19,8};
  int n =6;
  selectionSort(arr,n);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
