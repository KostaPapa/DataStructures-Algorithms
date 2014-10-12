#include<iostream>
using namespace std;

int fact(int n ){
    
    int tmp;
    
    if(n == 0){
        return 1;
    }
    
    tmp = fact(n - 1);
    return tmp;
}

int main(){
    
    cout << fact(9) << endl;
    
    system("pause");
}
