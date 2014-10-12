#include<iostream>
using namespace std;

int fact(int n){
    
    int tmp1, tmp2;
    
    if(n == 0){
        return 1;
    }
    else{
        tmp1 = fact(n-1);
        tmp2 = n*tmp1;
        cout << tmp1 << endl;
        return tmp2;
    }
}

int main(){
    
    cout << fact(5) << endl;
    
    system("pause");
}
