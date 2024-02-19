#include<iostream>
#include<set>
using namespace std;
void fu(set<int> ff)
{
    ff.erase(0);
}
int main()
{
    set<int> fuck = {0, 1, 2, 3};
    fu(fuck);
    for(auto a : fuck)
    {
        cout << a;
    }
}