#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

bool checktopelement(char a , char s)
{
    if(a==')')
        return s=='('?true:false;
    else if(a=='}')
        return s=='{'?true:false;
    else if(a==']')
        return s=='['?true:false;
}

bool checkbalance(char a[])
{
    int length = strlen(a);
    stack<char> s;
    for(int i=0;i<length;i++)
    {
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
        {
            cout<<"pushing"<<a[i]<<"\n";
            s.push(a[i]);
        }
        else if(a[i]==')' || a[i]=='}' || a[i]==']')
        {
            if(s.empty() || !checktopelement(a[i],s.top()))
                return false;
            else
            {
                s.pop();
            }
        }
    }
    return true;
}

int main()
{
    bool status;
    char a[20];
    cout<<"Enter expression"<<"\n";
    cin>>a;
    status = checkbalance(a);
    if(status)
        cout<<"expression is balanced"<<"\n";
    else
        cout<<"expression is not balanced"<<"\n";
    return 0;
}
    
