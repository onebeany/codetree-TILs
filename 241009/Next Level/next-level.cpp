#include <iostream>
#include <string>

using namespace std;

class account{
    public:
        string id;
        int level;

        account(string id = "codetree", int level = 10){
            this->id = id;
            this->level = level;
        }
};

int main() {

    string id;
    int level;
    cin >> id >> level;
    
    account arr[2];
    arr[0] = account();
    arr[1] = account(id, level);

    for(int i = 0 ; i < 2 ; i++){
        cout << "user " << arr[i].id << " lv " << arr[i].level << endl;
    }
    

    return 0;
}