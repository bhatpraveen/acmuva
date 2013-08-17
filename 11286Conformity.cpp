/* UVa 11286 Conformity */
#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main() {
    int n, backUpN, courseNo, mostPopular;
    map<int, int> courses;
    map<long long, int> popularity;

    long long combination = 0; //or string

    while(1) {
        cin >> n;
        if(n < 1)
            return 0;

        mostPopular = 0;
        while (n--) {
            for (int i = 0; i < 5; ++i) {
                cin >> courseNo;
                courses[courseNo] = n;
            }
            combination = 0;
            int k = 12;
            for (map<int, int>::iterator it = courses.begin(); it != courses.end(); ++it) {
                combination += (it->first * pow(10, k));
                k -= 3;
            }
            courses.clear();
            popularity[combination] += 1;
            mostPopular = mostPopular < popularity[combination]? popularity[combination]: mostPopular;
        }

        int backUpMostPopular = mostPopular;
        mostPopular = 0;
        for(map<long long, int>::iterator it = popularity.begin(); it != popularity.end(); ++it)
            if(it->second == backUpMostPopular)
                mostPopular += it->second;

        cout << mostPopular << endl;

        popularity.clear();
    }
}
