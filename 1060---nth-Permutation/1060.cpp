//! Bismillahi-Rahamanirahim.
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
 ** @Category:
/** ========================================**/


/**................ Headers ................**/
#include <bits/stdc++.h>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll unsigned long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 100010

//Fast Reader
template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};

string str;
ll n;
ll fact[22];
void precal(){
    fact[0]=1;
    for(int i=1;i<=20;i++)fact[i]=i*fact[i-1];
}

int freq[30];
int len;

ll permute(int L){
    ll ret=fact[L];
    for(int i=0;i<26;i++){
        ret/=fact[freq[i]];
//        cout<<char(i+'a')<<" "<<freq[i]<<endl;
    }
    return ret;
}
bool flag;
void print(ll made, ll total, int pos){
    if(pos>=len){
        flag=true;
        return;
    }
//    cout<<made<<" "<<total<<" "<<pos<<endl;
    for(int i=0;i<26;i++){
        if(freq[i]){
            freq[i]--;
            ll p = permute(len-pos-1);
//            cout<<char(i+'a')<<" "<<p<<endl;
            if(made+p>=total){
                printf("%c",char(i+'a'));
                print(made,total,pos+1);
                if(flag)return;
            }
            else made+=p;
            freq[i]++;
        }
    }
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    precal();
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        CLEAR(freq,0);
        cin>>str>>n;
        len=str.size();
        for(int i=0;i<len;i++){
            freq[str[i]-'a']++;
        }
        ll p=permute(len);
        flag=false;
        if(p<n)puts("Impossible");
        else{
            print(0,n,0);
            puts("");
        }
    }
    return 0;
}





