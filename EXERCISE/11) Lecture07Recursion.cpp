#include <iostream>
using namespace std;

const string DIGIT_TABLE = "0123456789ABCDEF";
const int MAX_BASE = DIGIT_TABLE.length();

void printIntRec(int n, int base){
    
    if(n >= base){
        printIntRec(n/base, base);
    }
    cout << DIGIT_TABLE[n % base];
}

void printInt(int n, int base){
    
    if(base <= 1 || base > MAX_BASE){
        cerr << "Cannot print in base " << base << endl;
    }
    else{
        if(n < 0){
            cout << "-";
            n = -n;
        }
        printIntRec(n, base);
    }
}

int main(){
    
    for (int i=0; i<=17; i++){
        printInt(-1000, i);
        cout << endl;
    }
    system("pause");
}
    
    
