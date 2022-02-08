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
const LL INF = 10e9;

int main3(int argc, const char * argv[]) {
    
    ifstream fin("in.txt");
    
    int i,j,n,k;
    fin >> n;
    vector<LL> a(n);
    
    for (i=0;i<n;i++) fin >> a[i];
    sort(a.begin(), a.end());
    
    k = 3;
    vector<float> c;
    for (i=0;i<k-1;i++) c.push_back(i * (float(a[n-1]) / k));
    c.push_back(a[n-1]);
    for (i=0;i<k;i++) cout << c[i] << " ";
    cout << endl;
    vector<int> p(n);
    
    for (int t=0;t<30;t++) {
        
        // mark points
        for (i=0;i<n;i++) {
            float dmin = INF;
            for (j=0;j<k;j++) {
                if (abs(c[j] - a[i]) < dmin) {
                   dmin = abs(c[j] - a[i]);
                   p[i] = j;
                }
            }
        }
        
        // recompute clusters
        for (j=0;j<k;j++) {
            float newC = 0;
            int nc = 0;
            for (i=0;i<n;i++) {
                if (p[i] == j) { newC += a[i]; nc++; }
            }
            c[j] = newC / nc;
        }
        
    }
    
//    convert into integers
    vector<LL> clusters(k);
    for (i=0;i<k;i++) {
//        clusters[i] = *upper_bound(a.begin(), a.end(), c[i]);
        clusters[i] = c[i];
    }
    
    for (i=0;i<k;i++) cout << c[i] << " ";
    cout << endl;
    for (i=0;i<k;i++) cout << clusters[i] << " ";
    cout << endl;
    
    int s = 0;
    for (i=0;i<n;i++) {
        LL mm = INF;
        for (j=0;j<k;j++) mm = min(mm, abs(a[i] - clusters[j]));
        s += mm;
    }
    cout << "s: " << s << endl;
    
    return 0;
    
}
