/* UVa 458 The Decoder */

#include <iostream>
const int SECRETCODE = 7;

using namespace std;

int main() {
    char line[255];
    while(cin >> line){
        for(int i=0; line[i] != '\0'; ++i)
            cout << char(line[i]-SECRETCODE);
    cout << endl;
    }

    return 0;
}
