/*MULTIPLICATION OF MATRICES*/
#include<iostream>
using namespace std;
int main()
{

    int a[10][10], b[10][10], mult[10][10]={0}, r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    while (c1!=r2)
    {
        cout << "column of first matrix not equal to row of second.";
        exit(0);
    }
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(int i = 0; i < r1; ++i)
      {  for(int j = 0; j < c1; ++j)
        {
            cin >> a[i][j];
        }
      }
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(int i = 0; i < r2; ++i)
        for(int j = 0; j < c2; ++j)
        {
            cin >> b[i][j];
        }
    //multiplying the matrices
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
            for(int k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
    //displaying the multiplied matrix
    cout << endl << "Output Matrix: " << endl;
    for(int i = 0; i < r1; ++i)
    {
        for(int j = 0; j < c2; ++j)
            {
                cout << " " << mult[i][j];
                if(j == c2-1)
                    cout << endl;
            }
    }
    return 0;
}