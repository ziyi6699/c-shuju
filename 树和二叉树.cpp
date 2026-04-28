//树是一种非线性数据结构
/*
术语	    定义	                                类比
根节点	    最顶端的节点，没有父节点	            公司的CEO
叶子节点	没有子节点的节点	                    基层员工
节点的度	该节点拥有的子节点个数	                直接下属人数
树的度	树中所有节点度的最大值	                    最多下属人数
深度	从根到该节点的边数 + 1（根深度为1）	        层级
高度	从该节点到最远叶子的边数 + 1（叶子高度为1）	下属层级深度
*/
//节点总数=所有节点度数sum+1;
//n个节点树有n-1个边(数据间的连线);

//树的三种存储表达
/*//双亲表示(找父节点快)
struct PTnode {
	int data;       // 节点数据
	int parent;     // 父节点在数组中的下标，-1表示根
};

//子表示(找子节点快)
struct CTnode {
	int child;              // 孩子节点下标
	CTnode* next;           // 下一个兄弟孩子
};
struct CTbox {
	int data;
	CTnode* fristchild; //第一个孩子为链表头
};

//孩子兄弟表示(最重要)
struct CSnode {
	int data;
	CSnode* firstchild;
	CSnode* nextchild;
};
*/


//基本二叉树

/*#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;*/

//两种节点定义
//左右定义
/*struct treenode {
	int val;
	treenode* left;
	treenode* right;
	treenode(int x) :val(x),left(NULL),right(NULL){}
};
//带父指针的节点定义

struct treenodewithparent {
	int val;
	treenodewithparent* left;
	treenodewithparent* right;
	treenodewithparent* parent;
	treenodewithparent(int x) :val(x), right(NULL), left(NULL),parent(NULL){}
}; 
*/

/*struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),right(NULL),left(NULL){}

};*/

/**
 * 前序创建二叉树
 * 输入序列如：1 2 4 -1 -1 5 -1 -1 3 -1 -1（-1表示空）
 *       1
 *      / \
 *     2   3
 *    / \
 *   4   5
 */

/*TreeNode* createTreePreOrder() {
	int val;
	cin >> val;
	if (val == -1) return nullptr;  // 空节点标记

	TreeNode* root = new TreeNode(val);
	root->left = createTreePreOrder();   // 递归创建左子树
	root->right = createTreePreOrder();  // 递归创建右子树
	return root;
}*/

/**
 * 层序创建二叉树
 * 输入：按层序的数组，-1表示空
 * 例如：[1, 2, 3, 4, 5, -1, -1] 创建
 *       1
 *      / \
 *     2   3
 *    / \
 *   4   5
 */

/*TreeNode* createTreelevelorder(vector<int>& nums) {
	if (nums.empty() || nums[0] == -1) {
		return nullptr;
	}
	TreeNode* root = new TreeNode(nums[0]);
	queue<TreeNode*>q;
	q.push(root);

	int i = 1;
	while (!q.empty() && i < nums.size()) {
		TreeNode* cur = q.front(); q.pop();
		// 左孩子
		if (i < nums.size() && nums[i] != -1) {
			cur->left = new TreeNode(nums[i]);
			q.push(cur->left);
		}
		i++;

		// 右孩子
		if (i < nums.size() && nums[i] != -1) {
			cur->right = new TreeNode(nums[i]);
			q.push(cur->right);
		}
		i++;
	}
	return root;
}

//遍历
//前序遍历
void before(TreeNode* root) {
	if (!root) {
		return;
	}
	cout << root->val << " ";
	before(root->left);
	before(root->right);
}

//中序遍历
//非递归(重要)
void inorder(TreeNode* root) {
	stack<TreeNode*>stk;
	TreeNode* cur = root;

	while (cur || !stk.empty()) {
		while (cur) {
			stk.push(cur);
			cur = cur->left;
		}
		cur = stk.top(); stk.pop();
		cout << cur->val << " ";
		cur = cur->right;
	}
}*/

//层序遍历
/*void levelwithlevel(TreeNode* root) {
	if (!root) {
		return;
	}
	queue<pair<TreeNode*, int>>q;//pair可以将两个数据存为一个数据体
	q.push({ root,1 });
	while (!q.empty()) {
		auto [cur, level] = q.front(); q.pop();
		cout << "Level " << level << ": " << cur->val << endl;

		if (cur->left) q.push({ cur->left, level + 1 });
		if (cur->right) q.push({ cur->right, level + 1 });
	}
}*/

