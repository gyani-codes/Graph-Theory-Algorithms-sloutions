#include
using namespace std;

int minTrioDegree(int n, vector&gt; edges) {
 vector&gt; v(n+1,vector(n+1,0));
 vector v1(n+1,0);
 for(auto e:edges)
 {
     v[e[0]][e[1]]=1;
     v[e[1]][e[0]]=1;
     v1[e[0]]+=1;
     v1[e[1]]+=1;
 }
 int mn = 500;
 for(int i=0;i&lt;=n;i++)
 {
     for(int j=i+1;j&lt;=n;j++)
     {
         for(int k=j+1;k&lt;=n;k++)
         {
             if(i!=j and j!=k and i!=k)
             {
                 if(v[i][j]==1 &amp;&amp; v[j][k]==1 &amp;&amp; v[i][k]==1)
                 {
                     mn=min(mn,v1[i]+v1[j]+v1[k]-6);
                 }
             }
         }
     }
 }
 return mn==500 ? -1 : mn;
}