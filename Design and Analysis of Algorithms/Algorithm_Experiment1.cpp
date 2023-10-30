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

// 获取位数 
int getDigit(int k) {
	int i = 0;
	int num = (pow(4, k) - 1) / 3;
	while (num - 10 > 0) {
		num /= 10;
		i++;
	}
	return ++i;
}

// 在四个单元格中进行填充 
void fillIn(int m, int n, int len) {
	if (len >= 2) {
		int lox = 0;
		int loy = 0;
		find(m, n, len, lox, loy);
		len /= 2;
		//区域1 
		if (lox < m + len && loy < n + len) {
			arr[m + len][n + len] = num;
			arr[m + len - 1][n + len] = num;
			arr[m + len][n + len - 1] = num;
			fillIn(m, n, len);
			fillIn(m, n + len, len);
			fillIn(m + len, n, len);
			fillIn(m + len, n + len, len);
			//区域3 
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
			//区域2 
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
			//区域4 
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
	// 输入 
	int k, x, y;
	cin >> k >> x >> y;
	if (x >= pow(2, k) || y >= pow(2, k)) {
		cout << "输入超出范围" << endl;
		return -1;
	}
	// 定义数组
	vector<int> tmp(pow(2, k));
	arr.resize(pow(2, k), tmp);
	// 定义特殊点 
	arr[x][y] = -1;
	// 填充 
	fillIn(0, 0, pow(2, k));
	// 获取位数
	int digit = getDigit(k);
	// 显示 
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
