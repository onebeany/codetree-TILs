#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0, y = 0;
    map<char, int> dir;
    dir.insert({'E', 0});
    dir.insert({'S', 1});
    dir.insert({'W', 2});
    dir.insert({'N', 3});

    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

    for(int i = 0 ; i < n ; i++){
        char way;
        int dist;
        cin >> way >> dist;
        for(int j = 0 ; j < dist ; j++){
            x += dx[dir[way]], y += dy[dir[way]];
        }
    }

    cout << x << " " << y;
    return 0;
}