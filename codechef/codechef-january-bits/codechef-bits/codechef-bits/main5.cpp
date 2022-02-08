//
//  main.cpp
//  codechef-bits
//
//  Created by Igor Peric on 31/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

int currentColor;
vector<int> color;
vector<vector<int>> e;
vector<bool> exists;

void f(int idx) {
    color[idx] = currentColor;
    for (int i=0;i<e[idx].size();i++) {
        int target = e[idx][i];
        if (color[ target ] == -1) {
            f(target);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int maxn = 2001;
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin >> n >> m;
        e = vector<vector<int>>(n);
        exists = vector<bool>(maxn, false);
        for (int i=0;i<m;i++) {
            cin >> a >> b; a--; b--;
            
            e[a].push_back(b);
//            e[b].push_back(a);
//            exists[a] = true;
//            exists[b] = true;
        }

        color = vector<int>(n, -1);
        currentColor = -1;
        for (int i=0;i<n;i++) {
            if (color[i] == -1) {
                currentColor++;
                f(i);
            }
        }
        
//        for (int i=0;i<n;i++) cout << color[i] << " ";
//        cout << endl;
        
        // find scores
        int nColors = currentColor + 1;
        vector<int> scores(nColors, -1);
        for (int i=0;i<n;i++) {
            if (scores[color[i]] == -1) scores[color[i]] = i+1;
            else scores[color[i]] ^= i+1;
        }

//        cout << "Scores: " << endl;
//        for (int i=0;i<nColors;i++) cout << scores[i] << " ";
//        cout << endl;
        
        // find max score
        int maxScoreIdx = 0;
        for (int i=1;i<nColors;i++) {
            if (scores[maxScoreIdx] < scores[i]) maxScoreIdx = i;
        }
        
//        cout << "Max score: " << scores[maxScoreIdx] << " on index " << maxScoreIdx << endl;
        
        // find max rating
        int maxRating = scores[maxScoreIdx];
        for (int i=0;i<nColors;i++) {
            if (i == maxScoreIdx) continue;
            int rating = scores[maxScoreIdx] ^ scores[i];
            if (maxRating < rating) maxRating =  rating;
        }

        int sol = 0;
        while (maxRating) {
            sol += (maxRating & 1);
            maxRating >>= 1;
        }
        
        cout << sol << endl;
    }
}
