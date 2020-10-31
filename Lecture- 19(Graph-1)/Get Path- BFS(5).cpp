#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

vector<int>* getPath(int** edges,int V,int sv,int ev,bool* visited)
{
    if(sv==ev)
    {
        vector<int>* v=new vector<int>();
        v->push_back(ev);
        return v;
    }
   queue<int> q;
   map<int,int> m;
    vector<int>* v=NULL;
    
   q.push(sv);
    visited[sv]=true;
    
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        int i;
        for(i=0;i<V;i++)
        {
            if(i==current)
                continue;
            if(edges[current][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
                m[i]=current;
                if(i==ev)
                {
                   v=new vector<int>();
                    v->push_back(ev);
                    while(i!=sv)
                    {
                        i=m[i];
                        v->push_back(i);
                    }
                }
            }
        }

    }
    return v;
    
    
}




int main()
{
  int V, E, tempX, tempY;
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
    {
        visited[i]=false;
    }
    int sv,ev;
    cin>>sv>>ev;
    
    vector<int>* op=getPath(edges,V,sv,ev,visited);
    if(op)
    {
        for(int i=0;i<op->size();i++)
            cout<<op->at(i)<<" ";
    }
    
    

  return 0;
}
