#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void prefix1(char w[100]);
void suffix1(char w[100]);

int main()
{
    char input[100];
    int i;
    cout<<"Enter the string:"<<endl;
    gets(input);
    prefix1(input);
    suffix1(input);
    getch();
    return 0;
}

void prefix1(char input[100])
{
    int i,j;
    cout<<"The possible prefixes are:"<<endl;
    for(i=strlen(input);i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            cout<<input[j];
        }
        cout<<"\n";
    }
}

void suffix1(char input[100])
{
    int i,j;
    cout<<"The possible suffixes are:"<<endl;
    for(i = 0;i<strlen(input);i++)
    {
        for(j=i;j<strlen(input);j++)
        {
            cout<<input[j];
        }
        cout<<"\n";
    }
}