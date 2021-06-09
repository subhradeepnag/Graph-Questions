#include<bits/stdc++.h>
using namespace std;

int dist[31][31];
int visited[31][31];
char arr[31][31];
int N;

bool isValid(int x,int y)
{
    if(x<1 || x>N || y<1 || y>N)
    {
        return false;
    }
    if(visited[x][y] == true || arr[x][y] == 'T')
    {
        return false;
    }
    return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(int srcx,int srcy)
{
    queue<pair<int,int>>q;
    q.push({srcx,srcy});
    visited[srcx][srcy] = 1;

    while(!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            if(isValid(currX + dx[i] , currY + dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                dist[newX][newY] = dist[currX][currY] + 1;
                visited[newX][newY] = 1;
                q.push({newX,newY});
            }
        }

    }

}

int main()
{
    int srcX,srcY,endX,endY;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 'S')
            {
                srcX = i;
                srcY = j;
            }
            if(arr[i][j] == 'E')
            {
                endX = i;
                endY = j;
            }
        }
    }

    bfs(srcX,srcY);
    cout<<dist[endX][endY]<<endl;
}