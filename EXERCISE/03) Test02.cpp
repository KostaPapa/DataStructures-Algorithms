#include <iostream>
using namespace std;

int main(){
    
    int n=10;
    int i=0;
    int j=0;
    
    int countI=0;
    int countJ=0;    
    for(i=0; i<n; i++){
             countI = countI + 1;
             for(j=i; j<n; j++){
                      countJ = countJ + 1;
                      cout << i << "\t" << j << "\t" << "Kosta" << endl;
            }
    }
    cout << "i = " << countI << endl;
    cout << "j = " << countJ << endl;
    system("pause");
}
