/* UVa 10110 Light, more light: http://isaac.lsu.edu/uva/101/10110.html */
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    unsigned long long int n, root;
    while(scanf("%llu", &n) == 1) {
        if(n == 0)
            break;
        if(n < 0) printf("no\n");
        else {
            root = (unsigned long long int)sqrt((double)n);
            if(root * root == n) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
