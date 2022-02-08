//
//  main.cpp
//  infobip-day-1
//
//  Created by Igor Peric on 11/1/21.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main2(int argc, const char * argv[]) {
    
//    ifstream fin("in.txt");
    
    int i,j,n,m;
    cin >> n >> m;
    vector<vector<LL>> mat(m, vector<LL>(n, 0));
    vector<LL> a(n, 0), b(m, 0);
    
    const int MAXN = 100010;
    vector<bool> f(MAXN, false);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        f[ a[i] ] = true;
    }
    
    for (int i=0;i<m;i++) {
        cin >> b[i];
//        cout << "P: " << b[i] << endl;;
        
        vector<bool> vis(MAXN, false);
        int c = 0;
        for (int k=0;k<n;k++) {
            if (!vis[ a[k] ] && f[ a[k] + b[i] ] && !vis[ a[k] + b[i] ]) {
                vis[ a[k] ] = true;
                vis[ a[k] + b[i] ] = true;
                c++;
//                cout << "c: " << c << "   " << a[k] << " - " << a[k] + b[i] << endl;
            }
        }
        
        if (c % b[i] == 0) cout << b[i] << endl;
    }
    
    return 0;
    
}
