//
//  main.cpp
//  codeforces-2021-01-05
//
//  Created by Igor Peric on 5/1/21.
//

#include <iostream>
#include <vector>
#include <math.h>

typedef long long LL;

const LL INF = 10e9;

using namespace std;

int mainA(int argc, const char * argv[]) {
    
    LL t,i,j,n,x;
    
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<LL> a(n), dp1(n+1, INF), dp2(n+1, 0), s(n+1, 0);
        for (i=1;i<=n;i++) {
            cin >> a[i-1];
            s[i] = s[i-1] + a[i-1];
        }
        
        LL mn = 0;
        dp1[0] = 0;
        for (i=1;i<=n;i++) {
            for (j=i;j>0;j--) {
                LL q = ceil(float(s[i] - s[j-1]) / x);
                dp1[i] = min(dp1[i], dp1[j-1] + q);
                dp2[i] = max(dp2[i], dp2[j-1] + q);
            }
        }
        
//        for (i=0;i<=n;i++) cout << s[i] << " ";
//        cout << endl;
//        for (i=0;i<=n;i++) cout << dp1[i] << " ";
//        cout << endl;
        cout << dp1[n] << " " << dp2[n] << endl;
//        cout << mn - s / x << " " << mn << endl;
    }
    return 0;
}
