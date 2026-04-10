#include<iostream>

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
	bool full() {
		return (tail + 1) % maxsize == head;
	}
	bool empty() {
		return head == tail;
	}
	bool inque(int x) {
		if (full()) {
			return false;
		}
		data[head] = x;
		head = (head + 1) % maxsize;
		return true;
	}
	bool outque(int& x) {
		if (empty()) {
			return false;
		}
		x = data[head];
		head = (head + 1) % maxsize;
		return true;
	}
	bool gethead(int& x) {
		if (empty()) {
			return false;
		}
		x = data[head];
		return true;
	}
	bool gettail(int& x) {
		if (empty()) {
			return false;
		}
		x = data[(tail-1+maxsize)%maxsize];
		return true;
	}
	int getsize() {
		return (tail - head + maxsize) % maxsize;
	}
	void print() {
		if (empty()) {
			cout << "empty!" << endl;
			return;
		}
		cout << "ele is(head->tail):";
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
	
}