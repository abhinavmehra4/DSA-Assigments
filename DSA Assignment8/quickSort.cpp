#include<iostream>
using namespace std;

int partition(int input[],int si,int ei)
{
  int count=0;
  for(int i =si+1;i<=ei;i++)
  {
    if(input[si]>=input[i]) //we first have to count how many numbers are less than the starting number.
    count++;
  }
  int partitionIndex = si+count; //we have to add this as we are doing recursion.
  //hence the partition is in place
  int tempswap = input[si];
  input[si] = input[partitionIndex];
  input[partitionIndex]=tempswap;

  //now we have to put numbers less than partition element before and the ones greater than it, after it.

  int i=si, j =ei;
  while(i!=partitionIndex&&j!=partitionIndex)
  {
    if(input[i]<=input[partitionIndex]) //if the element is less than, then move the pointer
      i++;
    else if(input[j]>=input[partitionIndex])
      j++;
    else
      {
        tempswap = input[i];
        input[i]=input[j];
        input[j]=tempswap;
      }

  }
  return partitionIndex;
}

void qs(int input[], int si, int ei)
{
  if(si>=ei)
    return;
  int partition_index = partition(input,si,ei);
  qs(input,si,partition_index-1);
  qs(input,partition_index+1,ei);
}

void quickSort(int arr[],int size )
{
  qs(arr,0,size-1);
}

int main()
{
  int n;
  cout<<"Enter the number of terms in the dyanamic array\n";
  cin>>n;

  int *input = new int[n];
  for(int i =0;i<n;i++)
  {
    cin>>input[i];
  }

  quickSort(input,n);

  for(int i =0;i<n;i++)
  {
    cout<<input[i]<<" ";
  }

  delete [] input;
  return 0;
}
