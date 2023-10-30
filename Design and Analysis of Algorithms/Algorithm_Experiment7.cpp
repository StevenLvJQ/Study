#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct res {
    int maxLoad;
    string seq;
};

vector<int> load;
string str = "";
res* result = new res();
int maxTmpLoad = 0;
int loada = 0;
int loadb = 0;

void solve(int id, int c1, int c2, int n) {
    if (id == n) {
        if (loada >= maxTmpLoad) {
            if ((result->maxLoad == 0) || (result->maxLoad != 0 && result->seq < str)) {
                result->maxLoad = loada;
                result->seq = str;
            }
        }
        maxTmpLoad = loada;
        return;
    }
    else if (loada + load[id] > c1 && loadb + load[id] > c2) {
        return;
    }
    string tmpStr = str;
    //选船1
    if (loada + load[id] <= c1) {
        loada += load[id];
        str += '1';
        solve(id + 1, c1, c2, n);
        loada -= load[id];
        str = tmpStr;
    }
    //选船2
    if (loadb + load[id] <= c2) {
        str += '0';
        loadb += load[id];
        solve(id + 1, c1, c2, n);
        loadb -= load[id];
        str = tmpStr;
    }
}

int main() {
    int num = 1;
    //输入部分
    int n, ld;
    while (cin >> n) {
        result->seq = "";
        result->maxLoad = 0;
        load.clear();
        str = "";
        loada = 0;
        loadb = 0;
        maxTmpLoad = 0;
        for (int i = 0; i < n; i++) {
            cin >> ld;
            load.push_back(ld);
        }
        int c1, c2;
        cin >> c1 >> c2;
        solve(0, c1, c2, n);
        cout << "Case " << num++ << endl;
        // cout << result.size() << endl;
        if (result->maxLoad == 0) {
            cout << "No" << endl;
        }
        else {
            cout << "bestw : " << result->maxLoad << " ,seq : " << result->seq << endl;
        }
    }
    return 0;
}