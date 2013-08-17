/* UVa 10394 Twin Primes */
#include <cstdio>
#include <bitset>
using namespace std;

const int HIGHEST = 20000000;
//bool primes[HIGHEST];
bitset<HIGHEST> primes;
int twins[100001];
int si = 0;

inline void SieveOfAtkin(const int &largest) {
    int square;

    for (int i = 2; i < largest; ++i) primes[i] = false;
    primes.set(0, false);
    primes.set(1, false);
    primes.set(2, true);
    primes.set(3, true);
    //Sieve Of Atkin
    int n, nmod12;
    for (int x = 1; x <= 2236; ++x) { //x till root/2
        for (int y = 1; y <= 4472; y += 2) { //odd y
            n = 4*x*x + y*y;
            nmod12 = n%12;
            if(n < largest && (nmod12 == 1 || nmod12 == 5)) primes.flip(n);
        }
    }

    for (int x = 1; x <= 4472; ++x) {
        for (int y = 1; y <= 4472; ++y) {
            n = 3*x*x + y*y;
            nmod12 = n%12;
            if(n < largest && (nmod12 == 7)) primes.flip(n);

            n = 3*x*x - y*y;
            nmod12 = n%12;
            if(x > y && n < largest && (nmod12 == 11)) primes.flip(n);
        }
    }

    //Eliminate by Sieve
    for (int i = 5; i <= 4472; ++i) {
        if(primes.test(i)) {
            square = i * i;
            for(int j = square; j <= largest; j += square) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    int s;
    //Generate Primes
    SieveOfAtkin(HIGHEST);

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
