#include <iostream>
#include <stack>

using namespace std;

struct queue
{
    stack<int> s1; //for enqueue
    stack<int> s2; //for dequeue
};

struct queue q;

void enqueue(int x)
{
    cout<<"Pushing "<<x<<" in stack s1"<<"\n"; 
    q.s1.push(x);
    cout<<"Top of s1 is "<<q.s1.top()<<"\n";
}

void dequeue()
{
    if(!q.s2.empty())
    {
        cout<<"Front element in queue is "<<q.s2.top()<<"\n";
        q.s2.pop();
    }
    else
    {
        if(q.s1.empty())
        {
            cout<<"Both stacks are empty"<<"\n";
            return;
        }
        while(!q.s1.empty())
        {
            cout<<q.s1.top()<<" trasferred to s2"<<"\n";
            q.s2.push(q.s1.top());
            q.s1.pop();
        }
        cout<<"Front Element in queue is "<<q.s2.top()<<"\n";
        q.s2.pop();
    }
}

int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    
    return 0;
}
