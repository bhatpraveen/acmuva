/* UVa 10082 Problem C: WERTYU */
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int NKEYS = 45;

char kb[] = {'`','1','2','3','4','5','6','7','8','9','0','-',\
'Q','W','E','R','T','Y','U','I','O','P','[',']',\
'A','S','D','F','G','H','J','K','L',';',\
'Z','X','C','V','B','N','M',',','.',' ','\n'};

char tb[] = {'1','2','3','4','5','6','7','8','9','0','-','=',\
'W','E','R','T','Y','U','I','O','P','[',']','\\',\
'S','D','F','G','H','J','K','L',';','\'',\
'X','C','V','B','N','M',',','.','/',' ','\n'};

int main() {
    char c;
    map<char, char> tb2kb;
    for(int i = 0; i < NKEYS; ++i) {
        tb2kb[tb[i]] = kb[i];
    }

    while(scanf("%c", &c) != EOF) {
        cout << tb2kb[c];
    }

    return 0;
}
