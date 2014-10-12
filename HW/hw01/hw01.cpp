/*
Kostaq Papa
0412768
CS2134
HW01
Due September 20, 2011; 11:59PM
*/

/*

CONSTRAINTS -> For the maxSubsequenceSum1, maxSubsequenceSum2, maxSubsequenceSum4 functions, 
the seqStart and seqEnd iterators are passed by value because otherwise the program wouldn't compile.
The C++ compiler I used was "DEV C++".

*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class timer {
public:
       timer() : start(clock()) {}
       double elapsed() { return ( clock() - start ) / CLOCKS_PER_SEC; }
       void reset() { start = clock(); }
private:
        double start;
};

template <class container>
int maxSubsequenceSum1( container& a, class container::iterator& seqStart, class container::iterator& seqEnd ){
    class container::iterator itrI;
    class container::iterator itrJ;
    class container::iterator itrK;
    int maxSum = 0;
    
    itrI=a.begin();
    for( itrI = a.begin(); itrI != a.end(); itrI++ )
    for( itrJ = itrI; itrJ != a.end(); itrJ++ ){
         int thisSum = 0;
         for( itrK = itrI; itrK != itrJ; itrK++ )
         thisSum += *itrK;
         thisSum += *itrJ;
         if( thisSum > maxSum ){
             maxSum = thisSum;
             seqStart = itrI;
             seqEnd = itrJ;
         }
    }
    return maxSum;
}

//Add appropriate comments
template<class container>
int maxSubsequenceSum2( container& a, class container::iterator itrSeqStart, class container::iterator itrSeqEnd ){
    class container::iterator itrI;
    class container::iterator itrJ;
    int maxSum = 0;
    for( itrI = a.begin(); itrI != a.end(); itrI++ ){
         int thisSum = 0;
         for( itrJ = itrI; itrJ != a.end(); itrJ++ ){
              thisSum += *itrJ;
              
              if( thisSum > maxSum ){
                  maxSum = thisSum;
                  itrSeqStart = itrI;
                  itrSeqEnd = itrJ;
              }
         }
    }
    return maxSum;
}

//Add appropriate comments
template<class container>
int maxSubsequenceSum4( container& a, class container::iterator itrSeqStart, class container::iterator itrSeqEnd ){
    
    class container::iterator itrI;
    class container::iterator itrJ;
    int thisSum = 0;
    int maxSum = 0;
    for( itrI = a.begin(), itrJ = a.begin(); itrJ != a.end(); itrJ++ ){
         thisSum += *itrJ;
         if( thisSum > maxSum ){
             maxSum = thisSum;
             itrSeqStart = itrI;
             itrSeqEnd = itrJ;
         }
         else if( thisSum < 0 ){
              itrI = itrJ;                          // skip ahead to subseqs starting at a[j+1]
              ++itrI;
              thisSum = 0;
         }
    }
    return maxSum;
}

void maxSS1n128(){
     
//-> Running algorithm for n = 128    
    vector<int> vData128;
    int n128 = 128;
    double timeCheck128=0;
    
    for(int i=0; i<n128; i++){
            vData128.push_back((rand() % 201) - 100);
    }
    
    timer t128;
    t128.reset();    
    maxSubsequenceSum1(vData128, vData128.begin(), vData128.end());
    timeCheck128 = t128.elapsed();
    cout << "Time for n = 128: " << "\t" << timeCheck128 << "s" << endl;
    t128.reset();
}

void maxSS1n245(){
     
//-> Running algorithm for n = 245

     vector<int> vData245;
     int n245 = 245;
     double timeCheck245=0;
     
     for(int i=0; i<n245; i++){
             vData245.push_back((rand() % 201) - 100);
     }
     
     timer t245;
     t245.reset();
     maxSubsequenceSum1(vData245, vData245.begin(), vData245.end());
     timeCheck245 = t245.elapsed();
     cout << "Time for n = 245: " << "\t" << timeCheck245 << "s" << endl;
     t245.reset();
}

void maxSS1n512(){
     
//-> Running algorithm for n = 512

     vector<int> vData512;
     int n512 = 512;
     double timeCheck512=0;
     
     for(int i=0; i<n512; i++){
             vData512.push_back((rand() % 201) - 100);
     }
     
     timer t512;
     t512.reset();
     maxSubsequenceSum1(vData512, vData512.begin(), vData512.end());
     timeCheck512 = t512.elapsed();
     cout << "Time for n = 512: " << "\t" << timeCheck512 << "s" << endl;
     t512.reset();
} 

void maxSS1n1024(){
     
     //-> Running algorithm for n = 1024

     vector<int> vData1024;
     int n1024 = 1024;
     double timeCheck1024=0;
    
     for(int i=0; i<n1024; i++){
             vData1024.push_back((rand() % 201) - 100);
     }
    
     timer t1024;
     t1024.reset();
     maxSubsequenceSum1(vData1024, vData1024.begin(), vData1024.end());
     timeCheck1024 = t1024.elapsed();
     cout << "Time for n = 1024: " << "\t" << timeCheck1024 << "s" << endl;
     t1024.reset();
}

void maxSS1n2048(){
     
//-> Running algorithm for n = 2048

     vector<int> vData2048;
     int n2048 = 2048;
     double timeCheck2048=0;
    
     for(int i=0; i<n2048; i++){
             vData2048.push_back((rand() % 201) - 100);
     }
    
     timer t2048;
     t2048.reset();
     maxSubsequenceSum1(vData2048, vData2048.begin(), vData2048.end());
     timeCheck2048 = t2048.elapsed();
     cout << "Time for n = 2048: " << "\t" << timeCheck2048 << "s" << endl;
     t2048.reset();
}

void maxSS1n4096(){

//-> Running algorithm for n = 4096

     vector<int> vData4096;
     int n4096 = 4096;
     double timeCheck4096=0;
     for(int i=0; i<n4096; i++){
             vData4096.push_back((rand() % 201) - 100);
     }
     
     timer t4096;
     t4096.reset();
     maxSubsequenceSum1(vData4096, vData4096.begin(), vData4096.end());
     timeCheck4096 = t4096.elapsed();
     cout << "Time for n = 4096: " << "\t" << timeCheck4096 << "s" << endl;
     t4096.reset();
}

void maxSS2n128(){
     
//-> Running algorithm for n = 128
  
    vector<int> vData128;
    int n128 = 128;
    double timeCheck128=0;
    
    for(int i=0; i<n128; i++){
            vData128.push_back((rand() % 201) - 100);
    }
    
    timer t128;
    t128.reset();    
    maxSubsequenceSum2(vData128, vData128.begin(), vData128.end());
    timeCheck128 = t128.elapsed();
    cout << "Time for n = 128: " << "\t" << timeCheck128 << "s" << endl;
    t128.reset();
}

void maxSS2n245(){
     
//-> Running algorithm for n = 245

     vector<int> vData245;
     int n245 = 245;
     double timeCheck245=0;
     
     for(int i=0; i<n245; i++){
             vData245.push_back((rand() % 201) - 100);
     }
     
     timer t245;
     t245.reset();
     maxSubsequenceSum2(vData245, vData245.begin(), vData245.end());
     timeCheck245 = t245.elapsed();
     cout << "Time for n = 245: " << "\t" << timeCheck245 << "s" << endl;
     t245.reset();
}

void maxSS2n512(){
     
//-> Running algorithm for n = 512

     vector<int> vData512;
     int n512 = 512;
     double timeCheck512=0;
     
     for(int i=0; i<n512; i++){
             vData512.push_back((rand() % 201) - 100);
     }
     
     timer t512;
     t512.reset();
     maxSubsequenceSum2(vData512, vData512.begin(), vData512.end());
     timeCheck512 = t512.elapsed();
     cout << "Time for n = 512: " << "\t" << timeCheck512 << "s" << endl;
     t512.reset();
} 

void maxSS2n1024(){
     
//-> Running algorithm for n = 1024

     vector<int> vData1024;
     int n1024 = 1024;
     double timeCheck1024=0;
    
     for(int i=0; i<n1024; i++){
             vData1024.push_back((rand() % 201) - 100);
     }
    
     timer t1024;
     t1024.reset();
     maxSubsequenceSum2(vData1024, vData1024.begin(), vData1024.end());
     timeCheck1024 = t1024.elapsed();
     cout << "Time for n = 1024: " << "\t" << timeCheck1024 << "s" << endl;
     t1024.reset();
}

void maxSS2n2048(){
     
//-> Running algorithm for n = 2048

     vector<int> vData2048;
     int n2048 = 2048;
     double timeCheck2048=0;
    
     for(int i=0; i<n2048; i++){
             vData2048.push_back((rand() % 201) - 100);
     }
    
     timer t2048;
     t2048.reset();
     maxSubsequenceSum2(vData2048, vData2048.begin(), vData2048.end());
     timeCheck2048 = t2048.elapsed();
     cout << "Time for n = 2048: " << "\t" << timeCheck2048 << "s" << endl;
     t2048.reset();
}

void maxSS2n4096(){

//-> Running algorithm for n = 4096

     vector<int> vData4096;
     int n4096 = 4096;
     double timeCheck4096=0;
     for(int i=0; i<n4096; i++){
             vData4096.push_back((rand() % 201) - 100);
     }
     
     timer t4096;
     t4096.reset();
     maxSubsequenceSum2(vData4096, vData4096.begin(), vData4096.end());
     timeCheck4096 = t4096.elapsed();
     cout << "Time for n = 4096: " << "\t" << timeCheck4096 << "s" << endl;
     t4096.reset();
}

void maxSS4n128(){
     
//-> Running algorithm for n = 128
  
    vector<int> vData128;
    int n128 = 128;
    double timeCheck128=0;
    
    for(int i=0; i<n128; i++){
            vData128.push_back((rand() % 201) - 100);
    }
    
    timer t128;
    t128.reset();    
    maxSubsequenceSum4(vData128, vData128.begin(), vData128.end());
    timeCheck128 = t128.elapsed();
    cout << "Time for n = 128: " << "\t" << timeCheck128 << "s" << endl;
    t128.reset();
}

void maxSS4n245(){
     
//-> Running algorithm for n = 245

     vector<int> vData245;
     int n245 = 245;
     double timeCheck245=0;
     
     for(int i=0; i<n245; i++){
             vData245.push_back((rand() % 201) - 100);
     }
     
     timer t245;
     t245.reset();
     maxSubsequenceSum4(vData245, vData245.begin(), vData245.end());
     timeCheck245 = t245.elapsed();
     cout << "Time for n = 245: " << "\t" << timeCheck245 << "s" << endl;
     t245.reset();
}

void maxSS4n512(){
     
//-> Running algorithm for n = 512

     vector<int> vData512;
     int n512 = 512;
     double timeCheck512=0;
     
     for(int i=0; i<n512; i++){
             vData512.push_back((rand() % 201) - 100);
     }
     
     timer t512;
     t512.reset();
     maxSubsequenceSum4(vData512, vData512.begin(), vData512.end());
     timeCheck512 = t512.elapsed();
     cout << "Time for n = 512: " << "\t" << timeCheck512 << "s" << endl;
     t512.reset();
} 

void maxSS4n1024(){
     
//-> Running algorithm for n = 1024

     vector<int> vData1024;
     int n1024 = 1024;
     double timeCheck1024=0;
    
     for(int i=0; i<n1024; i++){
             vData1024.push_back((rand() % 201) - 100);
     }
    
     timer t1024;
     t1024.reset();
     maxSubsequenceSum4(vData1024, vData1024.begin(), vData1024.end());
     timeCheck1024 = t1024.elapsed();
     cout << "Time for n = 1024: " << "\t" << timeCheck1024 << "s" << endl;
     t1024.reset();
}

void maxSS4n2048(){
     
//-> Running algorithm for n = 2048

     vector<int> vData2048;
     int n2048 = 2048;
     double timeCheck2048=0;
    
     for(int i=0; i<n2048; i++){
             vData2048.push_back((rand() % 201) - 100);
     }
    
     timer t2048;
     t2048.reset();
     maxSubsequenceSum4(vData2048, vData2048.begin(), vData2048.end());
     timeCheck2048 = t2048.elapsed();
     cout << "Time for n = 2048: " << "\t" << timeCheck2048 << "s" << endl;
     t2048.reset();
}

void maxSS4n4096(){

//-> Running algorithm for n = 4096

     vector<int> vData4096;
     int n4096 = 4096;
     double timeCheck4096=0;
     for(int i=0; i<n4096; i++){
             vData4096.push_back((rand() % 201) - 100);
     }
     
     timer t4096;
     t4096.reset();
     maxSubsequenceSum4(vData4096, vData4096.begin(), vData4096.end());
     timeCheck4096 = t4096.elapsed();
     cout << "Time for n = 4096: " << "\t" << timeCheck4096 << "s" << endl;
     t4096.reset();
}    

void maxSS1(){
     
     cout << "*Running times for maxSubsequenceSum1." << endl;
     maxSS1n128();
     maxSS1n245();
     maxSS1n512();
     maxSS1n1024();
     maxSS1n2048();
     maxSS1n4096();
     cout << endl;
}

void maxSS2(){
     
     cout << "*Running times for maxSubsequenceSum2." << endl;     
     maxSS2n128();
     maxSS2n245();
     maxSS2n512();
     maxSS2n1024();
     maxSS2n2048();
     maxSS2n4096();
     cout << endl;
}

void maxSS4(){
     
     cout << "*Running times for maxSubsequenceSum4." << endl;     
     maxSS4n128();
     maxSS4n245();
     maxSS4n512();
     maxSS4n1024();
     maxSS4n2048();
     maxSS4n4096();
     cout << endl;
}

void maxSS(){
     
     maxSS1();
     maxSS2();
     maxSS4();
}
          

int main(){
    
    maxSS();
    
    system("pause");
    return 0;
}
