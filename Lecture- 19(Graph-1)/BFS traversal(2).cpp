#include <iostream>
#include<queue>
using namespace std;


void printBFS(int** edges,int V,int sv,bool* visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        for(int i=0;i<V;i++)
        {
            if(i==current)
                continue;
            if(edges[current][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void BFS(int** edges,int V)
{
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    for(int i=0;i<V;i++)
    {
        if(visited[i]!=true)
            printBFS(edges,V,i,visited);
    }
    delete [] visited;
}

int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int** edges=new int*[V]; // adjency matrix
    for(int i=0;i<V;i++) 
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    
    for(int i=0;i<E;i++) // filling adjency matrix, making connections,taking inputs
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    BFS(edges,V);
    
    
    
    

  return 0;
}