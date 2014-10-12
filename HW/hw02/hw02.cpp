/*
Kostaq Papa
0412768
CS2134
HW02
*/


#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

//Part (a)
template<class Itr, class Comparator>
Itr simpleTransform(Itr& itrStart, Itr& itrEnd, Itr& itrResult, Comparator op){
      
      Itr itr = itrResult;
      
      for( ; itrStart != itrEnd; ++itrStart){
                        *itrResult = op(*itrStart);
                        ++itrResult;
      }
      
      return itr;
}

class switchCase{
public:
       char operator()(char ch){
            if((ch >= 'A')&&(ch <= 'Z')){
                   return ch += 32;
            }
            return ch -= 32;
       }
};

class divideBy{
public:
       divideBy(double d):d(d){}
       double operator()(double n){
              return n/d;
       }

private:
        double d;
};

//part(b)
template<class Itr, class Comparator>
Comparator forEachItem(Itr itrStart, Itr& itrEnd, Comparator& op){
      
      for( ; itrStart != itrEnd; ++itrStart){
                        op(*itrStart);
      }
      
      return op;
}

template<class Object>
class printItem{
public:      
       void operator()(string n){
              cout << n << ' ';
       }
private:      
};

class accumulate{
public:
       accumulate(double x):x(x){}
       double operator()(double y){
              x += y;
              return x;
       }
       
       double get(){
              return x;
       }
private:
        double x;
};
       


int main(){
    
    string DrSeuss = "Sometimes the Questions are Complicated and the Answers are Simple";
	size_t sz = DrSeuss.size();
	string DrSeussReverseCapitialization(sz,' ');
	string::iterator itrS;
    itrS = simpleTransform(DrSeuss.begin(), DrSeuss.end(), DrSeussReverseCapitialization.begin(), switchCase());
            // Now DrSeussReverseCapitilialization holds the string "sOMETIMES THE qUESTIONS ARE cOMPLICATED AND THE aNSWERS ARE sIMPLE" and irtS points to the first letter in DrSeussReverseCapitlialization which has the value 's'        
    
    divideBy divideByThree(3);
    vector<double> someNumbers(10);
	vector<double> someNumbersDivided(10);
	vector<double>::iterator itrV;

	for (int i = 0; i < 10; ++i) {		//put  1, 2, 3, 4, 5, 6, 7, 8, 9, 10 into someNumbers
		someNumbers[i] = i+1;
	}
    itrV = simpleTransform(someNumbers.begin(), someNumbers.end(), someNumbersDivided.begin(), divideByThree);
                   //now someNumbersDivided contains the values 0.333333, 0.666667, 1, 1.33333, 1.66667, 2, 2.33333, 2.66667, 3, 3.33333
    
    list<string> cities;
    cities.push_back("Brooklyn");
    cities.push_back("Paris");
    cities.push_back("Munchen");
    cities.push_back("Moscow");
    cities.push_back("London");
    
    vector<int> intVec;
	for (int i = 0; i < 10; ++i) {		//put  0, 1, 2, 3, 4, 5, 6, 7, 8, 9 into intVec
		intVec.push_back(i);
	}
	
    accumulate accNum = forEachItem(intVec.begin(), intVec.end(), accumulate(0));
        
    printItem<string> printString;

	forEachItem(cities.begin(), cities.end(), printString);
	cout << endl;
	
	system("pause");
    return 0;
}
