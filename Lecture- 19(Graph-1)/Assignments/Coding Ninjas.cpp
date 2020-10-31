void doDFS(int** edges,int V,int sv,bool* visited)
{
    visited[sv]=true;
    for(int i=1;i<=V;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1 && !visited[i])
        {
            doDFS(edges,V,i,visited);
        }
    }
}


int solve(int V,int E,vector<int>u,vector<int>v)
{
	// Write your code here .
    // 'n' is no. of ilands i.e., no. of vertices
    // m is size of 'u' and 'v' i.e., no. of edges
    int** edges=new int*[V+1];
    for(int i=1;i<=V;i++)
    {
        edges[i]=new int[V+1];
        for(int j=1;j<=V;j++)
            edges[i][j]=0;
    }
    
    for(int i=0;i<E;i++)
    {
        edges[ u[i] ][ v[i] ]=1;
        edges[ v[i] ][ u[i] ]=1;
    }
    
    bool* visited=new bool[V];
    for(int i=1;i<=V;i++)
        visited[i]=false;
    
    int count=0;
    
    for(int i=1;i<=V;i++)
    {
        if(visited[i]==false)
        {
          count++;
          doDFS(edges,V,i,visited);
        }
    }
    
    
    delete [] visited;
     for(int i=0;i<=V;i++)
        delete [] edges[i];
     delete [] edges;
    return count;
}