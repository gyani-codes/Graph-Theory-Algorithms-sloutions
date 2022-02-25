#include<bits/stdc++.h>
using namespace std;
// The trickiest part in this problem is to create a graph,
// once you construct a graph then simple apply bfs to solve the problem
int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    
        unordered_map<int,int> s,l;
        for(auto i:snakes)
        {
            s[i.first]=i.second;
        }
        for(auto i:ladders)
        {
            l[i.first]=i.second;
        }
        vector<bool> vis(n+1,false);
        queue<int> q;
        q.push(1);
        vis[1]=true;
        int t = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--){
            int a = q.front();
            q.pop();
            if(a==n)
            {
                return t;
            }
            for(int i=1;i<=6;i++)
            {
                int b = a + i;
                if(vis[b])continue;
                if(l.find(b)!=l.end())
                {
                    if(vis[l[b]]==false)
                    q.push(l[b]);
                    vis[l[b]]=true;
                }
                else if(s.find(b)!=s.end())
                {
                    if(vis[s[b]]==false)
                    q.push(s[b]);
                    vis[s[b]]=true;   
                }
                else{
                    q.push(b);
                    vis[b]=true;
                }
            }}
            t+=1;
        }
        return -1;
}
