#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* weights, bool* visited, int V){

	int minVertex = -1;
	for(int i = 0; i < V; i++){
		if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}
void prims(int** edges,int V)
{
    int* parent=new int[V];
    int* weights=new int[V];
    bool* visited=new bool[V];
    
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        weights[i]=INT_MAX;
    }
    
    parent[0]=-1;
    weights[0]=0;
    
	for(int i = 0; i < V-1 ; i++){
		int minVertex = findMinVertex(weights, visited, V);
		visited[minVertex] = true;
		for(int j = 0; j < V; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weights[j]){
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	} 
    
    	for(int i = 1; i < V; i++){
		if(parent[i] < i){
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		}else{
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}
    // delete [] parent;
    // delete [] visited;
    // delete [] weights;
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
        int f;
        int s;
        int w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    
    prims(edges,V);
    for(int i=0;i<V;i++)
        delete [] edges[i];
    delete [] edges;

  return 0;
}