#include <bits/stdc++.h>
using namespace std;

void primeSieve(int n) {
    vector<int> prime(n, 0);

    for (int i = 4; i <= n; i+=2) {
        prime[i] = 1;
    }

    for (int i = 3; i <= n; ++i) {
        if (prime[i] == 0) {

            // why j = i*i?
            // because for i, all the multiples before i*i has been marked.
            // example, i = 5      |  example, i=11
            // 10 is marked by 2   |  22 is marked by 2
            // 15 is marked by 3   |  33 is marked by 3
            // 20 is marked by 2   |  44 is marked by 4
            // 25 wasn't marked.   |  55, 66, 77, 88, 99, 110 all are marked.
            //                     |  except 121.
            for (int j = i*i; j <= n; j+=i) {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i < n; ++i) {
        if (prime[i] == 0) cout << i << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    primeSieve(n);

    return 0;
}