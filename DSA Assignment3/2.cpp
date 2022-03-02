#include<iostream>
using namespace std;
char* string_sort(char s[],int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(int(s[j])>int(s[j+1]))
            {
                char temp;
                temp=s[j];
                s[j]=s[j+1];
                s[j+1] = temp;
                
            }
        }
    }
    return s;
}
int main()
{
    char str[]={"abhjwcaiwecneicunnaeibercib"};
    int n = sizeof(str)/sizeof(str[0]);
    char* sorted_string = string_sort(str,n); 
    cout<<"The sorted string is\n";
    for(int i =0;i<n;i++)
    {
        cout<<*(sorted_string+i);
    }

    return 0;
}