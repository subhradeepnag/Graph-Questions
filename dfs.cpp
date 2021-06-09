#include<bits/stdc++.h>
using namespace std;

void DFS(int u,int A[][8],int n)
{
    int visited[8] = {0};
    std::stack<int>stk;
    stk.push(u);
    while(!stk.empty())
    {
        int x = stk.top();
        stk.pop();
        if(visited[x] == 0)
        {
            cout<<x<<"->";
            visited[x] = 1;
            for(int v=n-1;v>=0;v--)
            {
                if(A[x][v] == 1 && visited[v] == 0)
                {
                    stk.push(v);
                }
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
 
    int u = 5;
    cout << "DFS Vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;
 
    return 0;
}