/* 12289 - One-Two-Three */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int n;
    cin >> n;
    while(n-- && cin >> word) {
        if(word.length() == 5) cout << 3;
        else if((word[0] == 'o' && word[2] == 'e') || \
                (word[1] == 'n' && word[2] == 'e') || \
                (word[0] == 'o' && word[1] == 'n')) cout << 1;
        else cout << 2;
        cout << endl;
    }

    return 0;
}
