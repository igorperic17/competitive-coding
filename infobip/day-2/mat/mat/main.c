//
//  main.c
//  mat
//
//  Created by Igor Peric on 19/1/21.
//

#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(int argc, const char * argv[]) {
    
    int n, k, i, j;
    scanf("%d%d", &n, &k);
    int a[n][n];
    
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    k = k % (4 * (n - 1));
    for (int p=0;p<n/2;p++) { // prsten
        for (int kk=0;kk<k;kk++) {
            for (i=p;i<n-p-1;i++) swap(&a[i][p], &a[i+1][p]);
            for (i=p;i<n-p-1;i++) swap(&a[n-p-1][i], &a[n-p-1][i+1]);
            for (i=n-p-1;i>p;i--) swap(&a[i][n-p-1], &a[i-1][n-p-1]);
            for (i=n-p-1;i>p+1;i--) swap(&a[p][i], &a[p][i-1]);
        }
    }
    
    printf("\n");
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) printf("%d ", a[i][j]);
        printf("\n");
    }
    
    return 0;
}
