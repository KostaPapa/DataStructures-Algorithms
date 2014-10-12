#include<iostream>
#include<vector>
using namespace std;

int maxSumRec(const vector<int>& a, int left, int right){
    
    if(left == right){
        if(a[left] > 0){
            return a[left];
        }
        else{
            return 0;
        }
    }
    
    int center = (left + right)/2;
    
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);
    
    
    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for(int i = center; i >= left; i--){
        cout << "maxLeftSum: " << maxLeftSum << endl;
        leftBorderSum += a[i];
        cout << "a[i]: " << a[i] << endl;
        cout << "leftBorderSum: " << leftBorderSum << endl;
        if(leftBorderSum > maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
               cout << "maxLeftBorderSum: " << maxLeftBorderSum << endl << endl;
        }
    }
    
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for(int i = center; i >= left; i--){
        cout << "maxRightSum: " << maxRightSum << endl;
        rightBorderSum += a[i];
        cout << "a[i]: " << a[i] << endl;
        cout << "rightBorderSum: " << leftBorderSum << endl;
        if(rightBorderSum > maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
            cout << "maxRightBorderSum: " << maxRightBorderSum << endl << endl;
        }
    }
}

int main(){
    
    vector<int> a(8);
    
    a[0] = 4; a[1] = -3; 
    a[2] = 5; a[3] = -2;
    a[4] = -1; a[5] = 2;
    a[6] = 6; a[7] = -2;
    
    maxSumRec(a, 0, a.size()-1);
    
    system("pause");
}
