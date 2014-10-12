#include <iostream>
using namespace std;

void BC(int n){
    
    if(n != 0){
        BC(n/2);
        cout << n%2;
    }
}

int main(){
    
    int n;
    
    cout << "enter an integer: ";
    cin >> n;
    
    BC(n);
    cout << endl;
    
    system("pause");
    
}
    
