#include <iostream>
#include <vector>

using namespace std;

#define DIR_NUM 4

int dx[DIR_NUM]={0,1,0,-1}, dy[DIR_NUM]={1,0,-1,0};

int n, m;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));

    int currDir = 1;

    int x = 0, y = 0;
    arr[x][y] = 1;

    for(int i = 2 ; i <= n*m ; i++){
        int nx = x + dx[currDir], ny = y + dy[currDir];
        if(InRange(nx, ny) && arr[nx][ny] == 0){
            x = nx, y = ny;
            arr[x][y] = i;
        }
        else {
            currDir = (currDir + 3) % 4;
            x += dx[currDir], y += dy[currDir];
            arr[x][y] = i;
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}