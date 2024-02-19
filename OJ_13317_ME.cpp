#include<bits/stdc++.h>
using namespace std;

class People
{
    public:
        int height;
        int position;
        People(int h, int p)
        {
            height = h;
            position = p;
        }
};

class Stack
{
    public:
        int top;
        People *stack[100000];
        
        Stack()
        {
            top = -1;
        }

        bool IsEmpty()
        {
            if(top==-1)
                return true;
            else
                return false;
        }

        People* Top()
        {
            if(IsEmpty())
                return NULL;
            return stack[top];
        }

        void Push(People* p)
        {
            top = top + 1;
            stack[top] = p;
        }

        void Pop()
        {
            if(!IsEmpty()) top = top - 1;
        }
};

int main()
{
    int num;
    cin >> num;
    int cm;
    Stack *my_stack = new Stack();
    for (int i = 1; i <= num;i++)
    {
        cin >> cm;
        if(my_stack->IsEmpty())
            cout << 0;
        else if(cm > my_stack->Top()->height)
            cout << my_stack->Top()->position;
        else
        {
            while(!my_stack->IsEmpty())
            {
                my_stack->Pop();
                if(my_stack->IsEmpty())
                {
                    cout << 0;
                    break;
                }
                if(my_stack->Top()->height<cm)
                {
                    cout << my_stack->Top()->position;
                    break;
                }
            }
        }
        People *p = new People(cm, i);
        my_stack->Push(p);
        cout << ' ';
    }
    cout << '\n';
}
