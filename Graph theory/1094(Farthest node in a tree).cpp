#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
vector<pii>Graph[30000];
int visited[30000];
int level[300000];
int bfs(int source)
{
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    queue<int>q;
    q.push(source);
    visited[source]=1;
    level[source]=0;
    while(!q.empty())
    {
        int u=q.front();
      //  cout<<u<<" ";
        q.pop();
        for(int i=0;i<Graph[u].size();i++)
        {
            if(!visited[Graph[u][i].second])
            {
                level[Graph[u][i].second]=level[u]+Graph[u][i].first;

                   //maxcost=level[Graph[u][i].first];
                 //  maxnode=Graph[u][i].second;
                visited[Graph[u][i].second]=1;
                q.push(Graph[u][i].second);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
          int nodes;
     cin>>nodes;
    for(int i=0;i<nodes-1;i++)
   {
       int source,destination,weight;
       cin>>source>>destination>>weight;
       Graph[source].push_back(make_pair(weight,destination));
       Graph[destination].push_back(make_pair(weight,source));
   }
   bfs(0);
   ll maxcost=0;
   ll maxnode=0;
   for(int i=0;i<nodes;i++)
   {
       if(level[i]>maxcost)
       {
           maxcost=level[i];
           maxnode=i;
       }
   }
   bfs(maxnode);
   maxcost=0;

   for(int i=0;i<nodes;i++)
   {
       if(level[i]>maxcost)
       {
           maxcost=level[i];
           maxnode=i;
       }
   }
   printf("Case %d: %d\n",j,maxcost);
   //cout<<maxnode<<endl;
   for(int i=0;i<nodes;i++)
   {
       Graph[i].clear();
   }
    }

}
