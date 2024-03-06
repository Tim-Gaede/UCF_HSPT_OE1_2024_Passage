#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

// template<class T, class U> istream& operator>>(istream &is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
// template<class T> istream& operator>>(istream& is, vector<T>& vec) { for(auto &x : vec) cin >> x; return is; } 
// template<class T, class U> ostream& operator<<(ostream &os, pair<T, U>& p) { os << "<" << p.first << "," << p.second << ">"; return os; }
// template<class T> ostream& operator<<(ostream& os, vector<T>& vec) { os << "["; for(auto x : vec) os << x << " "; os << "]"; return os; }
int oo = -1^1<<31;

struct tcase {
	int d, n, a;
	vector<tuple<int, int, int>> ships;
	vector<pair<int, int>> times;
};

int solve(tcase cur) {
	auto [d, n, a, ships, times] = cur;

	//            x  type  tin tout
	vector<tuple<int, int, int, int>> events;
	for(auto [t, r] : times) {
		events.emplace_back(r, 1, t, -1);
	}
	for(auto [x, tin, tout] : ships) {
		x = min(x, d-x);
		events.emplace_back(x, 0, tin, tout);
	}

	sort(all(events));
	reverse(all(events));
	set<int> attacks;
	attacks.insert(1e9);
	int ans = 0;
	for(auto [x, type, tin, tout] : events) {
		// cout << x << " " << type << " " << tin << " " << tout << endl;
		if(!type) {
			auto nxtTime = *attacks.lower_bound(tin);
			if(nxtTime > tout) ans++;
		} else attacks.insert(tin);
	}

	return ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	vector<tcase> cases = {
		{
			10, 3, 1, 
			{{3, 2, 7}, {8, 4, 10}, {5, 1, 8}},
			{{8, 4}}
		},
		{
			10, 3, 2, 
			{{3, 2, 6}, {8, 4, 10}, {5, 1, 7}},
			{{4, 3}, {12, 5}}
		},
		{
			100, 56, 7,
			{{10, 12, 20}, {10, 1, 8}, {10, 9, 10}, {10, 11, 11},
			 {11, 12, 20}, {11, 1, 8}, {11, 9, 10}, {11, 11, 11},
			 {9, 12, 20}, {9, 1, 8}, {9, 9, 10}, {9, 11, 11},
			 {1, 12, 20}, {1, 1, 8}, {1, 9, 10}, {1, 11, 11},
			 {12, 11, 20}, {12, 1, 10},
			 {13, 5, 15},
			 {8, 11, 20}, {8, 1, 10},
			 {7, 5, 15}, 
			 {6, 11, 20}, {6, 1, 10},
			 {5, 5, 15},
			 {2, 11, 20}, {2, 1, 10},
			 {3, 5, 15},

			 {90, 12, 20}, {90, 1, 8}, {90, 9, 10}, {90, 11, 11},
			 {89, 12, 20}, {89, 1, 8}, {89, 9, 10}, {89, 11, 11},
			 {91, 12, 20}, {91, 1, 8}, {91, 9, 10}, {91, 11, 11},
			 {99, 12, 20}, {99, 1, 8}, {99, 9, 10}, {99, 11, 11},
			 {88, 11, 20}, {88, 1, 10},
			 {87, 5, 15},
			 {92, 11, 20}, {92, 1, 10},
			 {93, 5, 15}, 
			 {94, 11, 20}, {94, 1, 10},
			 {95, 5, 15},
			 {98, 11, 20}, {98, 1, 10},
			 {97, 5, 15}},
			{{10, 10}, {30, 99}, {50, 99}, {50, 99}, {40, 99}, {1000, 99}, {100000, 99}},
		}
	};

	for(int i = 0; i < 3; i++) {
		// Roughly max full-killshots, and roughly max ships of different times and range lengths
		tcase cur = {int(1e5), int(1e5)-1, int(1e5)};
		for(int i = 0; i < 1e5-1; i++) {
			int likelyLive = (rand() % 8) == 0;
			if(likelyLive) {
				int tin = rand()%300;
				cur.ships.emplace_back(i+1, tin, tin + (rand()%300));
			} else {
				cur.ships.emplace_back(i+1, rand()%300, int(1e5 - rand()%300));
			}
		}
		for(int i = 0; i < 1e5; i++) {
			cur.times.emplace_back(rand()%int(1e5 / 2) + 1, rand()%int(1e5));
		}
		cases.push_back(cur);
	}

	int tc = 1;
	for(auto cur : cases) {
		stringstream file_prefix;
        file_prefix << "passage" << setw(3) << setfill('0') << (tc++);

        ofstream in(file_prefix.str() + ".in");
        ofstream out(file_prefix.str() + ".out");
		auto [d, n, a, ships, times] = cur;
		in << d << " " << n << " " << a << endl;
		for(auto [x, y, z] : ships) in << x << " " << y << " " << z << "\n";
		for(auto [x, y] : times) in << x << " " << y << "\n";
		out << solve(cur) << endl;
	}

	return 0;
}
