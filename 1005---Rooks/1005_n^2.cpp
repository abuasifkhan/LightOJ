//! http://www.lightoj.com/volume_showproblem.php?problem=1005
/// 1005 - Rooks

#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#define pi 3.141592653589793

using namespace std;

#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define mx 100010
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("D:/a.txt", "r", stdin);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define i64 long long
#define mod 100000007

int main()
{
//    open
    int test;
    unsigned long long pascal[31][31];
    CLEAR(pascal, 0);
    pascal[0][0] = 1;
    for (int i=1; i<=30; i++) pascal[i][0] = 1;
    for (int i=1; i<=30; i++){
        for (int j=1; j<=i; j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
    S(test);
    FOR(C, 1, test){
        int n, k;
        S(n); S(k);
        unsigned long long mul = 1;
        int a= n;
        for (int i=1; i<=k; i++)
            mul *= a--;

        out(C);
        mul *= pascal[n][k];
        printf("%llu\n", mul);
    }
}





