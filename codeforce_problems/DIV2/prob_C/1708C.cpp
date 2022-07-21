#include<bits/stdc++.h>
using namespace std;;

int main(){ 
    // freopen("test.INP", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--){
        int n,q;
        scanf("%d %d", &n, &q);

        vector<int> a(n+1);
        vector<int> flag(n+1,0);

        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }

        if (q >= n){
            for (int i = 1; i <= n; i++){
                printf("1");
            }
        }else{
            int k = 0;
            for (int i = n; i >= 1; i--){
                if (a[i] <= k) flag[i] = 1;
                else if (k < q){
                    k++;
                    flag[i] = 1;
                }else {
                    flag[i] = 0;
                }
            }
            for (int i = 1; i <= n; i++){
                printf("%d", flag[i]);
            }
        }
        if (t) printf("\n");
    }

}