#include<iostream>
#include<vector>
using namespace std;

template<class Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tempArray, int left, int right){
    
    if(left < right){
        
        int center = (left+right)/2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center+1, right);
        merge(a, tmpArray, left, center +1, right);
    }
}
