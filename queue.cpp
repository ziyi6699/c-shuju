//循环队列的实现，使用数组实现，队列满时不能再入队，队列空时不能再出队，支持获取队头和队尾元素以及获取队列大小的功能。
/*#include<iostream>

using namespace std;

class queue {
private:
	int* data;
	int head;//队头
	int tail;//队尾
	int maxsize;//总容量（实际-1个）
public:
	queue(int size) {//创建队列
		maxsize = size;
		data = new int[maxsize];
		head = tail = 0;
	}
	~queue() {//虚构函数释放内存
		delete[]data;
	}
	bool full() {//判断队列是否满
		return (tail + 1) % maxsize == head;//当tail的下一个位置是head时，说明队列满了
	}
	bool empty() {
		return head == tail;
	}
	bool inque(int x) {//入队
		if (full()) {
			return false;
		}
		data[tail] = x;
		tail = (tail + 1) % maxsize;//tail指向下一个位置
		return true;
	}
	bool outque(int& x) {//出队
		if (empty()) {
			return false;
		}
		x = data[head];
		head = (head + 1) % maxsize;
		return true;
	}
	bool gethead(int& x) {//获取队头元素
		if (empty()) {
			return false;
		}
		x = data[head];
		return true;
	}
	bool gettail(int& x) {//获取队尾元素
		if (empty()) {
			return false;
		}
		x = data[(tail-1+maxsize)%maxsize];
		return true;
	}
	int getsize() {//获取队列大小
		return (tail - head + maxsize) % maxsize;
	}
	void print() {//打印队列元素
		if (empty()) {
			cout << "empty!" << endl;
			return;
		}
		cout << "ele is(head->tail):" << endl;
		int i = head;
		while (i != tail) {
			cout << data[i] << "\n";
			i = (i + 1) % maxsize;
		}
		cout << "\n";
	}
};

int main() {
	queue s1(5);
	int x = 0;
	//入队
	s1.inque(1);
	s1.inque(2);
	s1.inque(3);
	s1.inque(4);
	s1.print();

	//获取队头和队尾元素以及队列大小
	if (s1.gethead(x)) {
		cout << "head:" << x << endl;
	}
	if (s1.gettail(x)) {
		cout << "tail:" << x << endl;
	}
	cout << "size:" << s1.getsize() << endl;
	//出队
	s1.outque(x);
	s1.print();
	//继续入队
	s1.inque(5);
	s1.print();
	s1.inque(6);
	//清除
	while (!s1.empty()) {
		s1. outque(x);
	}
	s1.print();
	return 0;
}*/

//STL队列
/*#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int>s1;//创建一个空队列(int类型)
	//push()函数用于向队列尾部添加元素
	s1.push(1);//入队
	s1.push(2);
	s1.push(3);

	cout << s1.front() << endl;//获取队头元素
	cout << s1.back() << endl;//获取队尾元素

	s1.pop();//出队，删除队头元素

	cout << s1.front() << endl;//获取新的队头元素

	cout << s1.size() << endl;//获取队列大小

	while(s1.size()>0) {
		s1.pop();
	}

	if (s1.empty()) {
		cout<<"empty!"<<endl;
	}
	else {
		cout << "not empty!" << endl;
	}

	return 0;
}*/

//再现stl

/*#include<iostream>
#include<queue>
using namespace std;

int main() {
	
	queue<int>s;
	
	s.push(1);
	s.push(11);
	s.push(111);
	s.push(1111);

	cout << "size=" << s.size() << endl;

	cout << "head:" << s.front() << endl;
	cout << "tail:" << s.back() << endl;

	s.pop();

	cout << "head':" << s.front() << endl;
	cout << "size:" << s.size() << endl;

	while (s.size() > 0/*或者!s.empty()) {
		s.pop();
	}
	
	cout << "size=" << s.size() << endl;
	return 0;
}*/


//数组队列(顺序队列)(可操作)

/*#include<iostream>
using namespace std;

class queue {
private:
	int* data;
	int head_pos;  // 重命名：避免与函数名 head 重名
	int tail_pos;  // 重命名：避免与函数名 tail 重名
	int maxsize;
	int count;     // 重命名：避免与 std::cout 冲突
public:
	queue(int size) {
		maxsize = size;
		data = new int[maxsize];
		head_pos = tail_pos = 0;
		count = 0;
	}
	~queue() {
		delete[] data;
	}
	bool empty() {
		return count == 0;
	}
	bool full() {
		return count == maxsize;
	}
	bool inqueue(int x) {
		if (full()) {
			std::cout << "is full" << endl;
			return false;
		}
		data[tail_pos] = x;
		tail_pos = (tail_pos + 1) % maxsize;
		count++;
		return true;
	}
	bool outqueue(int& x) {
		if (empty()) {
			std::cout << "is empty" << endl;
			return false;
		}
		x = data[head_pos];
		head_pos = (head_pos + 1) % maxsize;
		count--;
		return true;
	}
	bool head(int& x) {
		if (empty()) {
			std::cout << "is empty" << endl;
			return false;
		}
		x = data[head_pos];
		return true;
	}
	bool tail(int& x) {
		if (empty()) {
			std::cout << "is empty" << endl;
			return false;
		}
		x = data[(tail_pos - 1 + maxsize) % maxsize];
		return true;
	}
	void print() {
		if (empty()) {
			std::cout << "is empty" << endl;
			return;
		}
		std::cout << "head->tail: ";
		int i = head_pos;
		int c = 0;
		while (c < count) { // 使用计数器遍历，解决 print 死循环和越界问题
			std::cout << data[i] << " ";
			i = (i + 1) % maxsize;
			c++;
		}
		std::cout << endl;
	}
};

int main() {
	queue s(5);

	std::cout << "is empty?:" << (s.empty() ? "yes" : "no") << endl;

	std::cout << "input ele:" << endl;
	s.inqueue(11);
	s.inqueue(22);
	s.inqueue(33);

	std::cout << "is empty?:" << (s.empty() ? "yes" : "no") << endl;

	s.print();

	int i = 0;
	while (i != 5) {
		std::cout << "input your opration(1-inqueue,2-outqueue,3-gethead,4-gettail,5-exit):" << endl;
		cin >> i;
		int x;
		switch (i) {
		case 1: {
			std::cout << "input a number to inqueue:" << endl;
			cin >> x;
			s.inqueue(x); 
			std::cout << "queue is:" << endl;
			s.print();
			break;
		}
		case 2: {
			if (s.outqueue(x)) {
				std::cout << "outqueue: " << x << endl;
			}
			s.print();
			break;
		}
		case 3: {
			if (s.head(x)) {
				std::cout << "head is: " << x << endl;
			}
			break;
		}
		case 4: {
			if (s.tail(x)) {
				std::cout << "tail is: " << x << endl;
			}
			break;
		}
		case 5: {
			std::cout << "exiting..." << endl;
			break;
		}
		default:
			std::cout << "invalid input!" << endl;
			break;
		}
	}
	return 0;
}*/


