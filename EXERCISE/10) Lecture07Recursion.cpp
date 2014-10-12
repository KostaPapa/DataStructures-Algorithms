#include <iostream>
using namespace std;

const string DIGIT_TABLE = "0123456789abcdef";
const int MAX_BASE = DIGIT_TABLE.length();

void printIntRec(int n, int base){
    
    if(n >= base){
        printIntRec(n/base, base);
    }
    cout << DIGIT_TABLE[n % base];
}

int main(){
    
    int n, b;
    
    cout << "enter an integer: "  << endl;
    cin >> n;
    
    cout << "enter the base: " << endl;
    cin >> b;
    
    printIntRec(n, b);
    cout << endl;
    system("pause");
}
