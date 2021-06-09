#include <iostream>
#include <queue>

using namespace std;

void BFS(int vtx,int A[][8],int n)
{
    int visited[8] = {0};
    queue<int>q;
    cout<<vtx<<" ->";
    q.push(vtx);
    visited[vtx] = 1;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int i=1;i<=n;i++)
        {
            if(A[x][i]==1 && visited[i]==0)
            {
                cout<<i<<"-> ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
 
 
    return 0;
}