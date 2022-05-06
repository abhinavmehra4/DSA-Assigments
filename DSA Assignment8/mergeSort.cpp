#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r)
{
  //make two temporary arrays to sort the 2 arrays and then merge then into the original arrays.
  int n1 = mid-l+1;//as middle term is included
  int n2 = r-mid;

  int a[n1],b[n2];

  //fillinng these 2 arrays
  for(int i = 0;i<n1;i++)
  {
    a[i]=arr[l+i];
  }
  for(int i = 0;i<n2;i++)
  {
    b[i]=arr[mid+1+i];
  }
  int i=0,j=0,k=l;// k traverses the main array.
  //comparing and filling the arrays
  while(i<n1 && j<n2)
  {
    if(a[i]<b[j])
    {
      arr[k]=a[i];
      i++; k++;
    }
    else
    {
      arr[k]=b[j];
      j++;k++;
    }
  }
  //there also might be cases where, the firfst array might finish before the second term.
  while(i<n1)
  {
    arr[k]=a[i];
    k++;i++;
  }
  while(j<n2)
  {
    arr[k]=b[j];
    k++;j++;
  }

}

void mergeSort(int arr[],int l,int r)
{
  //l is the first index and r is the last index

  if(l<r)
  {
    int mid = (l+r)/2;

    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r); //merging the 2 sorted arrays
  }

  //when l=0, r=0, the returns its call. but if we didnt put this below return, our code would still return.
  else
    return;
}

int main()
{
  int arr[]= {5,4,3,2,1};
  for(int i =0;i<5;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  mergeSort(arr,0,4);
  for(int i=0;i<5;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  return 0;
}
