#include <iostream>
using namespace std;
// 11:34

bool InRange(int n, int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

int main() {
    
    int n, m;
    cin >> n >> m;

    int arr[n+1][n+1] = {};
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

    for(int i = 0 ; i < m ; i++){
        int r, c; 
        cin >> r >> c;
        arr[r][c] = 1;

        int count = 0;
        for(int i = 0 ; i < 4 ; i++){
            int nx = r+dx[i], ny = c+dy[i];
            if(InRange(n, nx, ny) && arr[nx][ny] == 1){
                count++;
            }
        }
        if(count == 3) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}