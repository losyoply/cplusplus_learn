#include<iostream>
#include <deque>
using namespace std;
std::deque<int> D,A;
int main()
{    
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
    int N;
    int num;
    while(cin>>N)
    {
        for (int i = 0; i < N;i++)
        {
            cin >> num;
            D.push_back(num);
        }
        while(!D.empty())
        {
            if(abs(D.front())>abs(D.back()))
            {
                A.push_front(D.front());
                D.pop_front();
            }
            else if(abs(D.front())<=abs(D.back()))
            {
                A.push_front(D.back());
                D.pop_back();
            }
        }
        for (int i = 0; i < N;i++)
        {
            if(i!=N-1)cout << A[i] << ' ';
            else
                cout << A[i];
        }
        cout << endl;
    }
}