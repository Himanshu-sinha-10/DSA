#include<vector>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void doDFS(int** edges,int V,int sv,vector<int> & v,bool* visited)
{
    visited[sv]=true;
    v.push_back(sv);
    for(int i=0;i<V;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1 && !visited[i])
        {
            doDFS(edges,V,i,v,visited);
        }
    }
    
}

int main()
{
  int V, E;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
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
    
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    vector<vector<int> > vec;
    vector<int> v;
    int j=0;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            doDFS(edges,V,i,v,visited);
        }
        sort(v.begin(),v.end());
        vec.push_back(v);
        v.clear();
    }
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
  return 0;
}