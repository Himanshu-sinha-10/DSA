#include <iostream>
#include<climits>
using namespace std;


int findminvertex(int* distance,bool* visited,int V)
{
    int minvertex=-1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] &&(minvertex== -1 || distance[i]<distance[minvertex]))
            minvertex=i;
    }
    return minvertex;
}
void dikstra(int** edges,int V)
{
    bool* visited=new bool[V];
    int* distance=new int[V];
    
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<V-1;i++)
    {
        int minvertex=findminvertex(distance,visited,V);
        visited[minvertex]=true;
        for(int j=0;j<V;j++)
        {
            if(edges[minvertex][j]!=0 && !visited[j])
            {
                int dist=distance[minvertex]+edges[minvertex][j];
                if(dist<distance[j])
                    distance[j]=dist;
            }
        }
    }
    
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
}
int main()
{
  int V, E;
  cin >> V >> E;

 int** edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    
    for(int i=0;i<E;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    
    dikstra(edges,V);
    for(int i=0;i<V;i++)
        delete [] edges[i];
    delete [] edges;

  return 0;
}