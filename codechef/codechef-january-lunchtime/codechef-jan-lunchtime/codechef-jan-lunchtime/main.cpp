//
//  main.cpp
//  codechef-jan-lunchtime
//
//  Created by Igor Peric on 30/1/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        k = n * n - k;
        
        string sol = "No";
        int i,j,kk;
        for (i=0;i<=n;i++) {
            if (i * n > k) continue;
            for (j=0;j<=n;j++) {
                kk = (i + j) * n - i * j;
                if (kk == k) {
                    sol = "Yes";
                    break;
                }
            }
            if (j <= n) break;
        }
        printf("%s\n", sol.c_str());
    }
    return 0;
}
