#include<iostream>
#include <vector>
#include <set>
#include<tuple>
#include <queue>
#include <cstring>
using namespace std;
long long path = 9e10;
vector<pair<int, int>> Tunnel[20005], Bridge[20005];
queue< tuple<int, long long, int, set<int> > > Q;
int N, S, E;
int main()
{
    int T, B, v, u, w;
    cin >> N >> S >> E;
    cin >> T;
    for(int i = 0 ; i < T ; i++)
    {
        cin >> v >> u >> w;
        Tunnel[u].push_back({v, w});
        Tunnel[v].push_back({u, w});
    }
    cin >> B;
    for(int i = 0 ; i < B ; i++)
    {
        cin >> v >> u >> w;
        Bridge[u].push_back({v, w});
        Bridge[v].push_back({u, w});
    }
    
    //
    set<int> visited = {S};
    tuple<int, long long, int, set<int>> tu = make_tuple(S, 0, 0, visited);
    Q.push(tu);
    while(!Q.empty())
    {
        int now = get<0>(Q.front());
        long long now_length = get<1>(Q.front());
        int isB = get<2>(Q.front());
        set<int> now_visited = get<3>(Q.front());
        Q.pop();

        for (auto next : Tunnel[now])
        {
            if(now_visited.find(next.first)!=now_visited.end())
                continue;
            if(now_length+next.second >path)
                continue;
            if(next.first==E)
            {
                path = next.second+now_length;
            }
            else
            {
                visited = now_visited;
                visited.insert(next.first);
                Q.push(make_tuple(next.first, now_length+next.second, isB, visited));
            }
        }
        if(isB==1)
            continue;
        for (auto next : Bridge[now])
        {
            if(now_visited.find(next.first)!=now_visited.end())
                continue;
            if(now_length+next.second >path)
                continue;
            if(next.first==E)
            {
                path = next.second+now_length;
            }
            else
            {
                visited = now_visited;
                visited.insert(next.first);
                Q.push(make_tuple(next.first, now_length+next.second, 1, visited));
            }
        }
    }
    //
    cout << path << endl;
}