//1.结构体排序
/*#include <iostream>    
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int n = 300;

struct stu {
	int id;
	char name;
	int chinese_grade;
	int math_grade;
}a[n];

bool cmp(stu a, stu b) {
	if (a.chinese_grade > b.chinese_grade) {
		return 1;
	}
	else if (a.chinese_grade < b.chinese_grade) {
		return 0;
	}
	else {
		if (a.math_grade > b.math_grade) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int main() {
	int N = 0;
	cout << "input student num" << endl;
	cin >> N;
	if (N > 300) {
		printf("input N too mach");
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		cout << "input the " <<  i  <<" student imfo" << endl;
		cout << "input id:" ;
		cin >> a[i].id;
		cout << "input name:"  ;
		cin >> a[i].name;
		cout << "input chinese grade:"  ;
		cin >> a[i].chinese_grade;
		if (a[i].chinese_grade < 0 || a[i].chinese_grade>100) {
			cout << "grade error" << endl;
			return 0;
		}
		cout << "input math grade:" ;
		cin >> a[i].math_grade;
		if (a[i].math_grade < 0 || a[i].math_grade>100) {
			cout << "grade error" << endl;
			return 0;
		}
	}	
	sort(a + 1, a + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		cout << "no." << i << "\nid:" << a[i].id << " name:" << a[i].name << " chinese grade:" << a[i].chinese_grade
			<< " math grade:" << a[i].math_grade << endl;
	}
	return 0;
}*/

//2.定义多个圆
/*#include <iostream>
#include <vector> // 建议使用 vector 代替固定数组，更安全
using namespace std;

const double pi = 3.1415;

class Circle { // 类名通常首字母大写
private:
    double radius;
public:
    // 构造函数
    Circle() : radius(0) {};
    Circle(double rads) {
        radius = rads;
    }

    // 修改点 1: 返回类型改为 double，而不是 circle
    double getArea() const {
        return pi * radius * radius;
    }

    double getPerimeter() const { // 改名以避免与关键字或常见词混淆，原意为 prime (周长)
        return 2 * pi * radius;
    }

    // 这些静态工具函数不需要访问对象成员，可以设为 static，或者保留为普通函数
    // 修改点 2: 返回 double
    static double sumArea(double area, int n) {
        return area * n; // 数学上直接相乘即可，无需循环
    }

    static double sumPerimeter(double perimeter, int n) {
        return perimeter * n;
    }

    // 如果需要获取半径
    double getRadius() const {
        return radius;
    }
};

int main() {
    int n = 0; // 数量通常是整数
    cout << "input n:" << endl;
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input for n." << endl;
        return 1;
    }

    // 使用 vector 动态管理内存，避免固定大小数组的限制
    vector<double> radii(n);

    for (int i = 0; i < n; i++) {
        cout << "input the " << i << " radius:" << endl;
        cin >> radii[i];
    }

    cout << "--- Results ---" << endl;
    for (int i = 0; i < n; i++) {
        // 修改点 3: 创建对象，并调用成员函数获取数值
        Circle c(radii[i]);

        double areaVal = c.getArea();
        double primeVal = c.getPerimeter();

        // 修改点 4: 输出计算出的 double 数值，而不是对象本身
        cout << "Radius: " << c.getRadius()
            << ", Area: " << areaVal
            << ", Perimeter: " << primeVal << endl;
    }

    // 示例：计算所有圆的总面积（假设所有圆半径相同的情况下的累加逻辑演示）
    // 如果是要计算输入的所有不同圆的总面积，逻辑如下：
    double totalArea = 0;
    for (int i = 0; i < n; i++) {
        Circle c(radii[i]);
        totalArea += c.getArea();
    }
    cout << "Total Area of all circles: " << totalArea << endl;

    return 0;
}*/

/*#include<iostream>//循环练习

using namespace std;

int main() {
    int a = 1;
    while (a <= 5) {
        
        cout << "a=" << a << endl;
        a++;
    }
    for (int b = 1; b <= 5; b++) {
        cout << "b=" << b << endl;
        b += 1;
    }
    int c = 1;
    do {
        cout << "c=" << c << endl;
        c = c + 1;
        
    } while (c <= 5);



    return 0;
}*/

/*#include<iostream>//switch语句

using namespace std;

int main() {
    int grade = 0;
    cout << "input your grade(1-100)" << endl;
    cin >> grade;

    switch (grade/10) {
    case '10':
    case '9':
        cout << "A" << endl;
        break;
    case '8':
    case '7':
        cout << "B" << endl;
        break;
    case '6':
        cout << "C" << endl;
        break;
    default:
        cout << "D" << endl;
        break;

    }
    cout << "your grade is:" << grade << endl;
    return 0;
}*/

