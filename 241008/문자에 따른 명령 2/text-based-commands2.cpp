#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int x = 0, y = 0;
    int currDir = 3;
    int dx[4] = {1, 0, -1 ,0}, dy[4] = {0, -1, 0, 1};

    string cmd;
    cin >> cmd;
    for(int i = 0 ; i < cmd.length() ; i++){
        if(cmd[i] == 'F')
            x += dx[currDir], y += dy[currDir];
        else if(cmd[i] == 'L')
            currDir = (currDir + 3) % 4;
        else
            currDir = (currDir + 4) % 4; 
    }
    cout << x << " " << y;
    return 0;
}