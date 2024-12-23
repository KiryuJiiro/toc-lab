#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

void prefix2(char w[100],int n);
void suffix2(char w[100],int num);

int main()
{
    char input[100];
    int i,n,num;
    cout<<"Enter the string:"<<endl;
    gets(input);
    cout<<"Enter the number of trailing symbol to be removed:"<<endl;
    cin>>n;
    prefix2(input,strlen(input)-n);
    cout<<"Enter the number of leading symbol to be removed:"<<endl;
    cin>>num;
    suffix2(input,num);
    getch();
    return 0;
}

void prefix2(char input[100],int n)
{
    int i;
    cout<<"The prefix is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<input[i];
    }
    cout<<endl;
}

void suffix2(char input[100],int num)
{
    int i;
    cout<<"The suffix is:"<<endl;
    for(i=num;i<=strlen(input);i++)
        {
            cout<<input[i];
        }
}