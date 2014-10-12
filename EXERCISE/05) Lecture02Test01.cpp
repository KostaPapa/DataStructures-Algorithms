#include <iostream>
using namespace std;

class timer {
public:
       timer() : start(clock()) {}
       double elapsed() { return ( clock() - start ) / CLOCKS_PER_SEC; }
       void reset() { start = clock(); }
private:
        double start;
};

int main(){
    
    int n=10;
    double timecheck=0;
    
    timer t;
    t.reset();
    for(int i=1; i<n; i=2*i){
             cout << "Steps: \t " << "Print:" << endl;
             cout << n << "\t\t" << i << endl;
    }
    cout << endl;
    timecheck = t.elapsed();
    cout << "Times Elapsed: " << timecheck << endl;
    
    system("pause");
    return 0;
}
