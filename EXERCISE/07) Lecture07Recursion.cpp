#include <iostream>
using namespace std;

int Fac(int n){
    
    if (n == 0){
        return 1;
    }
    else{
        return (n*Fac(n-1));
    }
}

int main(){
    
    int n, factorial;
    
    cout << "enter an integer: ";
    cin >> n;
    
    factorial = Fac(n);
    cout << factorial << endl;
    
    system("pause");
    
}
