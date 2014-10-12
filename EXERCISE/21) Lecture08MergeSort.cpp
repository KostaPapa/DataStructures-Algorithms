#include<iostream>
#include<vector>
using namespace std;

template<class Comparable>
void mergeSort(vector<Comparable>& a){
    
    vector<Comparable> tmpArray(a.size());
    
    mergeSort(a, tmpArray, 0, a.size()-1);
}
