//
//  main.cpp
//  codeforces-2021-01-05
//
//  Created by Igor Peric on 5/1/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

typedef long long LL;

const LL INF = 10e9;

using namespace std;

typedef pair<LL, pair<LL,LL>> edge;

bool comp(edge &a, edge &b) {
    return a.first < b.first;
}

int main(int argc, const char * argv[]) {
    
    LL t,i,n,m;
    
    cin >> t;
    while (t--) {
        cin >> n  >> m;
        vector<LL> k(n), c(m);
        vector<bool> kv(n, false), cv(m, false);
        LL friends = 0;
        
        set<edge> q;
        
        for (i=0;i<n;i++) { cin >> k[i]; k[i]--; };
        for (i=0;i<m;i++) cin >> c[i];
        
        LL sol = 0;
        while (!q.empty()) {
            edge c = *q.begin();
            q.erase(q.begin());
            
            if (kv[c.second.first] || cv[c.second.second]) continue;
            
            LL kk = c.second.first
            for (i=k[i)
            
            kv[c.second.first] = cv[c.second.second] = true;
            friends++;
            sol += c.first;
            
            if (friends == n) break;
        }
        
        cout << sol << endl;
    }
    return 0;
}
