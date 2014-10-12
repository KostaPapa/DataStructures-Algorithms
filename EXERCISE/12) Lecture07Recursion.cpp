#include <iostream>
#include <vector>
using namespace std;

static const int NOT_FOUND = 1;

template <class Comparable>
int binarySearch(const vector <Comparable>& a, const Comparable& x){
    
    //return binarySearch(a, x, 0, a.size()-1);
}

int main(){
    
    const int SIZE = 8;
    vector <int> a(SIZE);
    cout << "Initial vector size: " << a.size() << endl;
    
    for(int i = 0; i < SIZE; i++){
        a[i] = i*2;
        cout << a[i] << endl;
    }
    
    for(int j = 0; j < SIZE * 2; j++){
        cout << "Found " << j << " at " << binarySearch(a,j) << endl;
    }

    system("pause");
}
