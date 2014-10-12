//Drivier Routine

#include <iostream>
using namespace std;

const int MAX_BASE = 15;

void printInt(int n, int base){    
    
    if(base <= 1 || base > MAX_BASE){
        
        cerr << "Cannot print in base " << base << endl;
    }
    else{
        if(n < 0){
            cout << "-";
            n = -n;
        }
        printInt(n, base);
    }
}

int main(){
    
    for(int i=1; i <=17; i=i+2){
        printInt(1000, i);
        cout << endl;
    }
    
    system("pause");
    
    return 0;
}
