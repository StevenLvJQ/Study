#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

//定义节点
struct node {
    int val;
    node* left;
    node* right;
    string str = "";
};

//仿函数
struct myGreater {
    bool operator() (node* nd1, node* nd2) {
        return nd1->val > nd2->val;
    }
};

//进行编码
void encode(node* pnd) {
    queue<node*> que;
    que.push(pnd);
    while (!que.empty()) {
        node* tmp = que.front();
        if (tmp->left != nullptr) {
            tmp->left->str = tmp->str + "0";
            que.push(tmp->left);
        }
        if (tmp->right != nullptr) {
            tmp->right->str = tmp->str + "1";
            que.push(tmp->right);
        }
        que.pop();
    }
}

//节点数组
node* nodes[100];

int main() {
    //输入部分
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        node* nd = new node;
        cin >> nd->val;
        nd->left = nullptr;
        nd->right = nullptr;
        nodes[i] = nd;
    }
    //特殊判断
    if (n == 1) {
        cout << nodes[0]->val << " 0" << endl;
        return 0;
    }
    else if (n == 2) {
        cout << max(nodes[0]->val, nodes[1]->val) << " 0" << endl;
        cout << min(nodes[0]->val, nodes[1]->val) << " 1" << endl;
        return 0;
    }
    //定义优先队列
    priority_queue < node*, vector<node*>, myGreater > que;
    for (int i = 0; i < n; i++) {
        que.push(nodes[i]);
    }
    //形成树结构
    node* fnode;
    while (!que.empty()) {
        fnode = new node;
        node* nd1 = que.top();
        que.pop();
        node* nd2 = que.top();
        que.pop();
        fnode->right = nd1;
        fnode->left = nd2;
        fnode->val = nd1->val + nd2->val;
        if (que.empty()) {
            break;
        }
        que.push(fnode);
    }
    encode(fnode);
    for (int i = 0; i < n; i++) {
        cout << nodes[i]->val << " " << nodes[i]->str << endl;
    }
    cout << endl;
    return 0;
}