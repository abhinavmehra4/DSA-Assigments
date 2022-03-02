#include<iostream>
#include<string>
using namespace std;
void string_length(string s)
{
    //int n = sizeof(s)/sizeof(s[0]);
   // cout<<n<<endl;
    int count = 0;
    int i =0;
    while(s[i]!='\0')
    {
        
            count++;
            i++;

    }
    cout<<"The length of the string is "<<count<<endl;
}
void string_lowercase(string s)
{
    //lower case alphabets start from 97 to 122 inclusive
    //upper case alphabets start from 65 to 90 inclusive

}
string string_validate(string s)
{ int check;
    for(int i =0;s[i]!='\0';i++)
    {
        if(((int(s[i])>=65)&&(int(s[i])<=90))||((int(s[i])>=97)&&(int(s[i])<=122))||(int(s[i]==32))) 
        //ASCII VALUE FOR whiteSPACE IS 64
        {
            check =1;
        }
        else{
            check =0;
            break;
        }
    
    }
    if(check==1)
    {
        return "The string is valid\n";
    }
    else
        return "The string is not valid\n";
    
}
string string_reversal(string s)
{
    string temp;
    int start =0;
    int end = s.length()-1;
    while(start<end)
    {
        int temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }
    return s;
}
void string_count(string s)
{  int vowel=0, word=1;
    for(int i =0;s[i]!='\0';i++)
    {
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            vowel++;
        }
        if(int(s[i]) == 32)
        {
            word++;
        }
    }
    cout<<"The string has "<<vowel<<" vowels and "<<word<<" words\n";
}
string string_palindrome(string s)
{
    if(s==string_reversal(s))
    {
        return "The string is a palindrome\n";
    }
    return "The string is not a palindrome\n";
}

char* string_duplicate(char s[],int n)
{
    int index = 0;
  
//transverse through all the characters in the array
    for(int i =0;i<n;i++)
    {   int j;
    //checking to see if s[i] is present before it
        for(j=0;j<i;j++)
            {
             if(s[i]==s[j])
             {
                 break;
             }   
        //if the character doesn't repeat and goes through all the iterations of the innermostfor loop, 
        //at the end the value of j is, j=i. Hence the upcoming if statement will m ake sure that it is added to the array.
        //But if we break out of the loop, j  is never equal to i and the character would not be added to the string.
            }
        
        if(j==i)
        {
            s[index++]=s[i];
                
        }
        
    }
   
    return s;
}

int main()
{
    cout<<"Enter a string \n";
    string str,str1,str2;
    getline(cin,str);
    //String Length
    string_length(str);
    //String validation
    cout<<"Enter the string you want to validate\n";
    getline(cin,str1);
    cout<<string_validate(str1);
    //Reversing a string
    cout<<"Enter the string you want to reverse\n";
    getline(cin,str2);
    str2 = string_reversal(str2);
    cout<<str2<<endl;
    //counting the words and vowels
    string_count(str2);
    //checking if string is a palindrome
    cout<<string_palindrome(str2);
    //finding duplicate elements
    cout<<"Enter a string to check for duplicate behaviour\n";
    char str3[]={"supercalifragilistisexpialidocious"};
    int n=sizeof(str3)/sizeof(str3[0]);
    cout<<string_duplicate(str3,n);
    cout<<endl<<str3;
    
    return 0;
}