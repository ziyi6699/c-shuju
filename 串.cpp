//串的基本操作
/*#include<iostream>
#include<string>
using namespace std;


int main() {
	//定义初始化串
	string s1;
	string s2 = "c plus plus";
	string s3 = s2;
	string s4(s2, 0, 5);//从s2下标0到5
	string s5(5, 's');//五个s


	//访问串
	string s = "hello";
	const char c1 = s[0];
	const char c2 = s.at(0);//可以检查边界，越界爆出异常
	const char c3 = s.at(1);
	const char first = s.front();//查看头
	const char tail = s.back();//查看尾
	const size_t len1 = s.length();
	const size_t len2 = s.size();//len1==len2
	const bool empty = s.empty();

	//修改操作
	s += " world";
	s.append("!");
	s.push_back('!');//等价于上式
	cout << s << endl;
	//1.下标遍历
	for (size_t i = 0; i < s.size(); i++) {
		cout << s[i] << "\n";
	}
	cout << endl;
	
	//插入
	s.insert(5, " c++");
	cout << s << endl;

	//删除
	string arr = "12345678";
	arr.erase(7);//从下标3开始删除到末尾
	cout << arr << endl;
	arr.erase(3, 3);//从下标5开始删三个元素
	cout << arr << endl;
	arr.clear();//删除所有元素

	//替换
	s.replace(6, 10, "c++");
	cout << s << endl;

	//查找
	string c = "hello world";
	size_t pos = c.find("world");
	cout << "find:" << pos << endl;
	pos = c.find('o');//首次出现o
	cout << "find:" << pos << endl;
	pos = c.rfind('o');//最后出现o
	cout << "find:" << pos << endl;

	//子串提取
	string sub = c.substr(6, 5);
	cout << sub << endl;

	return 0;
}*/

//模式匹配算法
//BF(暴力匹配)

/*#include<iostream>
#include<string>
using namespace std;

int BF(const string& S, const string& T) {
	int i = 0, j = 0;
	while (i < S.size() && j < T.size()) {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;//i从开头到下一位
			j = 0;
		}
	}
	if (j >= T.size()) {
		return i - T.size();
	}
	else {
		return -1;
	}
}

int main() {
	string S;
	string T;
	getline(cin,S);
	getline(cin, T);
	cout << "BF:" << BF(S, T) << endl;
	return 0;
}*/

//kmp算法
//KMP 算法利用 已匹配的信息 避免主串回溯。
// 当失配发生时，主串指针  i  不回溯，只移动模式串指针  j  到合适的位置。

/*#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getnext(const string& T, vector<int>& next) {
	int i = 0, j = -1;
	next[0] = -1;
	int len = (int)T.size();

	while (i < len - 1) {  //只计算到 next[len-1]
		if (j == -1 || T[i] == T[j]) {
			++i;
			++j;
			//处理相等字符
			if (T[i] != T[j]) {
				next[i] = j;
			}
			else {
				next[i] = next[j]; 
			}
		}
		else {
			j = next[j];
		}
	}
}

int kmp(const string& S, const string& T) {
	vector<int>next(T.size());
	getnext(T, next);

	int i = 0, j = 0;
	while (i < S.size() && j < (int)T.size()) {
		if (j == -1 || S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j >= T.size()) {
		return i - T.size()+1;
	}
	else {
		return -1;
	}
}

int main() {
	string S;
	string T;
	cout<<"input S:"<<endl;
	getline(cin, S);
	cout<<"input T:"<<endl;s
	getline(cin,T);
	cout << "找到子串位置在:" << kmp(S, T) << endl;
	return 0;
}*/

