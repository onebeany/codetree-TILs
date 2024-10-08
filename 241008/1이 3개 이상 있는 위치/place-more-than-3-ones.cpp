#include <iostream>
using namespace std;

int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};

bool InRange(int n, int nx, int ny){
    return (0 <= nx && nx < n && 0 <= ny && ny < n);
}

int main() {
    int n;
    cin >> n;

    int arr[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int numOfOne = 0;
            for(int currDir = 0 ; currDir < 4 ; currDir++){
                int nx = i + dx[currDir], ny = j + dy[currDir];
                if(InRange(n, nx, ny) && arr[nx][ny] == 1){
                    numOfOne++;
                }
            }
            if(numOfOne >= 3){
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}