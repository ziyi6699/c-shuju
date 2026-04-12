//多个圆求和
//#include<iostream>
//#include<iomanip>

/*using namespace std;  //普通数组
const double pi = 3.1415;

class circel {
private:
	double radius;
public:
	circel() {
		radius = 0;
	}
	circel(double rads) : radius(rads) {}
	double area();
	double sumarea(circel circels[],int n);
};

double circel::area() {
	return pi * radius * radius;
}
double circel::sumarea(circel circels[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += circels[i].area();
	}
	return sum;
}


int main() {
	circel c[] = { 1,2,3 };
	double sum = c[0].sumarea(c,3);
	cout << "圆的计算结果：" <<sum<< endl;
	return 0;
}*/

//指针数组
/*using namespace std;
const double pi = 3.1415;

class circle {
private:
	double radius;
public:
	circle() {
		radius = 0;
	}
	circle(double rads) : radius(rads) {}
	double area();
	double sumarea(circle* circels[], int n);
};
circle* create(double rads) {
	circle* c = new circle(rads);
	return c;
}
double circle::area() {
	return pi * radius * radius;
}
double circle::sumarea(circle* circels[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += circels[i]->area();
	}
	return sum;
}

int main() {
	circle*c[]={create(1),create(2),create(3) };
	double sum = c[0]->sumarea(c, 3);
	cout<<"圆的计算结果："<<sum<<endl;
	return 0;
}*/


//多态实现
/*#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
const double pi = 3.1415;


class shape {
public:
	virtual double getArea() const = 0;
	virtual ~shape() {}
};

class circle : public shape {
private:
	double radius;
public:
	circle() {
		radius = 0;
	}
	circle(double r) : radius(r) {}
	double getArea() const override { return pi * radius * radius; }
};

class rect :public shape {
private:
	double high;
	double lon;
public:rect() {
		high = 0;
		lon = 0;
}
	  rect(double h, double l) : high(h), lon(l) {}
	double getArea() const override { return high * lon; }
};

class squ :public shape {
private:
	double side;
public:
	squ() {
		side = 0;
	}
	squ(double s):side(s){}
	double getArea() const override { return side * side; }

};

class tri :public shape {
private:
	double high;
	double base;
public:
	tri() {
		high = 0;
		base = 0;
	}
	tri(double h,double b):high(h),base(b){}
	double getArea() const override { return 0.5 * high * base; }
};

class ell :public shape {
	private:
	double a;
	double b;
public:
	ell() {
		a = 0;
		b = 0;
	}
	ell(double a,double b) :a(a), b(b){}
	double getArea() const override { return pi * a * b; }
};

int main() {
	shape* shapes[10] = {
		new circle(1.0),      
		new circle(2.5),
		new rect(3.0, 4.0), 
		new rect(2.0, 5.0),
		new squ(2.0),      
		new squ(3.5),
		new tri(3.0, 6.0),  
		new tri(4.0, 5.0),
		new circle(0.5),
		new rect(1.5, 2.0)
	};

	double totalArea = 0;

	cout << "各形状面积列表：" << endl;
	for (int i = 0; i < 10; ++i) {
		double area = shapes[i]->getArea();
		totalArea += area;
		cout << "形状 [" << i + 1 << "] 面积: " << area << endl;
	}

	cout << "\n10个几何图形的总面积和为: " << totalArea << endl;

	for (int i = 0; i < 10; ++i) {
		delete shapes[i];
	}

	return 0;
}*/


//波兰表达式求值(栈）

/*#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

class stack {
private:
	int* arr;
	int size;
	int top;
public:
	stack(int s) {
		arr = new int[size];
		size=s;
		top = -1;
	}
	~stack() {
		delete[]arr;
	}
	void push(int value) {
		if (top < size - 1) {
			arr[++top] = value;
		}
		else {
			cout << "栈满了！" << endl;
		}
	}
	int pop() {
		if (top >= 0) {
			return arr[top--];
		}
		else {
			cout << "栈空了！" << endl;
			return -1; // 返回-1表示栈空
		}
	}
	int peek() {
		if (top >= 0) {
			return arr[top];
		}
		else {
			cout << "栈空了！" << endl;
			return -1; // 返回-1表示栈空
		}
	}
	bool empty() {
		return top = -1;
	}
};

bool isop(const string& s) {
	return s == "+" || s == "-" || s == "*" || s == "/";
}

int main() {
	string line;
	cout << "请输入一个表达式：" << endl;
	getline(cin, line);
	stringstream ss(line);
	string token;
	vector<string> tokens;

	
	while (ss >> token) {
		tokens.push_back(token);
	}

	stack s(tokens.size());

	
	for (int i = tokens.size() - 1; i >= 0; i--) {
		if (!isop(tokens[i])) {
			
			s.push(stoi(tokens[i]));
		}
		else {
			
			int op1 = s.pop();
			int op2 = s.pop();

			if (tokens[i] == "+") s.push(op1 + op2);
			else if (tokens[i] == "-") s.push(op1 - op2);
			else if (tokens[i] == "*") s.push(op1 * op2);
			else if (tokens[i] == "/") {
				if (op2 != 0) s.push(op1 / op2);
				else {
					cout << "错误：除数为0" << endl;
					return -1;
				}
			}
		}
	}

	cout << "计算结果为: " << s.pop() << endl;

	return 0;
}*/



