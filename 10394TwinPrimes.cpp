/* UVa 10394 Twin Primes */
#include <cstdio>
using namespace std;

const int HIGHEST = 20000000;
bool primes[HIGHEST];
int twins[100001];
int si = 0;

inline void SieveOfAtkin(bool primes[], const int &largest) {
    int square;

    for (int i = 2; i < largest; ++i) primes[i] = false;
    primes[0] = false;
    primes[1] = false;
    primes[2] = true;
    primes[3] = true;
    //Sieve Of Atkin
    for (int x = 1; x <= 4472; ++x) {
        for (int y = 1; y <= 4472; ++y) {
            int n = 4*x*x + y*y;
            if(n < largest && (n%12 == 1 || n%12 == 5)) primes[n] = !primes[n];

            n = 3*x*x + y*y;
            if(n < largest && (n%12 == 7)) primes[n] = !primes[n];

            n = 3*x*x - y*y;
            if(x > y && n < largest && (n%12 == 11)) primes[n] = !primes[n];
        }
    }

    //Eliminate by Sieve
    for (int i = 5; i <= 4472; ++i) {
        if(primes[i]) {
            square = i * i;
            //int m = 1;
            //for(int j = square; j <= largest; j = square + (m * i)) {
            for(int j = square; j <= largest; j += square) {
                primes[j] = false;
                //++m;
            }
        }
    }
}

int main() {
    int s;
    //Generate Primes
    SieveOfAtkin(primes, HIGHEST);

    //Mark twins
    //for(int i = 4472; si <= 100000; ++i) {
    for(int i = 2; si <= 100000; ++i) {
        if (primes[i] && primes[i+2]) {
            si++;
            twins[si] = i;
        }
    }

    while(scanf("%d", &s) != EOF) {
        printf("(%d, %d)\n", twins[s], twins[s] + 2);
    }

    return 0;
}
