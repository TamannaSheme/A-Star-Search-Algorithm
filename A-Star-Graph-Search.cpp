#include<bits/stdc++.h>
using namespace std;

int n,e,dest;

vector <int> adj[100105];
vector <int> adjw[100105];
int dis[100105];
int H[100105];
int F[100105];
int par[100105];
int path[100105];


queue <int> q;

void bfs(int s)
{
    dis[s] = 0;
    F[s] = 0+H[s];
    par[s] = s;
    q.push(s);

    int u,v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for (int i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            if(v == dest)
            {
                dis[v] = dis[u]+adjw[u][i];
                if(F[v]>dis[v]+H[v])
                {
                    F[v] = dis[v]+H[v];
                    par[v] = u;
                }
            }
            else
            {
                if(dis[v] == -1)
                {
                    q.push(v);
                    dis[v] = dis[u]+adjw[u][i];
                    if(F[v]>dis[v]+H[v])
                    {
                        F[v] = dis[v]+H[v];
                        par[v] = u;
                    }
                }

            }
        }

    }
}


int main()
{
    scanf("%d %d",&n, &e);
    int u, v, w;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adjw[u].push_back(w);
    }

    cout<<"Enter H:";
    int h;
    for(int i=1; i<=n; i++)
    {
        cin>>h;
        H[i] = h;
    }
    for(int i=0; i<=n; i++)
    {
        dis[i] = -1;
        F[i] = 99999;
    }

    int s;
    cout<<"Enter source:";
    scanf("%d",&s);
    cout<<"Enter destination:";
    cin>>dest;

    bfs(s);
    cout<<"Distance from source: "<<dis[dest]<<endl;

    int current = dest;
    int cnt = 0;
    while(current!=s)
    {
        path[cnt] = current;
        current = par[current];
        cnt++;
    }
    path[cnt] = current;

    cout<<"Path from "<<s<<" to "<<dest<<": ";
    for(int i=cnt; i>0; i--)
    {
        cout<<path[i]<<"->";
    }
    cout<<path[0];

}
