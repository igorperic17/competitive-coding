//
//  main.cpp
//  codeforces-2021-01-05
//
//  Created by Igor Peric on 5/1/21.
//

#include <iostream>
#include <vector>

typedef long long LL;

const LL INF = 10e9;

using namespace std;

int mainB(int argc, const char * argv[]) {
    
    LL t;
    
    cin >> t;
    while (t--) {
        LL s = 0;
        LL i,j,n,x,k=0;
        cin >> n >> x;
        vector<LL> a(n), c(n, 1);
        bool on = true;
        for (i=0;i<n;i++) cin >> a[i];
        for (i=0;i<a.size();i++) {
//            cout << "idx: " << i << " c[i]: " << c[i] << " a[i]: " << a[i] << endl;
            if (on && (a[i] % x) == 0) {
//                cout << "adding " << x << " copies of " << a[i] / x << endl;
                a.push_back(a[i] / x);
                c.push_back(c[i] * x);
            } else {
//                cout << "turning off" << endl;
                on = false;
            }
            s += a[i] * c[i];
        }
        cout << s << endl;
    }
    return 0;
}
