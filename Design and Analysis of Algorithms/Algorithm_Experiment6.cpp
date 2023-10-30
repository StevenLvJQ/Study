#include <iostream>
using namespace std;

bool sign[9][9];
int gridsleft;
int path;
int a[8] = { 1,-1,1,-1,2,-2,2,-2 };
int b[8] = { 2,2,-2,-2,1,1,-1,-1 };
int ori_i, ori_j;
int dest_i, dest_j;

void solve(int x, int y) {
    if (80 - gridsleft > path) {
        return;
    }
    if (x == dest_i && y == dest_j) {
        path = 80 - gridsleft;
        return;
    }
    for (int i = 0; i <= 7; i++) {
        int tx = x + a[i];
        int ty = y + b[i];
        if (tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8 && !sign[tx][ty]) {
            gridsleft -= 1;
            sign[tx][ty] = 1;
            solve(tx, ty);
            gridsleft += 1;
            sign[tx][ty] = 0;
        }
    }
}


int main() {
    string ori, dest;
    while (cin >> ori >> dest) {
        gridsleft = 80;
        path = 81;
        ori_i = ori[1] - '0';
        dest_i = dest[1] - '0';
        ori_j = ori[0] - 'a' + 1;
        dest_j = dest[0] - 'a' + 1;
        sign[ori_i][ori_j] = 1;
        solve(ori_i, ori_j);
        cout << ori << "==>" << dest << ": " << path << " moves" << endl;
    }
    return 0;
}