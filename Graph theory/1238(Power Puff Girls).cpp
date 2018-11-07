#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
char graph[1000][1000];
int r,c;
int level[1000][1000];
int visited[1000][1000];
void bfs(int x,int y)
{
    for(int i=0; i < r; i++){
        for(int j = 0; j < c; j++) {
            level[i][j]=INT_MAX;
            visited[i][j]=0;
        }
    }
    queue<pii>q;
    q.push(pii(x,y));
    visited[x][y]=1;
    level[x][y]=0;
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        int x=top.first;
        int y=top.second;
        if(graph[x][y]=='h')
        {
            return;
        }
        //cout<<"("<<top.first<<","<<top.second<<")   ";
        for(int k=0; k<4; k++)
        {
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            if(tx>=0 and tx<r and ty>=0 and ty<c and graph[tx][ty]!='#'and graph[tx][ty]!='m' and visited[tx][ty]==0)
            {
                level[tx][ty]=min(level[x][y]+1,level[tx][ty]);
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
    for(int k=1; k<=t; k++)
    {
        int ax,ay,cx,cy,bx,by,hx,hy;
        cin>>r>>c;
        for(int i=0; i<r; i++)
        {
            cin>>graph[i];
        }

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(graph[i][j]=='a')
                {
                    ax=i;
                    ay=j;
                }
                if(graph[i][j]=='b')
                {
                    bx=i;
                    by=j;
                }
                if(graph[i][j]=='c')
                {
                    cx=i;
                    cy=j;
                }
                if(graph[i][j]=='h')
                {
                    hx=i;
                    hy=j;
                }
            }
        }
        ll a,b,C;

        bfs(ax,ay);
        a=level[hx][hy];
        bfs(bx,by);
        b=level[hx][hy];
        bfs(cx,cy);
        C=level[hx][hy];
        cout<<"Case "<<k<<": "<<max(max(a,b),C)<<endl;
        for(int i=0;i<r;i++)
        memset(graph[i],0,sizeof(graph[i]));
    }
}
