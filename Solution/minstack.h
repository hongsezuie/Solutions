#ifndef MINSTACK_H
#define MINSTACK_H
#include <vector>
#include <stack>

class MinStack
{

    public:
        MinStack();

        ~MinStack();

        int topIndex=-1;

        std::stack<int> MyMinIndexStack;

        std::stack<int> MyMinValueStack;

        std::stack<int> MyRegularStack;

        void push(int x);


        void pop();


        int top();


        int getMin();



};

#endif // MINSTACK_H
