#include <iostream>
using namespace std;

class Agent{
    public:
        char name;
        int score;

        Agent(char name, int score){
            this->name = name;
            this->score = score;
        }
        Agent() {}
};
int main() {
    
    Agent agents[5];

    int minIdx;
    for(int i = 0 ; i < 5 ; i++){
        cin >> agents[i].name >> agents[i].score;
        if(i==0) minIdx = 0;
        else{
            if(agents[i].score < agents[minIdx].score){
                minIdx = i;
            }
        }
    }

    cout << agents[minIdx].name << " " << agents[minIdx].score;
    return 0;
}