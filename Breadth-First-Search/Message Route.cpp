#include<bits/stdc++.h>
using namespace std;
// Apply simple bfs to find the shortest path
int messageRoute(int n, vector<vector<int>>edges)
{   
    vector<int> g[n+1];
    for(auto e:edges)
    {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    queue<int> q;
    vector<bool> vis(n+1,false);
    q.push(1);
    vis[1]=true;
    int t = 1;
    while(!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
            int a = q.front();
            q.pop();
            if(a==n)return t;
            for(int u:g[a])
            {
                if(!vis[u])
                {
                    q.push(u);
                    vis[u]=true;
                }
            }
        }
        t+=1;
    }
    return -1;
    
}