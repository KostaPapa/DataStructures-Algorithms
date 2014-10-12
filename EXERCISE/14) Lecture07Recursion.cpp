#include<iostream>
#include<vector>
#include<string>
using namespace std;

static const int NOT_FOUND = -1;

template<class Comparable>
int binarySearch(const vector<Comparable>& a, const Comparable& x);
template<class Comparable>
int binarySearch(const vector<Comparable>& a, const Comparable& x, int low, int high);

template<class Comparable>
int binarySearch(const vector <Comparable>& a, const Comparable& x){
    
    return binarySearch(a, x, 0, a.size() - 1);
}

template<class Comparable>
int binarySearch(const vector<Comparable>& a, const Comparable& x, int low, int high){
    
    if(low > high){
        return NOT_FOUND;
    }
    
    int mid = (low + high)/2;
    
    if(a[mid] < x){
        return binarySearch(a, x, mid+1, high);
    }
    else if(a[mid] > x){
        return binarySearch(a, x, low, mid-1);
    }
    else{
        return mid;
    }
}

int main(){
    
    const int SIZE = 8;
    vector<int> a(SIZE);
    
    for(int i=0; i<SIZE; i++){
        a[i] = i * 2;
    }
    
    for(int j=0; j< SIZE *2; j++){
        cout << "Found " << j << " at " << binarySearch(a,j) << endl;
    }
    
    system("pause");
}




