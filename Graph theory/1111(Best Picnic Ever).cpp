#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>graph[10000];
int visited[10000];
ll check[100000];
void dfs(int source)
{
    check[source]++;
    visited[source]=1;
    for(int i=0;i<graph[source].size();i++)
    {
        if(visited[graph[source][i]]==0)
        {
            visited[graph[source][i]]=1;
            dfs(graph[source][i]);
        }
    }
}
int main()
{

  ll testcase;
  cin>>testcase;

  for(int i=1;i<=testcase;i++)
  {
      ll people,house,road;
      cin>>people>>house>>road;
      ll H[103];
      for(int j=1;j<=people;j++)
          cin>>H[j];
      for(int j=1;j<=road;j++)
      {
          ll u,v;
          cin>>u>>v;
          graph[u].push_back(v);
      }
      for(int j=1;j<=people;j++)
      {
          memset(visited,0,sizeof(visited));
          dfs(H[j]);
      }
      ll Count=0;
      for(int j=1;j<=house;j++)
      {
          if(check[j]==people)
            Count++;
      }
      cout<<"Case "<<i<<": "<<Count<<endl;
      memset(check,0,sizeof(check));
      memset(graph,0,sizeof(graph));
  }
}
