#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dist[1004];
int visited[1004];
#define inf INT_MAX
vector<int>graph[1004];
int dist2[1004];
int house,road;
void bfs1(int src)
{
    for(int i=0;i<=1000;i++)
    {
        visited[i]=0;
        dist[i]=0;
    }
    queue<int>q;
    q.push(src);
    visited[src]=1;
    dist[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            if(visited[graph[u][i]]==0)
            {
                dist[graph[u][i]]=dist[u]+1;
                visited[graph[u][i]]=1;
                q.push(graph[u][i]);
            }
        }
    }
}
void bfs2(int src)
{
    for(int i=0;i<=1000;i++)
    {
        visited[i]=0;
        dist2[i]=0;
    }
    queue<int>q;
    q.push(src);
    visited[src]=1;
    dist2[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            if(visited[graph[u][i]]==0)
            {
                dist2[graph[u][i]]=dist2[u]+1;
                visited[graph[u][i]]=1;
                q.push(graph[u][i]);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {

        cin>>house>>road;
        for(int j=1;j<=road;j++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int source,destination;
        cin>>source>>destination;
        bfs1(source);
        bfs2(destination);
//        for(int j=0;j<=house;j++)
//        cout<<dist[j]<<" ";
        ll maxdist=0;
        for(int j=0;j<house;j++)
        {
            ll Distance=dist[j]+dist2[j];
                if(Distance>maxdist)
                {
                    maxdist=Distance;
                }
        }
        cout<<"Case "<<i<<": "<<maxdist<<endl;
        for(int i=0;i<=1000;i++)
        graph[i].clear();
    }
}
