/*#include<iostream>

using namespace std;

struct cyclelist {
	int data;
	cyclelist* next;
};

cyclelist* node(int n) {
	if (n <= 0) {
		std::cout << "unable input" << "\n";
		return;
	}
	cyclelist* head = new cyclelist{ 1,NULL };
	cyclelist* end = head;
	for (int i = 2; i <= n; i++) {
		end->next = new cyclelist{ i,NULL };
		end = end->next;
	}
	end->next = head;
	return head;
}

void dele(cyclelist* head, int k, int n) {
	cyclelist* temp = head;
	for (int i = 1; i < k && temp != nullptr; ++i) {
		temp = temp->next;
	}
	cyclelist* de = temp->next;
	temp->next = de->next;
	delete de;
}

void insert(cyclelist* head, int data, int location) {
	cyclelist* newnode = new cyclelist;
	newnode->data = data;
	cyclelist* temp = head;
	for (int i = 0; i < location ; ++i) {
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void memory(cyclelist* head) {
	cyclelist* temp = head->next;
	while (temp != head) {
		cyclelist* nextnode = temp->next;
		delete temp;
		temp = nextnode;
	}
	head->next = head;
}

void print(cyclelist* head) {
	cyclelist* temp;
	temp = head->next;
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << endl;
}

int main() {
	int n = 0;
	std::cout << "input  first  num:" << endl;
	std::cin >> n;
	cyclelist* head = node(n);
	print(head);
	int x = 0;
	while (1) {
		std::cout << "please choice you wanna(1-insert,2-delet,3-exit):" << endl;
		cin >> x;
		if (x == 1) {
			int location = 0, data = 0;
			std::cout << "input your want to inert location:" << "\n";
			cin >> location;
			std::cout << "input your want to inert num:" << "\n";
			cin >> data;
			insert(head, data, location);
		}
	}

}*/