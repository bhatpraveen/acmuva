/* UVa 107 The Cat in the Hat  */
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int h, w, i, j, nw, n, th, tempN, tempH, hroot, wroot, m, tempW;
    while(1) {
        cin >> h >> w;
        if(h == 0 && w == 0)
            return 0;
        n = 1;

        if(w > 1) {
            n = 2;
 /*
            while(n++) {
                if(w%n || h%(n+1))
                   continue;
                //cout << "n= " << n << endl;
                m = 2;
                tempW = 1;
                for(i= 0; tempW < w; i++) {
                    tempW *= n;
                }
                if(tempW != w)
                    continue;
                tempH = 1;
                cout << i << endl;
                for(j = 0; tempH < h; j++)
                    tempH *= (n + 1);
                if(tempH != h)
                    continue;
                //cout << j << endl;
                if(i == j)
                    break;
            }
*/
            double loghw = log (h) / log (w);
            while (fabs(log(n + 1)/log(n) - loghw) > 1e-10)
                n++;

        }


        nw = 1;
        tempN = 1;
        tempH = h;
        th = h + w;
        for (i = 0; tempH > 1; ++i) {
            th += tempH * tempN;
            tempN = n * tempN;
            nw += tempN;
            tempH /= (n+1);
        }
        nw = nw - tempN;
        th -= h;

        cout << nw << " " << th << endl;

    }
}
