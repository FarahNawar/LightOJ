#include<bits/stdc++.h>
using namespace std;
int dx[]= {1,0,-1,0};
int dy[]= {0,-1,0,1};
int visited[20005];
vector<int>graph[20005];
int level[20005];
int Color[20005];
#define pii pair<int,int>
#define RED 1
#define BLACK 2
int r,c;
int nodes=0;

int bfs(int x)
{
    queue<int>q;
    q.push(x);
    int flag=-1;
     int R=0;
     int B=0;
    int clr=RED;
    Color[x]=clr;
    visited[x]=1;
    R++;
    while(!q.empty())
    {
        int u=q.front();
        nodes++;
        q.pop();
        if(Color[u]==RED)
            clr=BLACK;
        else if(Color[u]==BLACK)
            clr=RED;
        for(int i=0; i<graph[u].size(); i++)
        {
            if(visited[graph[u][i]]==0)
            {
                visited[graph[u][i]]=1;
                if(clr==RED)
                    R++;
                else if(clr==BLACK)
                    B++;
                //cout<<graph[u][i]<<" is being colored with "<<clr<<endl;
                Color[graph[u][i]]=clr;
                q.push(graph[u][i]);
            }
        }
    }
    return max(R,B);
}
int main()
{
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        int fight;
        cin>>fight;
        while(fight--)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int sum=0;
        for(int i=1;i<=20000;i++)
        {
           if(visited[i]==0&&graph[i].size()!=0)
           {
               sum+=bfs(i);
           }
        }
        printf("Case %d: %d\n",z,sum);
        memset(Color,0,sizeof(Color));
        memset(visited,0,sizeof(visited));
        memset(graph,0,sizeof(graph));
        sum=0;
    }


}
