#include <iostream>
using namespace std;
// start - 21:46

bool InRange(int n, int nx, int ny){
    return (0 <= nx && nx < n && 0 <= ny && ny < n);
}

int getDir(char dir){
    if(dir == 'R') return 0;
    else if(dir == 'D') return 1;
    else if(dir == 'U') return 2;
    else return 3;
}

int main() {
    
    int n, t, r, c;
    char d;

    cin >> n >> t;
    cin >> r >> c >> d;

    r--, c--;

    int currDir = getDir(d);
    int dx[4]={0, 1, -1, 0}, dy[4]={1,0,0,-1};

    for(int i = 0 ; i < t ; i++){
        int nx = r + dx[currDir], ny = c + dy[currDir];
        if(InRange(n, nx, ny)){
            r = nx, c = ny;
        }
        else currDir = 3 - currDir;
    }

    cout << r+1 << " " << c+1;

    return 0;
}