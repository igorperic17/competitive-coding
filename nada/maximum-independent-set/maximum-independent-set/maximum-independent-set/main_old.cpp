//
//  main.cpp
//  maximum-independent-set
//
//  Created by Igor Peric on 5/2/22.
//

#include <iostream>

using namespace std;

#define MAXN 40

int main_old(int argc, const char * argv[]) {
    
    int i, j, n, m;
    unsigned long long v[MAXN]; // connectivity "matrix" - bit B in the number v[A] will be set if there is a connection from A to B in the graph
    int parent[MAXN];
    for (i=0;i<MAXN;i++) {
        v[i] = 0;
        parent[i] = -1; // account for isolated edges
    }

    scanf("%d %d", &n, &m);
    int a, b;
    for (i=0;i<m;i++) {
        scanf("%d %d", &a, &b);
        v[a] |= (1 << b);
        v[b] |= (1 << a); // undirected graph
    }
    
    // dp[i][j] is the max number of independent vertices from [0,i]
    // j=0 means vertex i is not included and j=1 means it is
    unsigned long long dp[MAXN][2];
    long long s[MAXN][2]; // set of vertices for the max solution so far
    for (i=0;i<MAXN;i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
        s[i][0] = s[i][1] = (1 << i);
    }
    int maxIdx = 0;
    
    // try adding i-th vertex to the chart
    for (i=0;i<n;i++) {
//        cout << "i = " << i << endl;
        
//        cout << "  before [0]: ";
//        for (j=0;j<n;j++) cout << dp[j][0] << " ";
//        cout << endl;
//        cout << "  before [1]: ";
//        for (j=0;j<n;j++) cout << dp[j][1] << " ";
//        cout << endl;
        
        for (j=0;j<i;j++) {
            if ((s[j][1] & v[i]) == 0) {
//                unsigned long long k = max(dp[j][0], dp[j][1]);
//                dp[i][0] = max(dp[i][0], k);
//                dp[i][1] = max(dp[i][1], k + 1);
//                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                
                if (dp[j][1] + 1 > dp[i][1]) {
//                    cout << "   taking from " << j << ", s[][] = " <<  s[j][1] << endl;
                    dp[i][1] = dp[j][1] + 1;
                    parent[i] = j;
                    s[i][1] = s[j][1] | (1 << i);
                    
                    if (dp[maxIdx][1] < dp[i][1]) maxIdx = i;
                }
            }
        }
        
//        cout << "  after [0]: ";
//        for (j=0;j<n;j++) cout << dp[j][0] << " ";
//        cout << endl;
//        cout << "  after [1]: ";
//        for (j=0;j<n;j++) cout << dp[j][1] << " ";
//        cout << endl;
    }
    
//    printf("\n");
//    for (i=0;i<n;i++) {
//        printf("%lld ", v[i]);
//    }
//    printf("\n");
    
    printf("%llu\n", dp[maxIdx][1]);
    i = maxIdx;
    while (i != -1) {
        printf("%d ", i);
        i = parent[i];
    }
    printf("\n");
    return 0;
}
