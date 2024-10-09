#include <iostream>
#include <string>
using namespace std;

class Product{
    public:
        string name;
        int code;
    Product(string n, int c){
        this->name = n;
        this->code = c;
    }
    Product(){}
};

int main() {
    
    string name;
    int code;

    cin >> name >> code;
    
    Product products[2];
    products[0] = Product("codetree", 50);
    products[1] = Product(name, code);

    for(int i = 0 ; i < 2 ; i++){
        cout << "product " << products[i].code << " is " << products[i].name << endl;
    }
    return 0;
}