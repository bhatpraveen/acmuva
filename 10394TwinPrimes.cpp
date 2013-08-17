/* UVa 10394 Twin Primes */
#include <cstdio>
#include <math.h>
using namespace std;

const int HIGHEST = 20000000;
bool primes[HIGHEST];

inline void SieveOEratosthenes(bool primes[], const int &largest) {
    int square;
    int root = (int) sqrt(largest);

    for (int i = 2; i < largest; ++i) primes[i] = true;

    //Sieve of Eratosthenes
    for (int i = 2; i <= root; ++i) {
        if(primes[i]) {
            square = i * i;
            int m = 1;
            for(int j = square; j <= largest; j = square + (m * i)) {
                primes[j] = false;
                ++m;
            }
        }
    }
}

int main() {
    int s;
    int twins[100001];
    //Generate Primes
    SieveOEratosthenes(primes, HIGHEST);

    //Mark twins
    int si = 0;
    for(int i = 2; si <= 100000 /* && i < HIGHEST */; ++i) {
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
