#include<bits/stdc++.h>
using namespace std;
typedef struct matrix
{
    unsigned long long n, m, s;
    char name;
    matrix()
    {
        n = 0;
        m = 0;
        name = '\0';
    }
} matrix;
class Stack
{
    public:
        int top;
        matrix stack[1000];
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
        matrix Top()
        {
            if(IsEmpty())
                return matrix();
            return stack[top];
        }
        void Push(matrix p)
        {
            top = top + 1;
            stack[top] = p;
        }
        void Pop()
        {
            if(!IsEmpty()) top = top - 1;
        }
};
matrix arr[30];
unsigned long long sum(string str)
{
    Stack *sta = new Stack();
    int len = str.length();
    unsigned long long ans=0;
    for (int i = 0; i < len;i++)
    {
        if(str[i]=='(')
            continue;
        else if(str[i]==')')
        {
            matrix pop2 = sta->Top();
            sta->Pop();
            matrix pop1 = sta->Top();
            sta->Pop();
            if(pop1.m==pop2.n) ans += pop1.n * pop1.m * pop2.m;
            else
                return -1;
            matrix topush = matrix();
            topush.n = pop1.n;
            topush.m = pop2.m;
            sta->Push(topush);
        }
        else
        {
            matrix m = matrix();
            m.n = arr[str[i]-65].n;
            m.m = arr[str[i]-65].m;
            m.name = arr[str[i]-65].name;
            sta->Push(m);
        }
    }

    return ans;
}



int main()
{
    int t;
    char c;
    unsigned long long int n ,m;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> c >> n >> m;
        matrix a = matrix();
        a.n = n; a.m = m; a.name = c;
        arr[c-65] = a;
    }
    int q;
    cin >> q;
    string str;
    for (int i = 0; i < q;i++)
    {
        cin >> str;
        unsigned long long ans = sum(str);
        if(ans != -1)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
    return 0;
}
