#include <vector>
#include <iostream>
using namespace std;

int arr[22]; //��¼�������ֵ
int m[22][22]; //��dp����
int lo[22][22]; //��¼λ��

void solve(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int len = 2; len <= n; len++) { //len��i-j�ĳ���
		for (int i = 1; i <= n - len + 1; i++) { //i�����
			int j = i + len - 1; //j���յ�
			//�ȶ�m[i][j]���ϳ�ֵ��Ȼ������ѭ�����бȽ��ҵ���õ��е�
			m[i][j] = m[i + 1][j] + arr[i - 1] * arr[i] * arr[j];
			lo[i][j] = i;
			//��ѭ�����бȽ��ҵ���õ��е�
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