#include <iostream>
#include <stack>
#include <string>
using namespace std;


//No. 2

bool matchingParen(const string& str){
    
    stack<char> ch;
    
    int ndx = 0;
    int closePara = 0;
    
    while(ndx < str.size()){
        
        if( str[ndx] == '(' ){
            ch.push(str[ndx]);
        }
        else{
            if( str[ndx] == ')'){
                closePara++;
                if (ch.size() != 0 ){
                    ch.pop();
                }
            }
        }
        ndx++;
    }
    
    if(ch.size() != 0 && closePara < ch.size()){
        cout << "Unmatched ')' and " << ch.size() << " extraneous '('" << endl;
    }
    else if(ch.size() != 0){
        cout << ch.size() << " extraneous '('" << endl;
        return false;
    }
    else{
        return true;
    }
}
    
    

int main(){
    
    string str1 = "(3+4)*4";
    cout << boolalpha << matchingParen(str1) << endl; //true
    
    cout << endl;
    
    string str2 = "(4+2)(";
    cout << boolalpha << matchingParen(str2) << endl; //1 extraneous false
    
    cout << endl;
    
    string str3 = "The best way to prepare (to be a programmer) is to write programs, and to study great programs that other people have written.";
    cout << boolalpha << matchingParen(str3) << endl; //true
    
    cout << endl;
    
    string str4 = ")+3((";
    cout << boolalpha << matchingParen(str4) << endl; //Unmatched ')' and 2 extraneous'('
    
        
    system("pause");
}