/*void level(TreeNode* root) {
	if (!root) {
		return;
	}
	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty() ){
		TreeNode* cur = q.front(); 
		q.pop();
		cout << cur->val << " ";
		if (cur->left) {
			q.push(cur->left);
		}
		if (cur->right) {
			q.push(cur->right);
		}
	}
}

//后序

void after(TreeNode* root) {
	if (!root) {
		return;
	}
	after(root->left);
	after(root->right);
	cout << root->val << " ";
}

//求深度

int deep(TreeNode* root) {
	if (!root) {
		return 0;
	}
	return max(deep(root->left), deep(root->right));
}

//销毁树

void de(TreeNode* root) {
	if (!root) {
		return;
	}
	de(root->left);
	de(root->right);
	delete root;
}

int main() {
	vector<int>nums = { 1,2,3,4,5,6,-1 };
	TreeNode* root = createTreelevelorder(nums);

	cout << "前序:";
	before(root);
	cout << endl;
	
	cout << "中序:";
	inorder(root);
	cout << endl;

	cout << "后序:";
	after(root);
	cout << endl;

	cout << "层序:";
	level(root);
	cout << endl;

	cout << "深度:";
	deep(root);
	cout << endl;

	de(root);
	return 0;

}*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<sstream>
#include<queue>
using namespace std;

struct treenode {
	string val;
	treenode* left;
	treenode* right;
	treenode(string x):val(x),left(NULL),right(NULL){}
};

int idx = 0;
treenode* create_before(vector<string>&s) {
	if (idx >= s.size() || s[idx] == "#") {
		idx++;
		return NULL;
	}
	treenode* root = new treenode(s[idx]);
	idx++;
	root->left = create_before(s);
	root->right = create_before(s);
	return root;
}

treenode* create_level(vector<string>ss) {
	if (ss.empty() || ss[0] == "#") {
		return nullptr;
	}
	treenode* root = new treenode(ss[0]);
	queue<treenode*>q;
	q.push(root);
	int i = 1;
	while (!q.empty() && i <= ss.size()) {
		treenode* cur = q.front();
		q.pop();
		if (i < ss.size() && ss[i] != "#") {
			root->left = new treenode(ss[i]);
			q.push(cur->left);
		}
		i++;
		if (i < ss.size() && ss[i] != "#") {
			root->right = new treenode(ss[i]);
			q.push(cur->right);
		}
		i++;
	}
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

void level(treenode* root) {
	if (!root) {
		return;
	}
	vector<pair<treenode*, int>>qq;
	qq.push_back({ root,1 });
	while (!qq.empty()) {
		auto [cur, level] = qq.front();
		qq.pop_back();
		cout << "level:" << level << ":" << cur->val << endl;
		if (cur->left) {
			qq.push_back({ cur->left, level + 1 });
			qq.push_back({ cur->right,level + 1 });
		}
	}
}

int deep(treenode* root) {
	if (!root) {
		return -1;
	}
	return max(deep(root->left), deep(root->right));
}

void de(treenode* root) {
	if (!root) {
		return;
	}
	de(root->left);
	de(root->right);
	delete root;
}

int main() {
	vector<string>s;
	vector<string>ss;
	string s1, s2;
	cout << "输入第一个树(前序创建)：" << endl;
	getline(cin, s1);
	stringstream s11(s1);
	string token1;
	while (s11 >> token1) {
		s.push_back(token1);
	}
	idx = 0;
	treenode* root1 = create_before(s);
	cout << "前序遍历：";
	before(root1);
	cout << endl;
	cout << "层序遍历：";
	level(root1);
	cout << endl;
	cout << "深度：";
	deep(root1);
	cout << endl;
	de(root1);
	cout << "输入第二个树(层序创建):" << endl;
	getline(cin, s2);
	stringstream s22(s2);
	string token2;
	while (s22 >> token2) {
		ss.push_back(token2);
	}
	treenode* root2 = create_level(ss);
	cout << "前序遍历：";
	before(root2);
	cout << endl;
	cout << "层序遍历：";
	level(root2);
	cout << endl;
	cout << "深度：";
	deep(root2);
	cout << endl;
	de(root2);
	return 0;
}