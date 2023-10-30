# include<iostream>
# include<vector>
using namespace std;

bool signList[10];
int length = 1;
int num = 0;

void traverse(int choice, int size) {
	if (length == size) {
		num++;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (signList[i] == 0) {
			if ((choice == 5) ||
				(choice == 1 && i != 3 && i != 7 && i != 9) ||
				(choice == 3 && i != 1 && i != 7 && i != 9) ||
				(choice == 7 && i != 3 && i != 1 && i != 9) ||
				(choice == 9 && i != 3 && i != 7 && i != 1) ||
				(choice == 2 && i != 8) ||
				(choice == 8 && i != 2) ||
				(choice == 4 && i != 6) ||
				(choice == 6 && i != 4 ||
					(choice == 1 && i == 3 && signList[2]) ||
					(choice == 1 && i == 7 && signList[4]) ||
					(choice == 1 && i == 9 && signList[5]) ||
					(choice == 3 && i == 1 && signList[2]) ||
					(choice == 3 && i == 7 && signList[5]) ||
					(choice == 3 && i == 9 && signList[6]) ||
					(choice == 7 && i == 1 && signList[4]) ||
					(choice == 7 && i == 3 && signList[5]) ||
					(choice == 7 && i == 9 && signList[8]) ||
					(choice == 9 && i == 1 && signList[5]) ||
					(choice == 9 && i == 3 && signList[6]) ||
					(choice == 9 && i == 7 && signList[8]) ||
					(choice == 2 && i == 8 && signList[5]) ||
					(choice == 8 && i == 2 && signList[5]) ||
					(choice == 4 && i == 6 && signList[5]) ||
					(choice == 6 && i == 4 && signList[5]))) {
				signList[i] = 1;
				length++;
				traverse(i, size);
				signList[i] = 0;
				length--;
			}
		}
	}
}

int main() {
	// 将标志列表初始化
	for (int i = 1; i <= 9; i++) {
		signList[i] = 0;
	}
	// size为手势密码长度
	for (int size = 4; size <= 9; size++) {
		int prenum = num;
		for (int i = 1; i <= 9; i++) {
			signList[i] = 1;
			//加入函数
			traverse(i, size);
			signList[i] = 0;
		}
		cout << "手势密码长度为" << size << "的个数为：" << num - prenum << endl;;
	}
	cout << "一共有" << num << "种" << endl;
	return 0;
}