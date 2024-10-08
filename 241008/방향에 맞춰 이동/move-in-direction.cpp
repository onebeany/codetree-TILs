#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int x = 0, y = 0;
    int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};

    for(int i = 0 ; i < n ; i++){
        char currDir;
        int dist;
        cin >> currDir >> dist;

        if(currDir == 'E') x += dx[0] * dist, y += dy[0] * dist;
        else if(currDir == 'S') x += dx[1] * dist, y += dy[1] * dist;
        else if(currDir == 'W') x += dx[2] * dist, y += dy[2] * dist;
        else x += dx[3]*dist, y += dy[3]*dist;
    }
    cout << x << " " << y;
    return 0;
}