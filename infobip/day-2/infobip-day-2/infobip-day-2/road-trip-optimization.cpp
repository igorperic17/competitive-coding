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
LL tsum = 0;

//int f(int idx, int seg_idx, sss) {
//    
//    int targ = upper_bound(a.begin(), a.end(), tsum);
//    
//    return min( sss);
//    
//}

int main1(int argc, const char * argv[]) {
    
    ifstream fin("in.txt");
    
    int i,n,k;
    fin >> n >> k;
    vector<LL> a(n), ss(n);
    for (i=0;i<n;i++) {
        fin >> a[i];
        tsum += a[i];
        ss[i] = (i>0)?a[i]:0;
    }
    f(0,0,0);
    
    tsum /= k;
    cout << "tsum: " << tsum << endl;
    
    vector<LL> b;
    LL cs = 0, sol = 0;
    for (int i=0;i<n;i++) {
        cs += a[i];
        cout << i << " " << cs << endl;
        sol = max(sol, cs);
        if (cs >= tsum) {
//            cout << "diff: " << cs - tsum << "   " << a[i+1] << endl;
            b.push_back(i);
            cs = 0;
        }
    }
    
    sol = max(sol, cs);
    for (int i=0;i<k-1;i++) cout << b[i] << " ";
    cout << endl;
    cout << sol << " " << endl;
    return 0;
    
}
