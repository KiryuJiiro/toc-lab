#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int current_state = 0;
void state0 (char c)
{
    if (isalpha(c) || c =='_' )
    {
        current_state = 1;
    }
    else
    {
        current_state = -1;
    }
}

void state1(char c)
{
    if(isalnum(c)  || c =='_')
    {
        current_state = 1;
    }
    else
    {
        current_state = -1;
    }
}
int DFA_for_Identifier(string z)
{
    current_state = 0;
    int i, len = z.length();
    for(i = 0 ;  i<len ; i++)
    {
        if(current_state == 0)
        {
            state0(z[i]);
        }
        else if(current_state == 1)
        {
            state1(z[i]);
        }
        else{
            return 0;
        }
    }
    if(current_state ==1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int Iskeyword(string z)
{
    if(z =="auto" || "break" || "case" || "char" || "continue" || "long"||"do"||"return"||"unsigned")
    {
        return 1;
    }
}
int main()
{
    string a;
    int w;
    cout<<"Enter a string";
    cin>>a;
    w = Iskeyword(a);
    if(w == 1)
    {
        current_state = -1;
    }
    else{
        current_state = DFA_for_Identifier(a);
        }

    if(current_state == -1)
    {
        cout<<a<<":"<<"Valid Identifier"<<endl;
    }
    else{
        cout<<a<<":"<<"Valid Identifier"<<endl;
    }
    return 0;
}


