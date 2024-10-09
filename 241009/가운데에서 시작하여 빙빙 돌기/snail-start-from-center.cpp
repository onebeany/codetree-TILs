#include <iostream>
#include <vector>

using namespace std;
// 16:04

#define DIR_NUM 4

int n;
int dx[DIR_NUM]={0,1,0,-1}, dy[DIR_NUM]={1,0,-1,0};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    int currDir = 0;
    int mid = n/2; 
    int x = mid, y = mid;
    arr[x][y] = 1;
    
    if(n > 1){
        y++;
        arr[x][y] = 2;
    }

    for(int i = 3 ; i <= n*n ; i++){
        int rotatedDir = (currDir + 3) % 4;
        int nx = x + dx[rotatedDir], ny = y + dy[rotatedDir];
        if(arr[nx][ny]==0){
            currDir = rotatedDir;
            x = nx, y = ny;
            arr[x][y] = i;
        }
        else{
            x += dx[currDir], y += dy[currDir];
            arr[x][y] = i;
        } 
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}