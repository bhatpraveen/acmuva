/* 10696 - f91 */
#include <stdio.h>

/*
No need for this function, it does after several recursions what main does in a statement! :)
int f91(int n) {
    //cout << n << " ";
    if (n <= 100)
        return (f91(f91(n + 11)));
    else
        return n - 10;
}
*/

int main() {
    int n;
    while(1) {
        scanf("%d", &n);
        if (n < 1) return 0;

        printf("%s%d%s", "f91(", n, ") = ", n);
        if (n <= 100) printf("%d", 91);
        else printf("%d", n - 10);
        printf("\n");
    }

    return 0;
}
