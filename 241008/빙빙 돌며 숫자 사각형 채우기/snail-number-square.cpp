#include <iostream>
using namespace std;
// 22:11

bool InRange(int n, int m, int x, int y){
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    
    int n, m;
    cin >> n >> m;

    int answer[n][m] = {};

    int x = 0, y = 0;
    int currDir = 0;
    int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

    answer[x][y] = 1;
    for(int i = 2 ; i <= n*m ; i++){
        int nx = x + dx[currDir], ny = y + dy[currDir];
        if(!InRange(n, m, nx, ny) || answer[nx][ny] != 0){
            currDir = (currDir + 1) % 4; 
        }
        x += dx[currDir], y += dy[currDir];
        answer[x][y] = i;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}