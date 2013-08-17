/* UVa 10924 - Prime Words http://uva.onlinejudge.org/external/109/10924.pdf */
#include <cstdio>
#include <string.h>
using namespace std;

//'Z' has highest value of 52 and length of word is 20, so primes held are below 1040;
static int primes[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, \
103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, \
251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, \
419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, \
593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, \
761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, \
953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039};


int main() {
    int charMap['z' + 1]; //ASCII value of 'z' is higher than 'Z', though its other way around in the problem!
    bool primeMap[1040] = {};
    char word[20 + 1];


    int j = 1;
    for (int i = 'a'; i <= 'z'; i++, j++) charMap[i] = j;
    for (int i = 'A'; i <= 'Z'; i++, j++) charMap[i] = j;

    for(int i = 0; primes[i] < 1040; ++i) primeMap[primes[i]] = true;

    while(scanf("%s", &word) == 1) {
        int sum = 0;
        for(int i = 0; i < strlen(word); ++i) sum += charMap[(int)word[i]];
        if(primeMap[sum]) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }

    return 0;
}


