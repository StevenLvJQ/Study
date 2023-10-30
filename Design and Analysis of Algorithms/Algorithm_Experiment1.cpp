# include<iostream>
# include<vector> 
# include<iomanip>
# include<cmath>
using namespace std;

vector<vector<int>> arr;
int num = 1;

void find(int x, int y, int len, int& m, int& n) {
	for (int i = 0; i <= len - 1; i++) {
		for (int j = 0; j <= len - 1; j++) {
			if (arr[x + i][y + j] != 0) {
				m = x + i;
				n = y + j;
				return;
			}
		}
	}
}

// ��ȡλ�� 
int getDigit(int k) {
	int i = 0;
	int num = (pow(4, k) - 1) / 3;
	while (num - 10 > 0) {
		num /= 10;
		i++;
	}
	return ++i;
}

// ���ĸ���Ԫ���н������ 
void fillIn(int m, int n, int len) {
	if (len >= 2) {
		int lox = 0;
		int loy = 0;
		find(m, n, len, lox, loy);
		len /= 2;
		//����1 
		if (lox < m + len && loy < n + len) {
			arr[m + len][n + len] = num;
			arr[m + len - 1][n + len] = num;
			arr[m + len][n + len - 1] = num;
			fillIn(m, n, len);
			fillIn(m, n + len, len);
			fillIn(m + len, n, len);
			fillIn(m + len, n + len, len);
			//����3 
		}
		else if (lox >= m + len && loy < n + len) {
			arr[m + len - 1][n + len - 1] = num;
			arr[m + len - 1][n + len] = num;
			arr[m + len][n + len] = num;
			num++;
			fillIn(m, n, len);
			fillIn(m, n + len, len);
			fillIn(m + len, n, len);
			fillIn(m + len, n + len, len);
			//����2 
		}
		else if (lox < m + len && loy >= n + len) {
			arr[m + len - 1][n + len - 1] = num;
			arr[m + len][n + len - 1] = num;
			arr[m + len][n + len] = num;
			num++;
			fillIn(m, n, len);
			fillIn(m, n + len, len);
			fillIn(m + len, n, len);
			fillIn(m + len, n + len, len);
			//����4 
		}
		else {
			arr[m + len - 1][n + len - 1] = num;
			arr[m + len - 1][n + len] = num;
			arr[m + len][n + len - 1] = num;
			num++;
			fillIn(m, n, len);
			fillIn(m, n + len, len);
			fillIn(m + len, n, len);
			fillIn(m + len, n + len, len);
		}
	}
}

int main()
{
	// ���� 
	int k, x, y;
	cin >> k >> x >> y;
	if (x >= pow(2, k) || y >= pow(2, k)) {
		cout << "���볬����Χ" << endl;
		return -1;
	}
	// ��������
	vector<int> tmp(pow(2, k));
	arr.resize(pow(2, k), tmp);
	// ��������� 
	arr[x][y] = -1;
	// ��� 
	fillIn(0, 0, pow(2, k));
	// ��ȡλ��
	int digit = getDigit(k);
	// ��ʾ 
	for (int i = 0; i <= arr.size() - 1; i++)
	{
		for (int j = 0; j <= arr.size() - 1; j++)
		{
			cout << setiosflags(ios::left) << setw(digit + 1) << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
