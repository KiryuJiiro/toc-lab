#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void substring1(char w[100],int a,int b);

int main()
{
    char input[100],result;
    int start,end,i;
    cout<<"Enter the string:"<<endl;
    gets(input);
    do
    {
        cout<<"Enter the starting position of the subsritng:"<<endl;
        cin>>start;
        cout<<"Enter the ending position of the substring:"<<endl;
        cin>>end;
    }while(start < 1 || end > strlen(input));
    substring1(input,start-1,end-1);
    getch();
    return 0;
}
void substring1(char w[100],int start,int end)
{
    int i;
    cout<<"The substring is:"<<endl;
    for(i=start;i<=end;i++)
    {
        cout<<w[i];
    }
}
