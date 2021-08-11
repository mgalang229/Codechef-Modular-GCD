#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;

long long ModularExp(long long a, long long b, long long mod = MOD) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			// use __int128 since multiplying (10 ^ 12) to itself 
			// would result to (10 ^ 24), which is too large for long long
			res = ((__int128) res * a) % mod;
		}
		a = ((__int128) a * a) % mod;
		b >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long a, b, n;
		cin >> a >> b >> n;
		if (a == b) {
			// if a is equal to b, then simply output (a ^ n) + (b ^ n)
			cout << (ModularExp(a, n) + ModularExp(b, n)) % MOD;
		} else {
			// otherwise, follow the procedures (operations) in the problem statement
			// note: GCD(A, B) = GCD(B, A % B)
			// so we can say that: 
			// GCD((A ^ N) + (B ^ N), A - B) = GCD(A - B, ((A ^ N) + (B ^ N)) % (A - B))
			long long d = (ModularExp(a, n, a - b) + ModularExp(b, n, a - b)) % (a - b);
			cout << __gcd(d, a - b);
		}
		cout << '\n';
	}
	return 0;
}
