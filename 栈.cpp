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