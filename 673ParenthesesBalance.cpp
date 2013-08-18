/* UVa 673 - Parentheses Balance http://uva.onlinejudge.org/external/6/673.pdf */
#include <cstdio>
#include <string.h>
using namespace std;

class Stack {
    int i;
    char s[1024];
public:
    bool Push(char c) {
        if(i > 1024) return false;
        s[i++] = c;
        //printf("count: %d Pushed %c at %d\n", i, s[i-1], i-1);
        return true;
    }

    bool Pop (char *cp) {
        //if(i < 1) { printf("i: %d Stack empty\n", i); return false; }
        if(i < 1) return false;
        *cp = s[--i];
        //printf("i: %d Popped %c\n", i, *cp);
        return true;
    }
    void Clear() { i = 0; }
    Stack() { i = 0; }
    ~Stack() {}
};

int main() {
    char s[1024];
    Stack stk;
    int t, len;
    bool match;
    char c;

    scanf("%d", &t);
    fgets(s, 1024, stdin);
    while(t--) {
        fgets(s, 1024, stdin);
        match = true;
        len = strlen(s);
        //printf("%s\n", s);

        if(len == 0) {
            printf("Yes\n"); //empty string is valid
            continue;
        }

        for(int i = 0; i < len; ++i) {
            switch(s[i]) {
                case ')': if(!stk.Pop(&c) || c != '(') match = false; break;
                case ']': if(!stk.Pop(&c) || c != '[') match = false; break;
                case '(': stk.Push(s[i]); break;
                case '[': stk.Push(s[i]); break;
                default: break;
            }
            //printf("%d %s", i, s);
            if(match == false) break;
        }

        if(match && !stk.Pop(&c)) printf("Yes\n");
        else printf("No\n");
        stk.Clear();
    }

    return 0;
}
