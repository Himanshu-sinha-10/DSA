#include <iostream>
using namespace std;


void doDFS(int** edges,int V,int sv,bool* visited)
{
    visited[sv]=true;
    for(int i=0;i<V;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1 && !visited[i])
            doDFS(edges,V,i,visited);
    }
}


bool isConnected(int** edges ,int V)
{
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    doDFS(edges,V,0,visited);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            return false;
    }
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int** edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        edges[i][j]=0;
    }
    
    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool ans=isConnected(edges,V);
    if(ans)
        cout<<"true";
    else cout<<"false";

  return 0;
}