/*#include<iostream>//简单函数

using namespace std;

int max(int n1, int n2) {
    int result = 0;
    if (n1 > n2) {
        result = n1;
    }
    else {
        result = n2;
    }
    return result;
}

int main() {
    int n1 = 0, n2 = 0;
    cin >> n1;
    cin >> n2;
    int maxer=max(n1, n2);
    cout << "maxer=" << maxer << endl;
    return 0;
}*/


/*#include<iostream>//随机数
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 9; i++) {
        int j = rand();
        cout << "no." << i+1 << "=" << j << endl;
    }
    return 0;
}*/

/*#include<iostream>//限制输出的随机数
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    for (int i = 1; i < 10; i++) {
        int j = rand() % 50;
        cout << "no." << i << "=" << j << endl;
    }
    return 0;
}*/

/*#include<iostream>//约瑟夫环问题

using namespace std;

struct node {
    int id;
    node* next;
};

void yuesefu(int n, int k) {
    if (n <= 0 || k <= 0) {
        cout << "n and k must >0" << endl;
        exit(1);
    }

    node* head = new node{ 1,NULL };
    node* end = head;

    for (int i = 2; i <= n; i++) {
        end->next = new node{ i,NULL };
        end = end->next;
    }

    end->next = head;

    node* temp = end;


    while (temp->next != temp) {
        for (int i = 1; i < k;++i) {
            temp = temp->next;
        }

        node* de = temp->next;
        //cout << de->id << endl;
        temp->next = de->next;
        delete de;
    }
    cout << "last one is:" << temp->id << endl;
    //cout << temp->id << endl;
    delete temp;
}

int main() {
    int n, k;
    cout << "input n:" << endl;
    cin >> n;
    cout << "input k" << endl;
    cin >> k;
    yuesefu(n, k);
    return 0;
}*/

/*//循环队列的满队判断
#include<iostream>

using namespace std;

class queue {
private:
    int* data;
    int head;
    int tail;
    int max;
public:
    queue(int size) {
        max = size;
        data = new int[max];
        head = tail = 0;
    }
    ~queue() {
        delete[]data;
    }
    bool full() {
        return (tail + 1) % max == head;
    }
    bool empty() {
        return tail == head;
    }
    bool inqueue(int x) {
        if (full()) {
            cout << "full!" << endl;
            return false;
        }
        data[tail] = x;
        tail = (tail + 1) % max;
        return true;
    }
    bool outqueue(int& x) {
        if (empty()) {
            cout << "empty!" << endl;
        }
        x = data[head];
        head = (head + 1) % max;
        return true;
    }
    int getsize() {
        return(tail - head + max) % max;
    }
};
int main() {
    queue s1(6);
    s1.inqueue(11);
    s1.inqueue(22);
    s1.inqueue(33);
    s1.inqueue(44);
    s1.inqueue(55);
    if (s1.full()) {
        cout << "full!" << endl;
    }
    else {
        cout << "not full" << endl;
    }
    s1.inqueue(66);
    return 0;s
}*/


//  二叉树

/*#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

struct treenode {
   string val;
    treenode* left;
    treenode* right;
    treenode(string x) :val(x), right(NULL), left(NULL) {}
};


treenode* create(vector<string>nums) {
    if (nums.empty()||nums[0]=="#") {
        return NULL;
    }
    treenode* root = new treenode((nums[0]));
    queue<treenode*>q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        treenode* cur = q.front();
        q.pop();
        if (i < nums.size() && nums[i] != "#") {
            cur->left = new treenode((nums[i]));
            q.push(cur->left);
        }
        i++;
        if (i < nums.size() && nums[i] != "#") {
            cur->right = new treenode((nums[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int x=0;
treenode* create(vector<string>& nums) {
    if (x >= nums.size() || nums[x] == "#") {
        x++;
        return nullptr;
    }
    treenode* root = new treenode(nums[x]);
    x++;
    root->left = create(nums);
    root->right = create(nums);
    return root;
}

void before(treenode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    before(root->left);
    before(root->right);
}

int main() {
    vector<string>nums;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string token;
    while (ss >> token) {
        nums.push_back(token);
    }
    x = 0;
    treenode* root = create(nums);
    before(root);
    cout << endl;
    return 0;
}*/

