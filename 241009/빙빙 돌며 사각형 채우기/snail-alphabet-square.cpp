#include <iostream>
#include <vector>
using namespace std;

#define DIR_NUM 4

int n, m;
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m, '\0'));

    int currDir = 0;
    int currX = 0, currY = 0;
    arr[currX][currY] = 'A';

    for(int i = 1 ; i < n*m ; i++){
        int nx = currX + dx[currDir], ny = currY + dy[currDir];
        if(InRange(nx,ny) && arr[nx][ny] == '\0'){
            currX = nx, currY = ny;
            arr[currX][currY] = 'A' + (i%('Z'-'A'+1));
        }
        else{
            currDir = (currDir + 1) % 4;
            currX += dx[currDir], currY += dy[currDir];
            arr[currX][currY] = 'A' + (i%('Z'-'A'+1));
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