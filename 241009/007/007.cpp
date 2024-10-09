#include <iostream>
#include <string>
using namespace std;

class Spy {
    public:
        string code;
        char point;
        int time;

        Spy(string code, char point, int time){
            this->code = code;
            this->point = point;
            this->time = time;
        }
};

int main() {
    
    string code;
    char point;
    int time;

    cin >> code >> point >> time;

    Spy onebean = Spy(code, point, time);

    cout << "secret code : " << onebean.code << endl;
    cout << "meeting point : " << onebean.point << endl;
    cout << "time : " << onebean.time;

    return 0;
}