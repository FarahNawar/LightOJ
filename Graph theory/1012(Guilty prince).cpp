#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
char graph[1000][1000];
int r,c;
int Count=0;
int visited[1000][1000];
void bfs(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    visited[x][y]=1;
    while(!q.empty())
    {

        pii top=q.front();
        q.pop();
        //cout<<"("<<top.first<<","<<top.second<<")   ";
        Count++;
        for(int k=0;k<4;k++)
        {
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            if(tx>=0 and tx<r and ty>=0 and ty<c and graph[tx][ty]=='.' and visited[tx][ty]==0)
            {
                visited[tx][ty]=1;
                q.push(pii(tx,ty));
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int sourcex,sourcey;
    cin>>c>>r;
    for(int i=0; i<r; i++)
    {
         cin>>graph[i];
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(graph[i][j]=='@')
            {
                sourcex=i;
                sourcey=j;
            }
        }
    }
    bfs(sourcex,sourcey);
    cout<<"Case "<<k<<": "<<Count<<endl;
    for(int i=0;i<r;i++)
        memset(graph[i],0,sizeof(graph[i]));
    memset(visited,0,sizeof(visited));
    Count=0;
    }


}
