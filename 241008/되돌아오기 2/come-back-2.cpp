#include <iostream>
#include <string>
using namespace std;

#define DIR_NUM 4

int dx[DIR_NUM] = {0,1,0,-1};
int dy[DIR_NUM] = {1,0,-1,0};

int main() {
    
    string cmd;
    cin >> cmd;

    int x = 0 , y = 0;
    int t = 0;
    int currDir = 3;

    bool isStartPoint = false;

    for(int i = 0 ; i < cmd.length() ; i++){
        if(cmd[i] == 'L') currDir = (currDir - 1 + 4) % 4;
        else if (cmd[i] == 'R') currDir = (currDir - 1) % 4;
        else x += dx[currDir], y += dy[currDir];
        
        t++;

        if(x==0&&y==0){
            isStartPoint = true;
            break;
        }
    }

    if(isStartPoint) cout << t;
    else cout << -1;

    return 0;
}