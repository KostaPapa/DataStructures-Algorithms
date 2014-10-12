#include <iostream>
using namespace std;

int Sum(int n){
    
    if(n==0){
        return 0;
    }
    else{
        return (n+Sum(n-1));
    }
}

int main(){
    
    int n, sum;
    
    
    cout << "Enter an integer: ";
    cin >> n;
    
    sum = Sum(n);
    cout << sum << endl;
    
    system("pause");
    
}
    
    
    
