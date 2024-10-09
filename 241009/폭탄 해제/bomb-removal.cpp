#include <iostream>
using namespace std;

class Bomb{
    public:
        string code;
        char color;
        int second;
    
    Bomb(string code, char color, int second){
        this->code = code;
        this->color = color;
        this->second = second;
    }
    Bomb(){}
};

int main() {
    
    string code;
    char color;
    int second;

    cin >> code >> color >> second;

    Bomb bomb = Bomb(code, color, second);

    cout << "code : " << bomb.code << endl;
    cout << "color : " << bomb.color << endl;
    cout << "second : " << bomb.second << endl;

    return 0;
}