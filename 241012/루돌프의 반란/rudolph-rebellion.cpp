#include <iostream>
#include <cmath>
using namespace std;

// 11:45~15:03
// 16:21
/*

1. 게임판
- N * N
- M개의 턴
  - 루돌프 한 번 이동 -> 1번 산타부터 P번 산타까지 이동

2. 루돌프
- 1개
- 가까운 산타를 향해 1칸 돌진. 아직 탈락하지 않은 산타 선택해야함.
- 가까운 산타 >= 2 -> r 좌표가 가장 큰 산타 향해 돌진 -> 만약 r이 동일하다면 c 좌표가 큰 산타 향해 돌진.
- 총 8방향으로 이동 가능. 가장 가까운 산타를 향해 8방향 중 가장 가까워지는 방향으로 한 칸 돌진.
-> 루돌프와 산타들의 상대적인 거리를 다 재고 있어야 하나?

3. 산타
- 1 <= 산타 <= P -> 총 P명
- 루돌프에게 가장 가까워지는 방향으로 1칸 이동 -> 거리를 알고 있으면 좋을 것 같기도 한데? 아니면 실시간 계산?
- 기절 or 탈락하면 move x
- 다른 산타 칸이나 게임판 밖으로는 move x
- 움직이더라도, 만약 루돌프로부터 가까워지지 않는다면 move x (위 두 항목 체크 후 이것도 체크해야할 듯)
- 상하좌우 인접한 네 방향 이동 가능. 순서는 상우하좌.

4. 충돌 -> 상호작용

5. 기절
- k+1번째 턴까지 기절한다는 것에 대한 표현?

*/
#define DEBUG 0
#define DEEP_DEBUG 0
#define DIR_NUM_SANTA 4
#define DIR_NUM_RODOLF 8
#define MAX_NUM 50
#define MAX_SANTA 30

class Santa {
    public:
        int x, y;
        int score;
        int koTurns;
        bool isKO;
        bool isOut;

    Santa(int x, int y, int koTurns = 0, int score = 0, bool isKO = false, bool isOut = false) {
        this->x = x;
        this->y = y;
        this->koTurns = koTurns;
        this->score = score;  // score 초기화 추가
        this->isKO = isKO;
        this->isOut = isOut;
    }
    Santa() : score(0), koTurns(0), isKO(false), isOut(false) {}  // 기본 생성자에서도 초기화
};


class Rodolf{
    public:
        int x, y;

    Rodolf(int x, int y){
        this->x = x;
        this->y = y;
    }
    Rodolf(){}
};

int n, m, p, c, d;
bool isGameover = false;

int dx[8]={-1,0,1,0,-1,1,1,-1};
int dy[8]={0,1,0,-1,1,1,-1,-1};

int grid[MAX_NUM+1][MAX_NUM+1];
Santa santa[MAX_SANTA+1];
Rodolf rodolf;

bool InRange(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int getDist(int r1, int c1, int r2, int c2){
    return pow(r1 - r2, 2) + pow(c1 - c2, 2);
}

void initGrid(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            grid[i][j] = 0;
        }
    }
}

