#include<iostream>
#include<string.h>
#define max 100
using namespace std;
char symbol[max];
int top;
int curr_state = 0;
void push(char ch)
{
    if(top < (max-1))
    {
        top++;
        symbol[top] = ch;
    }
    else
    {
        cout<<"stack is full \n";
    }
}

void pop()
{
    char item;
    if(top > -1)
    {
        item = symbol[top];
        top--;
    }
    else
    {
        cout<<"stack is empty";
    }
}

char get_stack_top()
{
    return (symbol[top]);
}

int delta(char ch , char st_top)
{
    if(ch =='e' && st_top == 'e')
    {
        curr_state = 0;
        push('$');
    }
    else if (ch == '0' && (st_top == '$' || st_top == '0'))
    {
        curr_state = 0;
        push(ch);
    }
    else if (ch == '1' && (st_top == '$' || st_top == '1'))
    {
        curr_state = 0;
        push(ch);
    }
    else if (ch == '1' && st_top == '0' || ch == '0' && st_top =='1')
    {
        curr_state = 0;
        pop();
    }
    else if (ch == '\0' && st_top == '$')
    {
        curr_state = 0;
    }
    return curr_state;
}

int main()
{
    char input[20];
    top = -1;
    int i= 0,c=0;
    char ch = '6';
    char st_top = 'e';
    curr_state = delta(ch ,st_top);
    cout<<"Enter the string";
    cin>>input;
    ch = input[i];
    st_top = get_stack_top();
    while(c<= strlen(input))
    {
        curr_state = delta (ch,st_top);
        ch = input[++i];
        st_top = get_stack_top();
        c++;
    }
    if(symbol[top] == '$')
    {
        cout<<input<<"is rejected"<<endl;
    }
    else
    {
        cout<<input<<"is accepted";
    }
    return 0;
}