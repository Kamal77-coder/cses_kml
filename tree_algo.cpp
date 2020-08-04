//subordinates 

//Given the structure of a company, your task is to
//calculate for each employee the number of their subordinates.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>dp;
int n;
void dfs(int src)
{
    dp[src] = 1;
    
    for(int child : g[src])
    {
        dfs(child);
        
        dp[src] = dp[src] + dp[child];
    }
}
void solve()
{
    dfs(1);
    
    for(int i= 1;i<=n ;i++)
      cout<<--dp[i]<<" "; //we have to exclude the individual employee in subordinate  count
    //number of subordinates are equal to number of nodes in subtree of a node -1 
}
void set1()
{
    cin>>n;
    dp.assign( n+1 ,0);
    g.assign(n+1,{});
    
    for(int i= 2;i<=n ;i++)
    {
        int a;
        cin>>a;
        
        g[a].push_back(i);
    }
    solve();
}
int main()
{
    set1();
}
