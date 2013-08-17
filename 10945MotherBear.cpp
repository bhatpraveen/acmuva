/* 10945 - Mother bear */
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
    std::string sentence;
    bool palindrome;
    while(1) {
        getline(cin, sentence);
        if(!strcmp(sentence.c_str(), "DONE"))
            return 0;

        palindrome = true;

        std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

        for(int i = 0, j = sentence.size() - 1; i <= j; ) {
            //cout << i << sentence[i] << " and " << j << sentence[j] << endl;
            while(sentence[i] < 'a' || sentence[i] > 'z') i++;
            while(sentence[j] < 'a' || sentence[j] > 'z') j--;

            if(i < j && sentence[i] != sentence[j]) {
                //cout << i << sentence[i] << " differs " << j << sentence[j] << endl;
                palindrome = false;
                //break;
            }
            i++; j--;
        }

        if (palindrome) cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;
    }
}
