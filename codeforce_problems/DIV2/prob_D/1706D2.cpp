#include<bits/stdc++.h>
using namespace std;;

/*
    Problem: Given an array a[] of size n and a number k
              
              Find an array p[] of size n that minimizes the cost (max(a[i]/p[i]) - min(a[i]/p[i])) with 
              1 <= p[i] <= k for all i = 1 -> n

              Print the cost.
*/

int main(){
    // freopen("test.INP", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--){
        int n,k;
        int maxA = -1;
        int res = 1e9;
        scanf("%d %d", &n, &k);
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        maxA = a[n];
        vector<int> f(maxA + 1, -1);

        f[maxA] = n;
        for (int i = 1; i <= n - 1; i++){
            for (int j = a[i]; j < a[i+1]; j++){
                f[j] = i;
            }
        }

        for (int v = 1; v <= a[1]; v++){
            int mx = -1;
            for (int j = 1; j <= maxA/v; j++){
                int maxVal = min(maxA,(j+1)*v - 1);
                int posMax = f[maxVal];
                if (posMax == -1) continue;
                if (a[posMax] >= j*v){
                    mx = max(mx,a[posMax]/min(j,k));
                }
            }
            res = min(res,mx-v);
        }
        printf("%d", res);
        if (t) printf("\n");
    }
}
