#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//01:21

#define MAX_NUM 25

int n;
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int grid[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];

vector<int> town;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool canMove(int x, int y){
    if(!InRange(x, y)) return false;
    else if(visited[x][y] || grid[x][y] == 0) return false;
    return true;
}

int findTown(int x, int y){
    int numPerson = 1;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(canMove(nx, ny)){
            visited[nx][ny] = 1;
            numPerson += findTown(nx, ny);
        }
    }
    return numPerson;
}

int main() {
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j];
        }
    }


    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visited[i][j] || grid[i][j] == 0) continue;
            visited[i][j] = true;
            town.push_back(findTown(i, j));
        }
    }


    sort(town.begin(), town.end());
    cout << town.size() << endl;
    for(int i = 0 ; i < town.size(); i++){
        cout << town[i] << endl;
    }

    return 0;
}