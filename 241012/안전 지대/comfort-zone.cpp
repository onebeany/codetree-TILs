#include <iostream>
using namespace std;
// 01:47

#define MAX_ROW 50
#define MAX_COL 50

int n, m;

int grid[MAX_ROW][MAX_COL];
int visited[MAX_ROW][MAX_COL];

int tempGrid[MAX_ROW][MAX_COL]; // for each iteration for K

void initVisited(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            visited[i][j] = 0;
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool canMove(int x, int y){
    if(!InRange(x, y)) return false;
    else if(visited[x][y] || tempGrid[x][y] == 0) return false;
    return true;
}

void DFS(int x, int y){
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(canMove(nx, ny)){
            visited[nx][ny] = 1;
            DFS(nx, ny);
        }
    }
}

int findNumOfSafeArea(int k){

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            tempGrid[i][j] = grid[i][j] - k;
            if(tempGrid[i][j] < 0) tempGrid[i][j] = 0;
        }
    }
    /*
    if(k==4){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << tempGrid[i][j] << " ";
            }
        cout << endl;
        }
    cout << endl;
    }
    */
    int numOfArea = 0;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            if(!canMove(i, j)) continue;
            visited[i][j] = 1;
            DFS(i, j);
            numOfArea++;
            /*
            if(k == 4){
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < m ; j++){
                        cout << visited[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            */
        }
    }

    return numOfArea;
}

int main() {
    
    cin >> n >> m;
    int maxHeight = 0; // highest number of cells.
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
            if(grid[i][j] > maxHeight) maxHeight = grid[i][j];
        }
    }

    int minK = -1;
    int numMaxSafe = -1;

    for(int k = 1 ; k <= maxHeight ; k++){
        initVisited();
        int numSafe = findNumOfSafeArea(k);
        if(numSafe > numMaxSafe) {
            minK = k;
            numMaxSafe = numSafe;
        }
    }

    cout << minK << " " << numMaxSafe;

    return 0;
}