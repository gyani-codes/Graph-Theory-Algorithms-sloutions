#include<bits/stdc++.h>
using namespace std;
void dfs(int s,vector<vector<int>>& g,vector<int>& vis)
{
    vis[s]=true;
    for(auto v:g[s])
    {
        if(vis[v]==false)
        {
            dfs(v,g,vis);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>> rooms) {
   int n = rooms.size();
   vector<int> vis(n,false);
  dfs(0,rooms,vis);
   for(auto i:vis)
   {
       if(i==false)return false;
   }
   return true;
}