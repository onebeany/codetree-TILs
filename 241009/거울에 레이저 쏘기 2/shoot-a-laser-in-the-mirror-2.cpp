#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 13:19

#define DIR_NUM 4

// 들어오는 방향의 모양이 기준 (위에서 들어오면 down 모양의 화살표)
int getDir(int n, int k){
    if(k <= n) return 1;
    else if(k <= 2*n) return 2;
    else if(k <= 3*n) return 0;
    else return 3;
}

int InRange(int n, int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}

int changeDir(int prevDir, char mirror){
    if(mirror == '/') {
        if(prevDir == 0 || prevDir == 2){
            return (prevDir + 3)%4;
        }
        else return (prevDir + 1)%4;
    }
    else {
        if(prevDir == 0 || prevDir == 2){
            return (prevDir + 1)%4;
        }
        else return (prevDir + 3)%4;
    }
}

int dx[DIR_NUM]={0,1,0,-1}, dy[DIR_NUM]={1,0,-1,0};

int main() {
    
    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n));
    for(int i = 0 ; i < n ; i++){
        string line;
        cin >> line;
        for(int j = 0 ; j < n ; j++){
            arr[i][j] = line[j];
        }
    }

    int k;
    cin >> k;

    int x = 0, y = 0;
    int currDir = 0;
    for(int i = 1 ; i < k ; i++){
        int nx = x + dx[currDir], ny = y +dy[currDir];
        if(InRange(n, nx, ny)){
            x = nx, y = ny;
        }
        else currDir = (currDir + 1) % 4;
    }

    currDir = getDir(n, k);

    int cnt = 0;
    while(InRange(n, x, y)){
        cnt++;
        currDir = changeDir(currDir, arr[x][y]);
        x += dx[currDir], y += dy[currDir];
    }

    cout << cnt;

    return 0;
}