#include <iostream>
using namespace std;
bool hasPathhelper(int** edges,int V,int sv,int ev,bool* visited)
{
    visited[sv]=true;
    bool ans=false;
    for(int i=0;i<V;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1 && i==ev && !visited[i])
            return true;
        else if(!visited[i] && edges[sv][i]==1) 
        {
            ans=hasPathhelper(edges,V,i,ev,visited);
            if(ans)
                return true;
        }
        
    }
    return ans;
}

bool hasPath(int** edges,int V,int sv,int ev)
{
    if(sv==ev)
        return true;
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    bool ans= hasPathhelper(edges,V,sv,ev,visited);
    delete [] visited;
    return ans;
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
    int sv,ev;
    cin>>sv>>ev;
    bool ans=hasPath(edges,V,sv,ev);
    if(ans)
        cout<<"true";
    else cout<<"false";

  return 0;
}