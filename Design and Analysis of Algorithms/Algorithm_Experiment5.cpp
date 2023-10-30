#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int graph[51][51];
int res[51];
int isDone[51];
int sum = 0;
vector<int> path;

bool isFull(int n) {
    for (int i = 1; i <= n; i++) {
        if (isDone[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void dijistra(int ori, int dest, int n) {
    //初始化目标数组
    for (int i = 1; i <= n; i++) {
        res[i] = graph[ori][i];
    }
    //初始化标志数组
    for (int i = 1; i <= n; i++) {
        isDone[i] = 0;
    }
    isDone[ori] = 1;
    int num = 2;
    int now = ori;
    int min;
    //下一次的点
    int lo = ori;
    while (!isFull(n)) {
        int orilo = lo;
        min = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (res[i] <= min && res[i] != -1 && isDone[i] == 0) {
                min = res[i];
                lo = i;
            }
        }
        if (lo == orilo) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (res[i] == -1 && graph[lo][i] != -1) {
                res[i] = min + graph[lo][i];
            }
            else if (res[i] != -1 && graph[lo][i] != -1
                && (graph[lo][i] + min) < res[i]) {
                res[i] = graph[lo][i] + min;
            }
        }
        isDone[lo] = num++;
    }
}

int main() {
    //输入
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    int ori, dest;
    cin >> ori >> dest;
    dijistra(ori, dest, n);
    cout << "The least distance from " << ori << "->" << dest << " is : " << res[dest] << endl;
    cout << endl;
    return 0;
}