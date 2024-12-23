#include<iostream>
#include<string.h>
using namespace std;
int current;
void stateA(char ip,char ipp)
{
    if(ip == '0')
    {
        if(ipp == '0')
        {
            current = 1;
        }
        else{
            current = 0;
        }
    }
    else{
        current = 0;
    }
}
void stateB (char ip)
{
    if(ip == '0')
    {
        current = 2;
    }
}
void stateC (char ip )
{
    if(ip == '1')
    {
        current = 3;
    }
}
void stateD(char ip)
{
    current = 3;
}

int NFA_substring (string w)
{
    int i ,l;
    l = w.length();
    current = 0;
    for(i= 0; i<1 ;  i++)
    {
        if(current == 0)
        {
            stateA (w[i],w[i+1]);
        }
        else if(current == 1)
        {
            stateB(w[i]);
        }
        else if (current == 2)
        {
            stateC (w[i]);
        }
        else if ( current ==3)
        {
            stateD (w[i]);
        }
    }
    return current;
}
int main()
{
    string w;
    cout<<"Enter string :";
    cin>>w;
    current = NFA_substring(w);
    if(current == 3)
    {
        cout<<w<<"is rejected";
    }
    else{
        cout<<w<<"is accepted";
    }
    return 0;
}