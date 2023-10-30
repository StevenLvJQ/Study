#include <iostream>
using namespace std;

char str1[100];
char str2[100];
int dp[100][100];

void solve(int m, int n) {
	for (int i = 1; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else if (dp[i - 1][j] >= dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
			}
			else if (dp[i - 1][j] < dp[i][j - 1]) {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
}


int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> str1[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> str2[i];
	}
	solve(m, n);
	cout << dp[m][n] << endl;


	return 0;
}