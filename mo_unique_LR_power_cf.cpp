//Link to problem
//https://www.youtube.com/redirect?redir_token=_v_sue1D_I3r5CjNn-e60BdvE1h8MTU5Mjc3MDk2MEAxNTkyNjg0NTYw&q=https%3A%2F%2Fcodeforces.com%2Fproblemset%2Fproblem%2F86%2FD&v=-HSeAFhc3NQ&event=video_description

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
#define BLOCK 500
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
int fre[1000001] , ar[200001];
lli ans[200001];
lli power = 0;
struct query {
	int l;
	int r;
	int i;
};
query Q[200001];

bool comp(query a , query b)
{
	if (a.l / BLOCK != b.l / BLOCK)
		return a.l / BLOCK < b.l / BLOCK;

	return a.r < b.r;
}

void add(int pos)
{
	lli cnt = fre[ar[pos]];
	fre[ar[pos]]++;

	power -= (cnt * cnt) * ar[pos] , cnt++;
	power += (cnt * cnt) * ar[pos];
}

void remove(int pos)
{
	lli cnt = fre[ar[pos]];
	fre[ar[pos]]--;

	power -= (cnt * cnt) * ar[pos] , cnt--;
	power += (cnt * cnt) * ar[pos];
}

int main()
{
	int n , q;
	cin >> n >> q;
	REP(i , n) cin >> ar[i - 1];
	for (int i = 0; i < q; i++)
	{
		cin >> Q[i].l >> Q[i].r , Q[i].i = i ,  Q[i].l-- , Q[i].r--;
	}

	sort(Q , Q + q , comp);

	int ML = 0 , MR = -1;
	for (int i = 0; i < q; i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;

		while (ML > L)
			ML-- , add(ML);

		while (MR < R)
			MR++ , add(MR);

		while (ML < L)
			remove(ML) , ML++;

		while (MR > R)
			remove(MR) , MR--;

		ans[Q[i].i] = power;
	}

	REP(i , q)
	cout << ans[i - 1] << endl;
}