#include<bits/stdc++.h>

using namespace std;
 vector<vector<int>>g(100005);
 vector<bool>vis(100005,false);
 
 void dfs(int src)
 {
     vis[src] = true;
     
     for(int x : g[src])
     if(vis[x] == false)
     dfs(x);
     
 }
 int main()
 {
     int v,e;
     
     cin>>v>>e;
     
     for(int i=0;i<e;i++)
     {
         int a,b;
         cin>>a>>b;
         
         g[a].push_back(b);
         g[b].push_back(a);
     }
     int cc=0;
     vector<int>comp(100005);
     for(int i=1;i<=v;i++)
     {
         if(vis[i] == false)
         {
             dfs(i);
             cc++;
             comp[cc] = i;  //assigning a city to each connected component
         }
     }
     
     cout<<(cc-1)<<endl;
     if(cc>1)
     {
         for(int i=2;i<=cc;i++)
          cout<<comp[1]<<" "<<comp[i]<<endl;
     }
     return 0;
 }
