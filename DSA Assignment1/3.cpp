#include<iostream>
using namespace std;
int main()
{
    int r, c, a[100][100],b[100][100],sum[100][100];
    cout<<"Enter the number of rows \n";
    cin>>r;
    cout<<"Enter the number of columns \n";
    cin>>c;
    //ENTERING ELEMENTS THE 1ST MATRIX
    cout<<"Enter the elements of the first matrix \n";
    for(int i = 0; i < r; ++i)
      { for(int j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }
      }
    //ENTERING ELEMENTS OF THE 2ND MATRIX
    cout<<"Enter the elements of the second matrix \n";
    for(int i = 0; i < r; ++i)
      { for(int j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }
      }
    //ADDING THE MATRICES
    for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
                { 
                    sum[i][j] = a[i][j] + b[i][j];
                }
        }
    //SHOWING SUM OF THE MATRIX
    cout << endl << "Sum of two matrix is: " << endl;
    for(int i = 0; i < r; ++i)
    {    for(int j = 0; j < c; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == c - 1)
                cout << endl;
        }
    }
    return 0;
}