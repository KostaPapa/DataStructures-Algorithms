/*
Kostaq Papa
0412768
CS2134
HW03
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Write a recursive program that prints out the sum of the digits of a positive integer. */
int sumDigits(int x){
    
    const int y = 10;
    
    if(x == 0){
        return 0;
    }    
    if(x < 0){
        x = -x;
    }    
    return ((x % y) + (sumDigits(x / y)));
}

/* Write a recursive function that takes two parameters of type string::iterator and returns a boolean
value. Write a driver which calls the recursive function and returns the value returned by the recursive
function; the driver function takes one parameter of type string and returns a boolean value. Your
recursive function determines if a string is a palindrome. */

bool isPalindrome(string& a); //driver function
bool isPalindrome(string::iterator itrL, string::iterator itrR); //recursive function

bool isPalindrome(string& a){
    
    
    isPalindrome(a.begin(), (a.end()-1));
}

bool isPalindrome(string::iterator itrL, string::iterator itrR){    
        
        if(itrL >= itrR){
            return true;
        }
        
        if(*itrL == *itrR){
            itrL++;
            itrR--;
            return isPalindrome(itrL, itrR);
            
        }
        return false;
}

/* Write a program that sums a vector of integers using a divide and conquer algorithm that takes two pa-
rameters, left, right of type vector<int>::iterator and returns an integer. The divide and conquer
function sums the integers in the range [left, right]. Create a driver function to call the recursive
function; the driver function returns the value returned by the recursive function. The driver function
takes one parameter of type vector<a> and returns an integer.*/

int sumVectorInt(vector<int>& a); //driver function
int sumVectorInt(vector<int>::iterator left, vector<int>::iterator right); //recursive function

int sumVectorInt(vector<int>& a){
        
    sumVectorInt(a.begin(), (a.end() - 1));    
}
int sumVectorInt(vector<int>::iterator left, vector<int>::iterator right){
    
    if(left == right){
        return *left;
    }
    else{
        int center = (right - left)/2;
        return sumVectorInt(left, left + center) + sumVectorInt(left + center + 1, right);
    }
}
    
    
int main(){
    
    /* Question No.1 Test */
    cout << "* Question No.1 test:" << endl;
    cout << sumDigits(519) << endl;
    cout << sumDigits(312) << endl;
    cout << sumDigits(-4) << endl << endl;
    
    /* Question No.2 Test */
    cout << "Question No.2 test:" << endl;
    string a = "noon";
    cout << a << "\t" << boolalpha << "( "<< isPalindrome(a) << " )" << endl;

    string b = "kayak";
    cout << b << "\t" << boolalpha << "( " << isPalindrome(b) << " )" << endl;
    
    string c = "a mathematician is a device for turning coffee into theorems";
    cout << c << "\t" << boolalpha << "( " << isPalindrome(c) << " )" << endl;  
    
    string d = "234";
    cout << d << "\t" << boolalpha << "( " << isPalindrome(d) << " )" << endl << endl; 
    
    /*Question No.3 Test */  
    vector<int> x;    
    x.push_back(-9);
    x.push_back(12);
    x.push_back(8);
    
    cout << sumVectorInt(x) << endl;


    system("pause");
}
    
    
        
