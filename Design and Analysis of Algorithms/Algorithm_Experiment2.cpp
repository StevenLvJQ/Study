#include <vector>
#include <iostream>
using namespace std;

int arr[22]; //记录输入的数值
int m[22][22]; //作dp数组
int lo[22][22]; //记录位置

void solve(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int len = 2; len <= n; len++) { //len是i-j的长度
		for (int i = 1; i <= n - len + 1; i++) { //i是起点
			int j = i + len - 1; //j是终点
			//先对m[i][j]附上初值，然后在用循环进行比较找到最好的切点
			m[i][j] = m[i + 1][j] + arr[i - 1] * arr[i] * arr[j];
			lo[i][j] = i;
			//用循环进行比较找到最好的切点
			for (int k = i + 1; k < j; k++) {
				int tmp = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (tmp < m[i][j]) {
					m[i][j] = tmp;
					lo[i][j] = k;
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> arr[i];
	}
	solve(arr, n);
	cout << m[1][n] << endl;

	return 0;
}