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
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1};
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

LL weight[100001];
vector<LL> adj[100001];
const int maxN = 15;
int level[100001] , LCA[100001][maxN + 1];
int ft[200001], s[100001], t[100001];
int timer;






void dfs(int node , int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par;

    s[node] = timer;
    ft[timer] = node;
    timer++;

    for (int child : adj[node])
        if (child != par)
            dfs(child , lvl + 1, node);

    t[node] = timer;
    ft[timer] = node;
    timer++;
}



void init(int n)
{
    dfs(1 , 0 , -1);

    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= n; j++)
            if (LCA[j][i - 1] != -1)
            {
                int par = LCA[j][i - 1];
                LCA[j][i] = LCA[par][i - 1];
            }
    }
}


int getLCA(int a , int b)
{
    if (level[b] < level[a]) swap(a , b);

    int d = level[b] - level[a];

    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];

        d -= 1 << i;
    }

    if (a == b) return a;

    for (int i = maxN; i >= 0; i--)
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i] , b = LCA[b][i];
        }

    return LCA[a][0];
}

int getDist(int a , int b)
{
    int lca = getLCA(a , b);
    return level[a] + level[b] - 2 * level[lca];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE

    // for getting inpit from input.txt
    freopen("input1.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif



    LL t;
    cin >> t;
    while (t--)
    {

        LL n, q;
        cin >> n >> q;

        for (LL i = 1; i < n; i++)
        {
            adj[i].clear();

        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= maxN; j++)
                LCA[i][j] = -1;
        }

        for (LL i = 1; i <= n; i++)
        {
            cin >> weight[i];
        }

        for (LL i = 1; i < n; i++)
        {
            LL a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        timer = 1;
        init(n);
        // for (int i = 1; i <= 2 * n; i++) {
        //     cout << ft[i] << " ,";
        // }
        // cout << " }" << "\n";

        // for (int i = 1; i <= n; i++) {
        //     cout << s[i] << " ,";
        // }
        // cout << " }" << "\n";
        while (q--)
        {
            LL type;
            cin >> type;
            if (type == 1)
            {
                LL u, v, x;
                cin >> u >> v >> x;

                if (u > v) swap(u, v);
                if (u == getLCA(u, v))
                {   vector<LL> freq;

                    LL flag = 0;
                    for (LL i = 1; i <= 2 * n; i++)
                    {
                        if (ft[i] == u)
                        {
                            for (LL j = i; j <= 2 * n; j++)
                            {
                                freq.push_back(ft[j]);
                                if (ft[j] == v)
                                {   flag = 1;
                                    break;
                                }


                            }
                            if (flag)
                                break;
                        }

                    }
                    // for (LL i = 0; i < freq.size(); i++)
                    //     cout << freq[i] << " ";

                    for (LL i : freq)
                    {   if (count(freq.begin(), freq.end(), i) == 1)
                            weight[i] = weight[i] ^ x;
                    }


                }
                else
                {   vector<LL> freq;
                    LL cnt = 0;
                    LL flag = 0;
                    for (LL i = 1; i <= 2 * n; i++)
                    {
                        if (ft[i] == u)
                        {
                            cnt += 1;
                        }
                        if (cnt == 1)
                            for (LL j = i + 1; j <= 2 * n; j++)
                            {
                                freq.push_back(ft[j]);
                                if (ft[j] == v)
                                {
                                    flag = 1;
                                    break;
                                }


                            }
                        if (flag)
                            break;


                    }
                    // for (LL i = 0; i < freq.size(); i++)
                    //     cout << freq[i] << " ";
                    // cout << getLCA(u, v) << "\n";
                    // for (LL i = 1; i <= n; i++)
                    //     cout << weight[i] << " ";
                    // cout << "\n";

                    for (LL i : freq)
                    {   if (count(freq.begin(), freq.end(), i) == 1)
                            weight[i] = weight[i] ^ x;
                    }
                    weight[getLCA(u, v)] = weight[getLCA(u, v)] ^ x;
                    // for (LL i = 1; i <= n; i++)
                    //     cout << weight[i] << " ";
                    // cout << "\n";

                }


            }
            else
            {
                LL k, y;
                cin >> k >> y;
                set<LL> subtree;
                LL count = 0;
                LL flag = 0;
                for (LL i = 1; i <= 2 * n; i++)
                {
                    if (ft[i] == k)
                    {
                        for (LL j = i; j <= 2 * n; j++)
                        {
                            subtree.insert(ft[j]);

                            if (ft[j] == k)
                                count += 1;
                            if (count == 2)
                            {   flag = 1;
                                break;
                            }
                        }
                    }

                    if (flag )
                        break;
                }

                LL maxi = -1;
                //cout << subtree.size() << "\n";
                //set<LL>::iterator itr;
                // for (auto itr = subtree.begin(); itr != subtree.end(); ++itr)
                //     cout << *itr << " ";
                // cout << "\n";

                for (auto itr = subtree.begin(); itr != subtree.end(); ++itr)
                {   LL check = weight[*itr] ^ y;
                    maxi = max(check, maxi);
                }


                cout << maxi << "\n";
            }


        }
        // cout << "\n";
        // for (LL i = 1; i <= n; i++)
        //     cout << weight[i] << " ";

        // cout << "\n";







    }

    return 0;
}