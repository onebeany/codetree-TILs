#include <iostream>
using namespace std;
//20:51

#define MAX_NUM 100

int grid[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM] = {0};

int dx[2]={0,1}, dy[2]={1,0};

bool InRange(int n, int m, int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m; 
}

bool canMove(int n, int m, int x, int y){
    if(!InRange(n, m, x, y)) return false;
    else if (visited[x][y] ||grid[x][y] == 0) return false;
    else return true;
}

int canEscape = 0;

void DFS(int n, int m, int x, int y){

    for(int i = 0 ; i < 2 ; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(canMove(n, m, nx, ny)){
            x = nx, y = ny;
            visited[x][y] = 1;
            DFS(n, m, x, y);
        }
    }

    if(x == n-1 && y == m-1) canEscape = 1;

    return;
}

int main() {
    
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j];
        }
    }

    visited[0][0] = 1;
    DFS(n, m, 0, 0);
    cout << canEscape;

    return 0;
}