void printGrid(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int findClosestSanta(){
    int minDist = - 1;
    int minIdx = -1;
    for(int i = 1 ; i <= p ; i++){
        if(santa[i].isOut) continue;
        int dist = getDist(rodolf.x, rodolf.y, santa[i].x, santa[i].y);
#if DEEP_DEBUG
        cout << "rodolf: (" << rodolf.x << ", " << rodolf.y << ") santa: (" << santa[i].x << ", " <<  santa[i].y << ")" << endl;
        cout << "currMinDist: " << minDist << " currMinIdx: " << minIdx << " | Calculated Dist: " << dist << " santa idx: " << i << endl;
#endif
        if(minIdx == -1 || dist < minDist){
            minDist = dist, minIdx = i;
        }
        else if(dist == minDist){
            if(santa[i].x > santa[minIdx].x){
                minIdx = i;
            }
            else if(santa[i].x == santa[minIdx].x && santa[i].y > santa[minIdx].y){
                minIdx = i;
            }
        }
    }
    return minIdx;
}

void interaction(int x, int y, int dir, bool isSantaCollision){

    int santaIdx = grid[x][y];
    int nx, ny;
    if(isSantaCollision)
        nx = x - dx[dir], ny = y - dy[dir];
    else nx = x + dx[dir], ny = y + dy[dir];

    if(!InRange(nx, ny)) {
        santa[santaIdx].isOut = true;
    }
    else{
        if(grid[nx][ny] != 0){
            interaction(nx, ny, dir, isSantaCollision);
        }
        grid[nx][ny] = santaIdx;
        santa[santaIdx].x = nx, santa[santaIdx].y = ny;
    }

    return;
}

int getDir_For_MoveRodolf(int santaIdx){

    int x = santa[santaIdx].x, y = santa[santaIdx].y;

    int dir = -1;
    int minDist = -1;
    for(int i = 0 ; i < DIR_NUM_RODOLF ; i++){
        int nx = rodolf.x + dx[i], ny = rodolf.y + dy[i];
        if(!InRange(nx, ny)) continue;
        int dist = getDist(nx, ny, x, y);
        if(dir == -1 || dist < minDist){
            minDist = dist, dir = i;
        }
    }

    return dir;
}

void moveRodolf(int dir){
    
    int x = rodolf.x, y = rodolf.y;
    int nx = x + dx[dir], ny = y + dy[dir];

    if(grid[nx][ny] != 0){// 산타와의 충돌
        int santaIdx = grid[nx][ny];
        santa[santaIdx].score += c;
        santa[santaIdx].isKO = true;
        santa[santaIdx].koTurns = 2;
#if DEBUG
        cout << "Collision with santa[" << santaIdx << "]" << endl;
        cout << "KO status: " << santa[santaIdx].isKO << endl; 
#endif
        int newSantaX = nx + dx[dir] * c, newSantaY = ny + dy[dir] * c;
        if(!InRange(newSantaX, newSantaY)){ // 게임판에서 벗어나는 경우
            santa[santaIdx].isOut = true;
        }
        else{
            if(grid[newSantaX][newSantaY] != 0){ // 충돌 후 이동된 셀에 산타가 있다면
                interaction(newSantaX, newSantaY, dir, false); // 상호작용
            }
            grid[newSantaX][newSantaY] = santaIdx;
            santa[santaIdx].x = newSantaX, santa[santaIdx].y = newSantaY;
        }
    }

    grid[x][y] = 0, grid[nx][ny] = -1;
    rodolf.x = nx, rodolf.y = ny;
    //cout << "nx = " << nx << " ny = " << ny << " After move rodolf, rodolf point: (" << rodolf.x << ", " << rodolf.y << ")" << endl;
}

void rodolfTurn(){

    int santaIdx = findClosestSanta();
    if(santaIdx == -1){  // game over: There is no santa alive.
        isGameover = true; 
        return;
    }
    int dir = getDir_For_MoveRodolf(santaIdx);
    moveRodolf(dir);
}

int getDir_For_MoveSanta(int santaIdx){
    
    int currDist = getDist(santa[santaIdx].x, santa[santaIdx].y, rodolf.x, rodolf.y);
    int dir = -1;
    int minDist = currDist;
    for(int i = 0 ; i < DIR_NUM_SANTA ; i++){
        int nx = santa[santaIdx].x + dx[i], ny = santa[santaIdx].y + dy[i];
        if(!InRange(nx, ny)) continue;
        else if(grid[nx][ny] > 0) continue; // 해당 방향에 산타가 존재하는 경우
        int dist = getDist(nx, ny, rodolf.x, rodolf.y);
        if(dist < minDist){
            minDist = dist, dir = i;
        }
    }
    return dir;
}

void moveSanta(int dir, int santaIdx){
    int x = santa[santaIdx].x, y = santa[santaIdx].y;
    int nx = x + dx[dir], ny = y + dy[dir];
#if DEBUG
        cout << "Santa[" << santaIdx << "] | (" << x << ", " << y << ") => (" << nx << ", " << ny << ")" << endl;
#endif
    if(grid[nx][ny] == -1){// 루돌프와의 충돌
#if DEBUG
        cout << "Collision Occured!" << endl;
#endif
        santa[santaIdx].score += d;
        santa[santaIdx].isKO = true;
        santa[santaIdx].koTurns = 1;
        int newSantaX = nx - dx[dir] * d, newSantaY = ny - dy[dir] * d;
#if DEBUG
        cout << "newSanta: (" << newSantaX << ", " << newSantaY << ")" << endl;
#endif
        if(!InRange(newSantaX, newSantaY)){ // 게임판에서 벗어나는 경우
        #if DEBUG
            cout << "out of range!" << endl;
        #endif
            santa[santaIdx].isOut = true;
        }
        else if(newSantaX == x && newSantaY == y) return;
        else{
            if(grid[newSantaX][newSantaY] != 0){ // 충돌 후 이동된 셀에 산타가 있다면 (본인이면 안됨)
                bool isSantaCollision = true;
                interaction(newSantaX, newSantaY, dir, isSantaCollision); // 상호작용
            }
            grid[newSantaX][newSantaY] = santaIdx;
            santa[santaIdx].x = newSantaX, santa[santaIdx].y = newSantaY;
        }
    }
    else{
        grid[nx][ny] = santaIdx;
        santa[santaIdx].x = nx, santa[santaIdx].y = ny;
    }
    grid[x][y] = 0;
#if DEBUG
    printGrid();
#endif
}

void santaTurn(int santaIdx){

    int dir = getDir_For_MoveSanta(santaIdx);
    if(dir == -1) return;
    moveSanta(dir, santaIdx);
}

void doGame(){
#if DEBUG
    cout << "\n<Santa status before moving rodolf> | ";
    for(int i = 1 ; i <= p ; i++){
        cout << santa[i].isKO << " " << santa[i].isOut << " | ";
    }
    cout << endl;
#endif

    rodolfTurn();  
    if(isGameover) return;

#if DEBUG
    cout << "After moving rodolef" << endl;
    printGrid();
    cout << "Santa KO Status : " ;
     for(int i = 1 ; i <= p ; i++){
        cout << "isKO: " << santa[i].isKO << " lefTurns: " << santa[i].koTurns << " || ";
    }
    cout << endl;
    cout << "Santa OUT Status : " ;
     for(int i = 1 ; i <= p ; i++){
        cout << santa[i].isOut << " | ";
    }
    cout << endl;
    cout << "Santa Score : " ;
    for(int i = 1 ; i <= p ; i++){
        cout << santa[i].score << " ";
    }
    cout << endl << endl;

    cout << "----- Santa's turn -----" << endl;
#endif

    for(int i = 1 ; i <= p ; i++){
        if(santa[i].isOut){
            continue;
        }
        else if (santa[i].isKO){
#if DEBUG
            cout << "santa[" << i << "] is stuned. Left turns: " << santa[i].koTurns << endl << endl;
#endif
            santa[i].koTurns--;
            if(santa[i].koTurns == 0) {
                santa[i].isKO = false;
#if DEBUG
                cout << "santa[" << i << "] is now can participate again from the next turn!" << endl;
#endif
            }
            continue;
        }
        else santaTurn(i);
    }

    for(int i = 1 ; i <= p ; i++){
        if(!santa[i].isOut) {
            santa[i].score++;
       }
    }
}

int main() {
    
    cin >> n >> m >> p >> c >> d;

    int x, y;
    cin >> x >> y;
    rodolf = Rodolf(x, y);

    initGrid();

    grid[x][y] = -1; // Rodolf

    for(int i = 0 ; i < p ; i++){
        int santaIdx;
        cin >> santaIdx >> x >> y;
        santa[santaIdx] = Santa(x, y);
        grid[x][y] = santaIdx;
    }

    for(int i = 1 ; i <= m && !isGameover ; i++){
#if DEBUG
    cout << "\n ========== GAME[" << i << "] start! ========== " << endl;
#endif
        doGame();
#if DEBUG
        cout << "Game[" << i << "] is done! current santa status : ";
        for(int i = 1 ; i <= p ; i++){
            cout << santa[i].score << " ";
        }
        cout << endl;
        cout << "Santa KO Status : " ;
        for(int i = 1 ; i <= p ; i++){
            cout << "isKO: " << santa[i].isKO << " lefTurns: " << santa[i].koTurns << " || ";
        }
        cout << endl;
        cout << "Santa OUT Status : " ;
        for(int i = 1 ; i <= p ; i++){
            cout << santa[i].isOut << " | ";
        }
        cout << endl;
        cout << "Santa Score : " ;
        for(int i = 1 ; i <= p ; i++){
            cout << santa[i].score << " ";
        }
        cout << endl << endl;
#endif
    }
    
    for(int i = 1 ; i <= p ; i++){
        cout << santa[i].score << " ";
    }
    return 0;
}