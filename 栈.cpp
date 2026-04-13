//链表栈
/*#include<iostream>
#include <stdexcept>

using namespace std;

struct node {//创建链表
	int data;
	node* next;
};

class stack {//创建栈区
private:
	node* head;
public:
	stack():head(nullptr){}
	~stack();
	void push(int x);
	void print();
	int pop();
	int peek();
	bool empty();
};

stack::~stack() {//释放内存函数
	while (!empty()) {
		pop();
	}
}

void stack::push(int x) {//栈顶输入元素
	node* temp = new node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

bool stack::empty(){//判断栈头是否为空
	return head == nullptr;
}

int stack::pop() {//弹出栈顶元素
	if (empty()) {
		throw std::underflow_error("the head is free");
	}
	node* temp = head;
	head = head->next;
	int pop = temp->data;
	delete temp;
	return pop;
}

int stack::peek() {//查看栈顶元素
	if (!empty()) {
		return head->data;
	}
	throw std::underflow_error("the head is free");
}

void stack::print() {
	if (empty()) {
		cout << "nothing in stack" << endl;
	}
	node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp=temp->next;
	}
	cout << endl;
}
int main() {
	try {
		stack s;
		//测试初始是否为空
		cout << "check the s" << endl;
		cout << (s.empty()? "yes" : "no" )<< endl;

		//塞入元素
		cout << "the ele is" << endl;
		s.push(10);
		s.push(20);
		s.push(100);
		s.print();

		//检测头元素
		cout << "the head ele is" << s.peek() << "\n";
		s.print();

		//弹出头元素
		cout << "out the head" << endl;
		cout << s.pop() << "\n";
		s.print();


	}
	catch (const std::underflow_error& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	cout << "test end" << endl;
	return 0;
	
}*/

//STL实现栈

/*#include<iostream>
#include<stack>
using namespace std;

int main() {
	std::stack<int>s;//建栈

	s.push(11);//压栈
	s.push(22);
	s.push(33);

	std::cout << "first is:" << s.top() << endl;

	s.pop();//弹栈

	std::cout << "first' is:" << s.top() << endl;//栈顶
	std::cout << "size is:" << s.size() << endl;//大小
	std::cout << "is empty?:" << (s.empty()?"yes":"no") << endl;//判断空

	while (!s.empty()) {//遍历弹栈
		std::cout << "ele is:" << s.top() << "\n";
		s.pop();
	}
	std::cout << endl;
	std::cout << "is empty?:" << (s.empty() ? "yes" : "no") << endl;
	return 0;
}*/

//数组栈

/*#include<iostream>
#include <stdexcept>
using namespace std;

class stack {
private:
	int* arr;
	int topidx;
	int maxsize;
public:
	stack(int size) {
		maxsize = size;
		arr = new int[maxsize];
		topidx = -1;
	}
	~stack() {
		delete[]arr;
	}
	bool empty() {
		return topidx == -1;
	}
	bool full() {
		return topidx == maxsize - 1;
	}
	void push(int x) {
		if (full()) {
			std::cout << "is full" << "\n";
			return;
		}
		arr[++topidx] = x;
	}
	int pop() {
		if (empty()) {
			std::cout << "is empty" << "\n";
			throw std::underflow_error("is empty");
		}
		int x = arr[topidx--];
		return x;
	}
	int peek(){
		if (empty()) {
			throw std::underflow_error("is empty");
		}
		return arr[topidx];
	}
	void print() {
		if (empty()) {
			std::cout << "is empty" << endl;
			return;
		}
		std::cout << "stack elements:";
		for (int i = topidx; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		/*while(i!=-1){
		 cout << arr[i] << " ";
		 i--;
		 }
		cout << endl;
		
	}
};

int main() {
	stack s(5);
	cout << "is empty?" << "\n" << (s.empty() ? "yes" : "no") << endl;
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
	s.push(55);
	s.print();
	cout << "the first element is:" << s.peek() << endl;
	cout << "pop:" << s.pop() << endl;
	cout << "the first element is:" << s.peek() << endl;
	while (!s.empty()) {
		cout << "pop:" << s.pop() << endl;
	}
	cout << "is empty?" << "\n" << (s.empty() ? "yes" : "no") << endl;
	return 0;
}*/

//栈的应用
//前缀表达式

/*#include<iostream>//lzy
#include<stack>
using namespace std;

bool isop(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
bool isnum(char c) {
	return c >= '0' && c <= '9';
}
int cal(int a, int b, char op) {
	switch (op) {
	case'+':return a + b;
	case'-':return a - b;
	case'*':return a * b;
	case'/':return a / b;
	default:
		cout << "invaild";
		return 0;
	}
}
void print(std::stack<int> s) {
	std::cout << " 栈底[栈内: ";
	std::stack<int> tempStack;
	// 倒序显示先转存
	while (!s.empty()) {
		tempStack.push(s.top());
		s.pop();
	}
	while (!tempStack.empty()) {
		std::cout << tempStack.top() << (tempStack.size() > 1 ? ", " : "");
		tempStack.pop();
	}
	std::cout << "]栈顶";
}


int polish(char* exp) {
	std::stack<int>s;
	int len = 0;//初始化计数器
	while (exp[len] != '\0') {
		++len;//遍历到最后的\0	
	}
	const char* p = exp + len - 1;//定位到\0前的最后一个字符
	std::cout << "\n=== 前缀表达式求值 ===" << std::endl;
	std::cout << "表达式: " << exp << std::endl;
	while (p >= exp) {
		while (p >= exp && *p == ' ')--p;
		if (p < exp) {
			break;
		}

		if (isnum(*p)) {
			int num = 0;
			int base = 1;// 位数权重：个位=1，十位=10
			while (p >= exp && isnum(*p)) {
				num = num + (*p - '0') * base;
				base *= 10;
				--p;
			}
			s.push(num);
			std::cout << "入栈: " << num;
			print(s);
			std::cout << endl;
		}
		else if (isop(*p)) {
			char op = *p;
			--p;
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			int result = cal(left, right, op);
			s.push(result);
			std::cout << left << " " << op << " " << right << " " << "=" << result << endl;
			print(s);
			std::cout << endl;
		}
		else {
			--p;
		}
	}
	return s.top();
}

int main() {
	std::cout << "输入前缀表达式 (例如: - + 10 20 5):" << std::endl;
	char pre[100];
	if (cin.getline(pre, 100)) {
		int result1 = polish(pre);
		std::cout << "\n最终结果 = " << result1 << std::endl;
	}
	return 0;
}*/
