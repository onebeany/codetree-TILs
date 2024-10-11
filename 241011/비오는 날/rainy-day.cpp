#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Data{
    public:
        string date;
        string day;
        string whether;
    Data(string date, string day, string whether){
        this->date = date;
        this->day = day;
        this->whether = whether;
    }
    Data(){}
};

int main() {
    int n;
    cin >> n;

    vector<Data> data(n);

    int closestIdx = -1;

    for(int i = 0 ; i < n ; i++){
        cin >> data[i].date >> data[i].day >> data[i].whether;
        if(data[i].whether == "Rain" && ((closestIdx == -1) || data[i].date < data[closestIdx].date)){
            closestIdx = i;
        }
    }
    
    cout << data[closestIdx].date << " " << data[closestIdx].day << " " << data[closestIdx].whether;

    return 0;
}