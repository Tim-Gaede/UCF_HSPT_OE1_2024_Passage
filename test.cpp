#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

// template<class T, class U> istream& operator>>(istream &is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
// template<class T> istream& operator>>(istream& is, vector<T>& vec) { for(auto &x : vec) cin >> x; return is; } 
// template<class T, class U> ostream& operator<<(ostream &os, pair<T, U>& p) { os << "<" << p.first << "," << p.second << ">"; return os; }
// template<class T> ostream& operator<<(ostream& os, vector<T>& vec) { os << "["; for(auto x : vec) os << x << " "; os << "]"; return os; }
int oo = -1^1<<31;

void test(string fileName) {
    ifstream in(fileName);
    int d, n, a; in >> d >> n >> a;
    assert(2 <= d && d <= 1e5);
    assert(1 <= n && n <= 1e5);
    assert(1 <= a && a <= 1e5);

    vector<vii> ships(d+1);
    rep(i, 0, n) {
        int x, s, e;
        in >> x >> s >> e;
        assert(0 < x);
        assert(x < d);
        ships[x].emplace_back(s, e);
    }

    rep(i, 1, d) {
        sort(all(ships[i]));
        rep(j, 0, sz(ships[i])-1)
            assert(ships[i][j].second < ships[i][j+1].first);
    }

    rep(i, 0, a) {
        int z, r;
        in >> z >> r;
        assert(0 <= r && r <= d);
        assert(1 <= z && z <= 1e5);
    }
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
    rep(i, 0, 6) {
        string fileName = "passage00" + to_string(i+1) + ".in";
        test(fileName);
        cout << fileName << " PASSED" << endl;
    }

	return 0;
}
