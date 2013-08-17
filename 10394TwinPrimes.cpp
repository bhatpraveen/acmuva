/* UVa 10394 Twin Primes */
#include <cstdio>
using namespace std;

const int HIGHEST = 20000000;
bool primes[HIGHEST];
int twins[100001];
int si = 0;

inline void SieveOEratosthenes(bool primes[], const int &largest) {
    int square;

    for (int i = 2; i < largest; ++i) primes[i] = true;
    primes[0] = false;
    primes[1] = false;
    //Sieve of Eratosthenes
    for (int i = 2; i <= 4472; ++i) {

        if(primes[i]) {
            if (primes[i-2]) {
                //printf("both %d and %d are primes\n", i, i-2);
                si++;
                twins[si] = i - 2;
            }
            square = i * i;
            //int m = 1;
            //for(int j = square; j <= largest; j = square + (m * i)) {
            for(int j = square; j <= largest; j += i) {
                primes[j] = false;
                //++m;
            }
        }
    }
}

int main() {
    int s;
    //Generate Primes
    SieveOEratosthenes(primes, HIGHEST);

    //Mark twins
    for(int i = 4472; si <= 100000; ++i) {
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
