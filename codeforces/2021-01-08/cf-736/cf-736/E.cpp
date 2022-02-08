//
//  main.cpp
//  cf-736
//
//  Created by Igor Peric on 1/8/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <math.h>

using namespace std;

unsigned long long NCR( long long n, long long r)
{
//    cout << n << " " << r << endl;
    if (r <= 0) return 1;

    /*
     Extra computation saving for large R,
     using property:
     N choose R = N choose (N-R)
    */
    if (r > n / 2) return NCR(n, n - r);

    unsigned long long res = 1;

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;
}

#define MOD 1000000007

int main(int argc, const char * argv[]) {
    
    unsigned long long n, q;
    cin >> n >> q;
    while (q--) {
        
        unsigned long long x;
        cin >> x;
        
        int first = (int)floor(x / 3.0);
        cout << "first " << first << endl;
        
        long long N = n - first;
        cout << "N: " << N << endl;
        unsigned long long K = 3 * (((N + 1) * N) / 2);
        unsigned long long t = NCR(K, x) % MOD;
        
        cout << t << endl;
    }
}
