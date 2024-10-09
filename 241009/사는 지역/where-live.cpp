#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person{
    public:
        string name, address, location;
    Person(string n, string a, string l){
        this->name = n;
        this->address = a;
        this->location = l;
    }
    Person(){}
};

int main() {
    
    int n;
    cin >> n;
    //Person people[n];
    vector<Person> people(n);
    
    int slowIdx = 0;
    for(int i = 0 ; i < n ; i++){
        string name, address, location;
        cin >> name >> address >> location;
        people[i] = Person(name, address, location);
        if(people[i].name > people[slowIdx].name){
            slowIdx = i;
        }
    }

    cout << "name " << people[slowIdx].name << endl;
    cout << "addr " << people[slowIdx].address << endl;
    cout << "city " << people[slowIdx].location;
    return 0;
}