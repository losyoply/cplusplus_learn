#include<iomanip>
#include<iostream>
#include <vector>
#include <set>
#include<tuple>
#include <queue>
#include <cstring>
using namespace std;
double prob = 0;
vector<pair<int, double>> Nodes[505]; //next//p
void FIND(int S, int E)
{
    if(S==E) 
    {
        cout<<"1.00000"<<endl;
        return;
    }
    queue< tuple<int, double, set<int> > > Q; //now//now_p//visited
    set<int> visited = {S};
    tuple<int, double, set<int>> tu = make_tuple(S, 1, visited);
    Q.push(tu);
    while(!Q.empty())
    {
        int now = get<0>(Q.front());
        double now_p = get<1>(Q.front());
        set<int> now_visited = get<2>(Q.front());
        Q.pop();

        for (auto next : Nodes[now])
        {
            if(now_visited.find(next.first)!=now_visited.end())
                continue;
            if(now_p*next.second <prob)
                continue;
            if(next.first==E)
            {
                prob = max(prob, next.second * now_p);
            }
            else
            {
                visited = now_visited;
                visited.insert(next.first);
                Q.push(make_tuple(next.first, now_p*next.second, visited));
            }
        }
    }
    cout<<fixed<< setprecision(5)<<prob<<endl;
    prob = 0;
}
int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    int a, b;
    double p;
    int S, E;
    for (int i = 0; i < m;i++)
    {
        cin >> a >> b >> p;
        Nodes[a].push_back({b, p});
        Nodes[b].push_back({a, p});
    }
    for (int i = 0; i < r;i++)
    {
        cin >> S >> E;
        FIND(S, E);
    }
    return 0;
}