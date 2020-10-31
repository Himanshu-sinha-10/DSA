#include<bits/stdc++.h> 
int a[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
 bool visited[NMAX][NMAX];

bool isvalid(int x,int y,int N)
{
 return (x>=0 && x<N && y>=0 && y<N && !visited[x][y]);

}


int dfs(char cake[NMAX][NMAX],int n,int x,int y)
{
    visited[x][y]=true;
    int count=0;
    for(int i=0;i<4;i++)
    {
        int newi=x+a[i][0];
        int newj=y+a[i][1];
        if(isvalid(newi,newj,n) && cake[newi][newj]=='1')
        {
            //count++;
            count+=dfs(cake,n,newi,newj);
        }
    }
    return count+1;
}



int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    int i,j,max=0,count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            visited[i][j]=false;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cake[i][j]=='1' && !visited[i][j])
                count=dfs(cake,n,i,j);
            if(count>max)
                max=count;
                
        }
    }
    return max;
}