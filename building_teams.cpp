//==bipartite graph problem===================
#include<bits/stdc++.h>

using namespace std;
 vector<vector<int>>g(100005);
 vector<bool>vis(100005,false);
 vector<int>col(100005,-1);
 
 bool dfs(int src,int c)
 {
     col[src] = c;
     
    bool res = true;
     for(int x : g[src])
     {
        if(col[x]== -1 ) 
          res = res && dfs(x,!c);
        else if(col[x] == c)
        {
            return false;
        }
     }
     return res;
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
     bool res = true;
     for(int i=1;i<=v;i++)
     {
         if(col[i] == -1)
          res = res && dfs(i,0);
     }
     
     if(res == false)
     cout<<"IMPOSSIBLE";
     else
     {
         for(int i=1;i<=v;i++)
          cout<<(++col[i])<<" ";
     }
     return 0;
 }
