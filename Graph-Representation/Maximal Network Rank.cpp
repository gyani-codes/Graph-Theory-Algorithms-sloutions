#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> roads) {
    
        vector<vector<int>> v(n,vector<int>(n,0));
        vector<int> v1(n,0);
        for(auto& i:roads)
        {
            v1[i[0]]+=1;
            v1[i[1]]+=1;
            // v[i[0]][i[1]]=-1;
        }
        int mx = -1;
        for(auto& i:roads)
        {
            v[i[0]][i[1]]= v1[i[0]]+v1[i[1]]-1;
            v[i[1]][i[0]]=v[i[0]][i[1]];
            mx = max(mx,v[i[0]][i[1]]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j and v[i][j]==0)
                {
                    v[i][j]=v1[i]+v1[j];
                    mx=max(mx,v[i][j]);
                    // cout<<i<<" "<<j<<" "<<v[i][j]<<endl;

                }
            }
        }
        return mx;

}