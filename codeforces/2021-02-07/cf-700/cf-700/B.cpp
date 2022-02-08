//
//  main.cpp
//  cf-700
//
//  Created by Igor Peric on 7/2/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL A,B;

bool comp(pair<LL,LL> &a, pair<LL,LL> &b) {
    LL roundsA = (a.second / A) * a.first;
    LL roundsB = (b.second / A) * b.first;
    return roundsA < roundsB;
}

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        
        LL n,k;
        vector<pair<LL,LL>> b;
        
        cin >> A >> B >> n;
        vector<LL> a(n, 0);
        
        for (LL i=0;i<n;i++) cin >> a[i];
        for (LL i=0;i<n;i++) {
            cin >> k;
            b.push_back({a[i], k});
        }
        sort(b.begin(), b.end(), comp);
        
        int i;
        bool monsterAlive = false;
        for (i=0;i<n;i++) {
            
            LL rounds = b[i].second / A;
            LL roundsMe = B / b[i].first;
            rounds = min(rounds, roundsMe);
            
            B -= rounds * b[i].first;
            monsterAlive = (A * rounds < b[i].second);
            
            if (B <= 0) break;
            
            if (monsterAlive) B -= b[i].first;
            monsterAlive = (A * (rounds+1) < b[i].second);
        }
        
        if (!monsterAlive) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}
