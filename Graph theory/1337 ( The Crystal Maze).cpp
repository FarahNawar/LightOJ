#include<bits/stdc++.h>
using namespace std;
char graph[505][505];
bool visited[505][505];
int Crystal[505][505];
int Count,r,c,q;
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
void dfs(int x,int y)
{
    if(graph[x][y]=='C')
        Count++;
    visited[x][y]=true;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<r && ny>=0 && ny<c && graph[nx][ny]!='#' && !visited[nx][ny])
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int z=1; z<=t; z++)
    {
        scanf("%d %d %d",&r,&c,&q);

        for(int i=0; i<r; i++)
            scanf("%s",graph[i]);
        memset(Crystal,-1,sizeof(Crystal));
        int sx,sy;
        printf("Case %d:\n",z);
        while(q--)
        {
            Count=0;
            memset(visited,false,sizeof(visited));
            scanf("%d %d",&sx,&sy);
            if(Crystal[sx-1][sy-1]==-1)
            {
                dfs(sx-1,sy-1);
                Crystal[sx-1][sy-1]=Count;
                printf("%d\n",Count);
                for(int i=0; i<r; i++)
                    for(int j=0; j<c; j++)
                        if(visited[i][j])
                            Crystal[i][j]=Count;
            }
            else
                printf("%d\n",Crystal[sx-1][sy-1]);
        }

    }
    return 0;
}

