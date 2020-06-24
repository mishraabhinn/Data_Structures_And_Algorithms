#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) for (LL i = 1; i <= n; i++)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

struct edge {
    int a;
    int b;
    int w;
};

edge ar[100001];
int par[10001];

bool comp(edge a, edge b) {
    if (a.w < b.w)
        return true;

    return false;
}

int find(int a) {
    if (par[a] == -1)
        return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) { par[a] = b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, a, b, w;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = -1;
    }
    for (int i = 0; i < m; i++) {

        cin >> ar[i].a >> ar[i].b >> ar[i].w;
    }

    /*for(int i=0;i<m;i++)
    {
            cout<<ar[i].a<<" "<<ar[i].b<<" "<<ar[i].w<<" "<<"\n";
    }
    */
    sort(ar, ar + m, comp);

    int sum = 0;
    for (int i = 0; i < m; i++) {
        a = find(ar[i].a);
        b = find(ar[i].b);

        if (a != b) {
            sum += ar[i].w;
            merge(a, b);
        }
    }

    cout << sum << "\n";

    return 0;
}
