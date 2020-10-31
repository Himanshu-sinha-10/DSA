int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int** edges=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        edges[i]=new int[n+1];
        for(int j=0;j<=n;j++)
            edges[i][j]=0;
    }
    
    for(int i=0;i<m;i++)
    {
        edges[ u[i] ][ v[i] ]=1;
        edges[ v[i] ][ u[i] ]=1;
    }
    int count=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(edges[i][j]==1)
            {
              for(int k=1;k<=n;k++)
               {
                if(k==i)
                    continue;
                  if(edges[j][k]==1)
                  {
                      if(edges[k][i]==1)
                          count++;
                  }
               }
            }
           
        }
    }
    return count/6;
}





