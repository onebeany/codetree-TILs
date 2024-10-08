#include <iostream>
using namespace std;

int getDir(char dir){
    if(dir == 'E') return 0;
    else if (dir == 'S') return 1;
    else if (dir == 'W') return 2;
    else return 3;
}

int main() {
    
    int n;
    cin >> n;

    int x = 0, y = 0;
    int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

    bool isStartPoint = false;
    int t = 0;

    for(int i = 0 ; i < n ; i++){
        char dir;
        int dist;
        cin >> dir >> dist;

        int currDir = getDir(dir);

        for(int j = 0 ; j < dist ; j++){
            x += dx[currDir], y += dy[currDir];
            t++;
            if(x==0&&y==0){
                isStartPoint= true;
                break;
            }
        }
        if(isStartPoint) break;
    }
    cout << t;
    return 0;
}