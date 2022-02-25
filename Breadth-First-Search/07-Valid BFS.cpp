#include<bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> seq , vector<vector<int>> edges)
{
 // first step is make graph
 vector<vector<int>> g(n+1);
 for(auto e:edges)
 {
     g[e[0]].push_back(e[1]);
     g[e[1]].push_back(e[0]);
 }
 
 // do a bfs
 // check if the childrens are present in the sequence or not;
 queue<int> q;
 vector<bool> vis(n+1,false);
 q.push(1);
 vis[1]=true;
 int j = 1;
 while(!q.empty())
 {
     int u = q.front();
     q.pop();
     set<int> s;
     
     for(auto v:g[u])
     {
         if(vis[v]==false)
         {
             vis[v]=true;
             s.insert(v);
         }
     }
     
     int val = 0;
     int sz = s.size();
     while(val<sz)
     {
         if(s.find(seq[j])==s.end())return false;
         q.push(seq[j]);
         j++;
         val++;
     }
     
 }
 return true;
}
int main()
{
	int n,a;
	int m;
	cin>>n>>m;
	vector<vector<int>> edges;
	for(int i=0;i<m;i++)
	{
		int a1,b;
		cin>>a1>>b;
		vector<int> v2={a1,b};
		edges.push_back(v2);
	}
	cin>>m;
	vector<int> v;
	for(int i=0;i<m;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	cout<<validBfs(n,v,edges);
}