#include <iostream>
#include <set>

using namespace std;
// 02:31

#define MAX_NUM 100

int n;

int grid[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];

void initVisited(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            visited[i][j] = 0;
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool canMove(int x, int y, int parentNum){
    if(!InRange(x, y)) return false;
    else if(visited[x][y] || grid[x][y] != parentNum) return false;
    return true;
}

int findBlocks(int x, int y){
    
    int numBlock = 1;
    int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(canMove(nx, ny, grid[x][y])){
            visited[nx][ny] = 1;
            numBlock += findBlocks(nx, ny);
        }
    }
    return numBlock;
}

int main() {
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j];
        }
    }

    initVisited();

    int block;
    int numExploded = 0;
    int maxBlock = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visited[i][j]) continue;
            visited[i][j] = 1;
            block = findBlocks(i, j);
            if(block >= 4) numExploded++;
            if(block > maxBlock) maxBlock = block;
            /*
            cout << "Current Number: [" << grid[i][j] << "] block: " << block << "\n";
            for(int k = 0 ; k < n ; k++){
                for(int m = 0 ; m < n ; m++){
                    cout << visited[k][m] << " ";
                }
                cout << endl;
            }
            cout << endl;
            */
        }
    }

    cout << numExploded << " " << maxBlock;
    return 0;
}