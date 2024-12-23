#include<iostream>
#include<string.h>
using namespace std;
int current;
void stateA (char ip, char ipp)
{
    if(ip == '0')
    {
        if(ipp == '1')
        {
            current = 1;
        }
        else
        {
            current = 0;
        }
    }
    else
    {
        current = 0;
    }
}

void stateB (char ip)
{
    if(ip == '1')
    {
        current = 2;
    }

}
int NFA_end (string w)
{
    int i,l;
    l = w.length();
    current = 0;
    for(i = 0; i<l; i++)
    {
        if(current == 0)
        {
            stateA (w[i],w[i+1]);
        }
        else if(current == 1)
        {
            stateB(w[i]);
        }
        else{
            current = 0;
            i--;
        }
    }
    return current ;
}

int main()
{
    string w;
    cout<<"Enter string:";
    cin>>w;
    current = NFA_end(w);
    if(current == 2)
    {
        cout<<w<<"is accepted";
    }
    else{
        cout<<w<<"is rejected";
    }
    return 0;
}