#include<iostream>
#include<vector>
using namespace std;

template<class Comparable>
int binarySearch(const vector<Comparable>& a, const Comparable& x, int low, int high){
    
    if(low > high){
        return 1; //NOT_FOUND;
    }
    
    int mid = (low + high)/2;
    
    if(a[mid] > x){
        return binarySearch(a, x, low, mid-1);
    }
    else if(a[mid] < x){
        return binarySearch(a, x, mid+1, high);
    }
    else{
        return mid;
    }
}
