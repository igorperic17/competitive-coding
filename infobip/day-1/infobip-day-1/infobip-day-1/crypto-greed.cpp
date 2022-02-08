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
#include <set>

using namespace std;

typedef long long LL;

LL mx = 0;
vector<int> idx;

int main3(int argc, const char * argv[]) {
    
//    ifstream fin("in.txt");
    
    int i,j,n,m;
    cin >> n >> m;
    vector<vector<LL>> mat(m, vector<LL>(n, 0));
    vector<vector<LL>> dp(m, vector<LL>(n, 0));
    
    
    for (int i=0;i<m;i++) {
        idx.push_back(0);
        for (int j=0;j<n;j++) {
            cin >> mat[i][j];
            dp[i][j] = ((j > 0) ? dp[i][j-1] : 0 ) + mat[i][j];
        }
    }
    
    for (int i=0;i<m;i++) cout << idx[i] << endl;
    return 0;
}
