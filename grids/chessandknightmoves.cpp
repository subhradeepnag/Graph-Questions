#include<bits/stdc++.h>
using namespace std;

int dist[10][10];
int visited[10][10];
int targetX,targetY;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, 1};

bool isValid(int x,int y)
{
    if(x<1 || x>8 || y<1 || y>8)
    {
        return false;
    }
    if(visited[x][y] == true )
    {
        return false;
    }
    return true;
}

int BFS(int x,int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y] = 1;
    dist[x][y] = 0;
    if(x == targetX && y == targetY)
    {
        return dist[x][y];
    }
    while(!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0;i<8;i++)
        {
            if(isValid(currX + dx[i] , currY + dy[i]))
            {
                x = currX + dx[i];
                y = currY + dy[i];
                dist[x][y] = dist[currX][currY] + 1;
                visited[x][y] = 1;
                q.push({x,y});

                if(x == targetX && y == targetY)
                {
                    return dist[x][y];
                }
            }

        }

    }

    return -1;

}

int getX(char a)
{
    return a - 'a' + 1;
}

int main()
{
    int x,y,q;
    cin>>q;
    while(q--)
    {
        char a,b;
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                visited[i][j] = 0;
            }
        }
        cin>>a>>b;
        x = getX(a);
        y = b - '0';

        cin>>a>>b;
        targetX = getX(a);
        targetY = b - '0';

        cout<<BFS(x,y)<<endl; 
    }

}