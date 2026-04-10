/*#include<iostream>//单链表（全操作函数）

using namespace std;

struct list {//创建数据域
	int data;
	list* next;
};

list* creat(int n){//创建n个节点的链表
	list* head, *end,* temp;
	head = new list;//新节点
	head->next=nullptr;
	end = head;
	for (int i = 0; i < n; i++) {
		temp = new list;
		temp->data=i;
		temp->next=nullptr;
		end->next = temp;
		end = temp;
	}
	end->next=nullptr;
	return head;
}



list* find(list* head, int n) {//查找函数
	list* p2 = head;
	for (int i = 0; i < n && p2 != nullptr; i++) {
		p2 = p2->next;
	}
	if (p2 == nullptr) {
		cout << "can't find " << endl;
	}
	return p2;
}

void change(list* head, int n, int temp) {
	list* p3 = head;
	for (int i = 0; i < n && p3 != nullptr; i++) {
		p3 = p3->next;
	}
	if (p3 != nullptr) {
		p3->data = temp;
	}
	else {
		cout << "can't find" << endl;
	}
}

list* insert(list* head, int n, int data) {//插入函数
	list* p = head;
	list* in = new list;
	for (int i = 0; i < n && p != nullptr; i++) {
		p = p->next;
	}
	if (p != nullptr) {
		in->data = data;
		in->next = p->next;
		p->next = in;
	}
	else {
		cout << "can't find" << endl;
	}
	return head;
}

void print(list* head) {//打印函数
	list* temp;
	temp = head->next;
	while (temp != nullptr) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

//void print(list* head) {//打印函数2（可备选）
	//list* p1 = nullptr;
	//p1 = head->next;
	//while (p1 != nullptr) {
		//cout << "num=" << p1->data << ' ';
		//p1 = p1->next;
	//}
//}

void delet(list* head, int n) {//删除函数
	list* p = head, * p1 = head;
	for (int i = 0; i < n && p != nullptr; i++) {
		p1 = p;
		p = p->next;
	}
	if (p != nullptr) {
		p1->next = p->next;
		delete p;
	}
	else {
		cout << "can't find" << endl;
	}
}

void destroy(list* head) {//释放内存函数
	while (head != nullptr) {
		list* temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {//主操作函数
	int n = 6;
	
	list* head = creat(n);
	print(head);

	change(head, 2, 66);
	print(head);

	insert(head, 3, 666);
	print(head);

	delet(head, 1);
	print(head);

	destroy(head);

	return 0;
}*/