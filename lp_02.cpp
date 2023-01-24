#include<iostream>
#include <string>
using namespace std;
bool patternFound;  

class MyClass {

    private: 
    string str;
    string replace;
    string replaceWith;

    public:

    void getStrings() {

        cout<<"Enter the string" <<endl;
        cin>> str;
        
    }

    void getReplaceStrings() {
        cout<<"Enter the pattern string" <<endl;
        cin>>replace;

        cout<<"Enter the string to be replaced with: " <<endl;
        cin>>replaceWith;
        
    }

    string patternReplace() {

         // loop to traverse through the string: 
        for(int i = 0; i<str.length(); i++) {

            string temp = "";

            // created a check to prevent the index out of bound
            if(i > str.length() - replace.length()) {
                break;

            }

            // inner loop to find the pattern in the string: 
            for(int j = i; j< replace.length() + i; j++) {
                temp = temp + str[j];
            
            }
            // checks the pattern matching: 
            if(temp == replace) {

                patternFound = true;

                for(int j = i; j<replace.length() + i; j++) {
                    // makes the necessary changes to the string: 
                    str[j] = replaceWith[j-i];
                } 
            } 
  
        }
        return str;
    }
};

int main() {

    MyClass c1;

    c1.getStrings();
    c1.getReplaceStrings();

    string result = c1.patternReplace();

    if(patternFound) {

        cout<<"Edited string is:  " <<result<<endl;

    } else {

        cout<<"No such string is found."<<endl;
    }
    return 0;
}
