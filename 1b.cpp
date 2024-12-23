#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

void substring2(char w[100],int a,int b);

int main()
{
    char input[100];
    int start,noofsymbol,i;
    cout<<"Enter the string:"<<endl;
    gets(input);
do
{
    cout<<"Enter the starting position of substring:";
    cin>>start;
    cout<<"Enter the number of symbos to be extracted:";
    cin>>noofsymbol;
}while(start<1||noofsymbol>strlen(input));
substring2(input,start-1,noofsymbol);
getch();
return 0;
}

void substring2(char w[100],int start,int noofsymbol)
{
    int i;
    cout<<"the substring is:"<<endl;
    for(i=start;i<=noofsymbol;i++)
    {
        cout<<w[i];
    }
}