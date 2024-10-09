#include <iostream>
#include <vector>

using namespace std;
// 17:23

#define DIR_NUM 4

int n;
int dx[DIR_NUM]={0,1,0,-1}, dy[DIR_NUM]={1,0,-1,0};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {

    int t;
    cin >> n >> t;

    vector<char> cmd(t);
    for(int i = 0 ; i < t ; i++){
        cin >> cmd[i];
    }

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    int x = n/2, y = n/2;
    int currDir = 3;
    
    int score = 0;
    for(int i = 0 ; i < t ; i++){
        if(cmd[i] == 'L') currDir = (currDir + 3) % 4;
        else if(cmd[i] == 'R') currDir = (currDir + 1) % 4;
        else {
            int nx = x + dx[currDir], ny = y + dy[currDir];
            if(InRange(nx, ny)){
                x = nx, y = nx;
                score += arr[x][y];
            }
        }
    }
    cout << score;

    return 0;
}