#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>edges)
{
    // The idea is to find a node whose degree is n-1
    int n = edges.size()+1;
    vector<int> degree(n+1,0);
    int center_node = -1;
    for(auto e:edges)
    {
        degree[e[0]]++;
        degree[e[1]]++;
        if(degree[e[0]]==n-1)
        {
            center_node=e[0];
            break;
        }
        if(degree[e[1]]==n-1)
        {
            center_node=e[1];
            break;
        }
    }
    return center_node;
        
}