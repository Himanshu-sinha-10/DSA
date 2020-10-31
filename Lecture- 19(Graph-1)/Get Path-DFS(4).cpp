#include <iostream>
#include<vector>

using namespace std;

vector<int>* getPathHelper(int** edges,int V,int sv,int ev,bool* visited)
{
    if(sv==ev)
    {
        vector<int>* v= new vector<int>();
        v->push_back(ev);
        return v;
    }
    vector<int>* op=NULL;
    visited[sv]=true;
    for(int i=0;i<V;i++)
    {
        if(i==sv)
        continue;
        
        if(edges[sv][i]==1 && !visited[i])
        {
             op=getPathHelper(edges,V,i,ev,visited);
            if(op!=NULL)
            {
                op->push_back(sv);
              return op;
            }

        }
        
    }
    return op;
}


vector<int>* getPath(int** edges,int V,int sv,int ev)
{
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    
    vector<int>* ans=getPathHelper(edges,V,sv,ev,visited);
    delete [] visited;
    return ans;
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
    int sv,ev;
    cin>>sv>>ev;
    vector<int>* v=getPath(edges,V,sv,ev);
    if(v!=NULL)
    for(int i=0;i<v->size();i++)
        cout<<v->at(i)<<" ";
    

  return 0;
}