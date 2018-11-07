#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define boundary(i,j) (i>=0 and i<r and j>=0 and j<c)
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int r,c;
char graph[1000][1000];
ll dist[1000][1000];
int visited[1000][1000];
map<char,pii>position;
char node1;
char node2;
int Distance=0;
void bfs(int x,int y)
{
    for(int i=0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            dist[i][j]=INT_MAX;
            visited[i][j]=0;
        }
    }
    queue<pii>q;
    q.push(pii(x,y));
    visited[x][y]=1;
    dist[x][y]=0;
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        int x=top.first;
        int y=top.second;
        if(graph[x][y]==node2)
        {
            Distance=dist[x][y];
            graph[x][y]='.';
            return;
        }
        for(int k=0; k<4; k++)
        {
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            if(boundary(tx,ty) and (graph[tx][ty]=='.'||graph[tx][ty]==node2) and visited[tx][ty]==0)
            {
                dist[tx][ty]=min(dist[x][y]+1,dist[tx][ty]);
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
    for(int z=1; z<=t; z++)
    {
        getchar();
        int n;
        cin>>n;

        r=n;
        c=n;
        int k=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]!='.' and graph[i][j]!='#')
                {
                    k++;
                    position[graph[i][j]]=make_pair(i,j);
                }

            }
        }
        node2='A';
        int x=position[node2].first;
        int y=position[node2].second;
        graph[x][y]='.';
        Distance=0;
        dist[x][y]=0;
        int sum=0;
        int flag=-1;
        int i;
        for(i=1; i<k; i++)
        {
            node1=node2;
            node2++;
            int x=position[node1].first;
            int y=position[node1].second;
            bfs(x,y);
            if(Distance==0)
            {
                flag==0;
                break;
            }
            //cout<<"\nDistance of "<<node1<<" and "<<node2<<" is "<<Distance<<endl<<endl;
//            for(int i=0;i<n;i++)
//            {
//                for(int j=0;j<n;j++)
//                    cout<<dist[i][j]<<"   ";
//                cout<<endl;
//            }
            sum+=Distance;
            Distance=0;
        }
        //cout<<" i "<<i<<endl;
        if(flag==0||i!=k)
            cout<<"Case "<<z<<": Impossible"<<endl;
        else
        cout<<"Case "<<z<<": "<<sum<<endl;
    }



}

