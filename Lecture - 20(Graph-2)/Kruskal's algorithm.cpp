#include <iostream>
#include<algorithm>
using namespace std;

class edge
{
    public:
    
    int source;
    int dest;
    int weight;
    
    edge()
    {
        
    }
    edge(int source,int dest,int weight)
    {
        this->source=source;
        this->dest=dest;
        this->weight=weight;
    }
};

bool compare(edge obj1, edge obj2)
{
    return obj1.weight<obj2.weight;
}

int find_parent(int x,int* parent)
{
    if(parent[x]==x)
        return x;
    return find_parent(parent[x],parent);
    
}
int main()
{
  int V, E;
  cin >> V >> E;
    
    edge* input=new edge[E];
    edge* output=new edge[V-1];
    for(int i=0;i<E;i++)
    {
        int s;
        int d;
        int w;
        cin>>s>>d>>w;
        edge* e=new edge(s,d,w);
        input[i]=*e;
        delete e;
    }
   
    sort(input,input+E,compare);
    int* parent=new int[V];
    for(int i=0;i<V;i++)
        parent[i]=i;
    int count=0;
    int i=0;
    while(count<V-1)
    {
        edge e=input[i];
        int sourceparent=find_parent(e.source,parent);
        int destparent = find_parent(e.dest,parent);
        if(sourceparent!=destparent)
        {
            output[count]=e;
            count++;
            parent[sourceparent]=destparent;
            i++;
        }
        else i++;
    }
    for(int i=0;i<V-1;i++)
    {
        if(output[i].source < output[i].dest )
        {
        cout<<output[i].source<<" ";
        cout<<output[i].dest<<" ";
        cout<<output[i].weight<<endl;
        }
        else 
        {
        cout<<output[i].dest<<" ";
        cout<<output[i].source<<" ";
        cout<<output[i].weight<<endl;            
        }
        
     }
     delete [] input;
     delete [] output;
     delete [] parent;

  return 0;
}