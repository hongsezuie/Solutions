#include "minstack.h"

MinStack::MinStack()
{

}

MinStack::~MinStack()
{

}

void MinStack::push(int x)
{
    MyRegularStack.push(x);

    topIndex++;

    if(MyMinIndexStack.size()==0)
    {
        MyMinIndexStack.push(0);
        MyMinValueStack.push(x);
    }
    else
    {
        if(x<MyMinValueStack.top())
        {
            MyMinIndexStack.push(topIndex);
            MyMinValueStack.push(x);
        }
    }
}

void MinStack::pop()
{
    if(topIndex==MyMinIndexStack.top())
    {
        MyRegularStack.pop();

        topIndex--;

        MyMinIndexStack.pop();
        MyMinValueStack.pop();
    }
    else
    {
        MyRegularStack.pop();
        topIndex--;
    }
}

int MinStack::top()
{
    return MyRegularStack.top();
}

int MinStack::getMin()
{
    return MyMinValueStack.top();
}
