/* UVa 494 Kindergarten Counting Game */
#include <iostream>
#include <string>

using namespace std;


inline bool isAlphabet(char c) {
    //Check if the character is a valid lowercase or uppercase alphabet and also a number
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

int main() {
    string line;
    while(getline(cin, line)) {
       int wordCount = 0;
       int charCount = 0;
       char c;
       for (int i = 0; (c = line[i]) != '\0'; ++i) {
           if(c != ' ' && isAlphabet(c)) {
               ++charCount;
               //cout << "char count is " << charCount << " with character " << c << " and i = " << i << endl;
           }
           else if(charCount > 0) {
               charCount = 0;
               ++wordCount;
               //cout << "wordCount is " << wordCount << endl;
           }
       }
       if(charCount)
           ++wordCount; //The last word is followed by a newline character without a space.
       cout << wordCount << endl;
    }

     return 0;
}
