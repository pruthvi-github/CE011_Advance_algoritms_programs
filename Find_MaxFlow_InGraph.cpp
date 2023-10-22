#include <iostream>
#include <queue> 
#include<limits.h>
#include<algorithm>
using namespace std;
const int n=6;
bool bfs(int rgraph[n][n],int s,int t,int parent[n])
{   
    int visited[n];
    for(int i=0;i< n;i++)
    {
         visited[i] = 0;
    }
    queue<int> q1;
    q1.push(s);
    visited[s] = 1;
    parent[s] = -1;
    while(!q1.empty())
    {
        int u = q1.front();
        q1.pop();
        for(int v=0;v<n;v++)
        {
          if(visited[v]==0 && rgraph[u][v]>0)
          {
            if(v==t)
            {
                parent[v]=u;
                return true;
            }
            q1.push(v);
            visited[v] = 1;
            parent[v] = u;
          }    
        }
    }
    return false;   
}
int fordfulkerson(int g[n][n],int s,int t)
{
    int rgraph[6][6];
    for(int u=0;u<n;u++)
    {
        for(int v=0;v<n;v++)
        {
            rgraph[u][v] = g[u][v];
        }
    }
    int parent[n];
    int max_flow = 0;
    while(bfs(rgraph,s,t,parent))
    {
        int path_flow = INT_MAX;
        for(int v=t;v!=s;v=parent[v])
        {
            int u = parent[v];
            path_flow = std::min(path_flow,rgraph[u][v]);
        }
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
   return max_flow; 
}
int main()
{
    int g[6][6] = { {0,16,13,0,0,0},
                    {0,0,10,12,0,0},
                    {0,4,0,0,14,0},
                    {0,0,9,0,0,20},
                    {0,0,0,7,0,4},
                    {0,0,0,0,0,0} };
                    
                    
    int max_flow = fordfulkerson(g,0,5); 
    cout << max_flow;

    return 0;
}