/* 11385 - Da Vinci Code */
#include <iostream>
#include <string.h>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int T, N, fib[100];
    int largest = 0;
    string line;

    char c;
    map<int, char> cipher;

    cin >> T;
    while(T--) {
        largest = 0;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> fib[i];
            if (fib[i] > largest) largest = fib[i];
        }
        cin.ignore();
        getline(cin, line);
        //cout << line << " " << line.size() << endl;
        for (int i = 0, j = 0; i < line.size() && j < N; ++i) {
            c = line[i];
            //cout << c;
            if (c >= 'A' && c <= 'Z') {
                cipher[fib[j]] = c;
                //cout << "Entering " << fib[j] << " as " << c << endl;
                j++;
            }
        }

        fib[0] = 1; fib[1] = 2;

        for (int i = 2; fib[i - 1] <= largest; ++i) {
            fib[i] = fib[i - 2] + fib[i - 1];
        }

        /*
        for (int i = 0; fib[i] <= largest; ++i)
            cout << "fibs= " << fib[i] << " ";
        cout << endl;
        */


        /*
        for (map<int, char>::iterator it = cipher.begin(); it != cipher.end(); ++it, ++i)
            cout << "map has " << it->first << " array has " << fib[i] << endl;
        */

        map<int, char>::iterator it = cipher.begin();
        //for (i = 0; fib[i] <= largest; ++i) {
        //cout << "N= " << N << endl;
        for (int i = 0, j = 0; j < N && fib[i] <= largest; ++i) {
            //cout << "map has " << it->first << " array has " << fib[i] << endl;
            if ((it->first) == (fib[i])) {
                cout << it->second;
                ++j;
                ++it;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
        line.clear();
        cipher.clear();
    }

    return 0;
}
