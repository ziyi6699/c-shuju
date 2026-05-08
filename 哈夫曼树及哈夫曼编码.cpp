//哈夫曼树是最优二叉树
//哈夫曼编码是前缀编码
//编码不唯一，但最优长度唯一
//频率越高，编码越短
/*编写过程：
输入字符和频率
        ↓
创建初始结点（每个字符一个结点）
        ↓
放入小根堆 priority_queue
        ↓
重复：
    取出频率最小的两个结点
    合并成新结点
    再放回堆中
        ↓
堆中只剩一个结点
        ↓
得到哈夫曼树根结点
        ↓
递归遍历树
左边加 0，右边加 1
        ↓
得到每个字符的哈夫曼编码
*/


/*
Node：表示树中的一个结点
Compare：让 priority_queue 变成小根堆
构造过程：不断合并最小的两个结点
generateCode：递归生成编码
main：负责输入、建树、输出
*/

//链式haffman树

/*#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<string>
using namespace std;

struct node {
    char ch;
    int freq;//频率
    node* left;
    node* right;
    node(char c,int f):ch(c),freq(f),left(NULL),right(NULL){}
};

//比较器
struct compare {
    bool operator()(node* a, node* b){
        return a->freq > b->freq;
    }
};

//root(当前节点),path(根到节点的过程),codes(字符到编码的映射表)
void create(node* root, const string& path, map<char, string>& codes) {
    if (!root)return;
    if (!root->left && !root->right) {
        codes[root->ch] = path;
        return;
    }
    create(root->left, path + '0', codes);
    create(root->right, path + '1', codes);
}

void de(node* root) {
    if (!root)return;
    de(root->left);
    de(root->right);
    delete root;
}

int main() {
    vector<pair<char, int>>data = {
        {'a',5},
        {'b',9},
        {'c',12},
        {'d',13},
        {'e',16},
        {'f',45}
    };

    //优先队列，每次取compare中小的两节点
    priority_queue<node*, vector<node*>, compare>pq;

    //先把字符作为单独节点放入队列
    for (auto& p : data) {
        pq.push(new node(p.first, p.second));
    }

    while (pq.size() > 1) {
        node* left = pq.top();
        pq.pop();

        node* right = pq.top();
        pq.pop();

        node* parent = new node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    node* root = pq.top();

	map<char, string> codes;
    create(root, "", codes);
    cout << "haffman:\n";
    for (auto& p : codes) {
        cout << p.first << ":" << p.second << endl;
    }
    de(root);
    return 0;
}*/

//数组实现

/*#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

const int MAXN = 100;

// 哈夫曼树结点
struct HTNode {
    char ch;        // 字符
    int weight;     // 权值/频率
    int parent;     // 父结点下标
    int lchild;     // 左孩子下标
    int rchild;     // 右孩子下标
};

// 找到当前还没有父结点的两个最小权值结点
void selectMin(HTNode HT[], int end, int& s1, int& s2) {
    s1 = s2 = 0;

    // 先找第一个最小值
    for (int i = 1; i <= end; i++) {
        if (HT[i].parent == 0) {
            if (s1 == 0 || HT[i].weight < HT[s1].weight) {
                s2 = s1;
                s1 = i;
            }
            else if (s2 == 0 || HT[i].weight < HT[s2].weight) {
                s2 = i;
            }
        }
    }

    if (s1 > s2) swap(s1, s2);
}

// 构造哈夫曼树
void createHuffmanTree(HTNode HT[], int n) {
    int m = 2 * n - 1;   // 总结点数

    // 初始化所有结点
    for (int i = 1; i <= m; i++) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].weight = 0;
        HT[i].ch = '\0';
    }

    // 前 n 个结点存放叶子结点
    // 这里假设 HT[1..n] 已经赋好字符和权值

    // 依次构造内部结点
    for (int i = n + 1; i <= m; i++) {
        int s1, s2;
        selectMin(HT, i - 1, s1, s2);

        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// 生成每个字符的哈夫曼编码
void createHuffmanCode(HTNode HT[], int n, map<char, string>& codes) {
    for (int i = 1; i <= n; i++) {
        string code = "";
        int child = i;
        int parent = HT[i].parent;

        while (parent != 0) {
            if (HT[parent].lchild == child)
                code = '0' + code;
            else
                code = '1' + code;

            child = parent;
            parent = HT[parent].parent;
        }

        // 只有一个字符时，编码可能为空
        if (code.empty()) code = "0";

        codes[HT[i].ch] = code;
    }
}

// 编码字符串
string encode(const string& text, const map<char, string>& codes) {
    string result;
    for (char c : text) {
        auto it = codes.find(c);
        if (it != codes.end()) {
            result += it->second;
        }
    }
    return result;
}

// 解码字符串
string decode(const string& bits, HTNode HT[], int root, int n) {
    string result;
    int p = root;

    for (char b : bits) {
        if (b == '0') p = HT[p].lchild;
        else if (b == '1') p = HT[p].rchild;

        if (HT[p].lchild == 0 && HT[p].rchild == 0) {
            result += HT[p].ch;
            p = root;
        }
    }

    return result;
}

int main() {
    // 原始字符及其频率
    vector<pair<char, int>> data = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };

    int n = data.size();
    int m = 2 * n - 1;

    // 哈夫曼树数组，1~m 使用
    HTNode HT[MAXN];

    // 初始化前 n 个叶子结点
    for (int i = 1; i <= n; i++) {
        HT[i].ch = data[i - 1].first;
        HT[i].weight = data[i - 1].second;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // 构造哈夫曼树
    createHuffmanTree(HT, n);

    // 生成编码表
    map<char, string> codes;
    createHuffmanCode(HT, n, codes);

    // 输出编码表
    cout << "Huffman Codes:\n";
    for (auto& p : codes) {
        cout << p.first << " : " << p.second << endl;
    }

    // 测试编码
    string text = "abcdef";
    string encoded = encode(text, codes);

    cout << "\nOriginal text: " << text << endl;
    cout << "Encoded bits : " << encoded << endl;

    // 根节点下标就是最后一个结点
    int root = m;

    // 测试解码
    string decoded = decode(encoded, HT, root, n);
    cout << "Decoded text : " << decoded << endl;

    return 0;
}*/
