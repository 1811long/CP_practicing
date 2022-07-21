#include<bits/stdc++.h>
using namespace std;;

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n,c,q;
        scanf("%d %d %d", &n, &c, &q);
        vector<char> s;
        
        vector<long long int> l(c+1);
        vector<long long int> r(c+1);
        vector<long long int> cost(c+1);

        s.push_back('0');
        long long int len = (long long int) n;      

        for (int i = 1; i <= n; i++){
            char x;
            scanf("\n%c", &x);
            s.push_back(x);
        }

        l[0] = 1;
        r[0] = n;
        cost[0] = 0;

        for (int i = 1; i <= c; i++){
            long long int l1,r1;
            scanf("%lli %lli", &l1, &r1);
            l[i] = r[i-1] + 1;
            r[i] = l[i] + (r1 - l1);
            cost[i] = l[i] - l1;
        }

        for (int i = 1; i <= q; i++){
            long long int k;
            scanf("%lli", &k);
            for (int j = c; j >= 1; j--){
                if (k >= l[j]){
                    k -= cost[j];
                }
            }
            printf("%c", s[k]);
            if (i < q) printf("\n");
        }

        if(t) printf("\n");
    }
}