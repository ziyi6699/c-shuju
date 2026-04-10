/*#include<iostream>//可实现键盘操作单向链表

using namespace std;

struct nodelist {
    int id;
    nodelist* next;
};

nodelist* crate (int n) {
    nodelist* head=nullptr, * tail=nullptr, * temp=nullptr;
    head = new nodelist;
    head->next = nullptr;
    tail = head;
    for (int i = 1; i <= n; i++) {
        temp = new nodelist;
        temp->id = i;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
    tail = nullptr;
    return head;
}

void change(nodelist* head, int n, int temp) {
    nodelist* p = head;
    for (int i = 0; i < n && p != nullptr;i++) {
        p = p->next;
    }
    if (p != nullptr) {
        p->id = temp;
    }
    else {
        std::cout << "can't find node" << endl;
        return;
    }
}

void insert(nodelist* head, int n, int temp) {
    nodelist* p = head;
    nodelist* in = new nodelist;
    for (int i = 0; i < n && p != nullptr; i++) {
        p = p->next;
    }
    if (p != nullptr) {
        in->id = temp;
        in->next = p->next;
        p->next = in;
    }
    else {
        std::cout << "can't find the node" << endl;
    }
}

void print(nodelist* head) {
    nodelist* temp;
    temp = head->next;
    while (temp != nullptr) {
        std::cout << temp->id << " ";
        temp = temp->next;
    }
    cout << endl;
   }


  void delet(nodelist* head, int n) {
    nodelist* p = head, * p1 = head;
    for (int i = 0; i < n && p != nullptr; i++) {
        p1 = p;
        p = p->next;
    }
    if (p != nullptr) {
        p1->next = p->next;
        delete p;
    }
    else {
        std::cout << "can't find the node" << endl;
    }
}

void memory(nodelist* head) {
    while (head != nullptr) {
        nodelist* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n = 0;
    cout << "input n:" << endl;
    cin >> n;
    nodelist*head=crate(n);
    cout << "the first list crate successed" << endl;
    print(head);
    while (1) {
        int x=-1 ;
        cout << "please choice your wanna(1-change,2-insert,3-delete,4-exit):" << endl;
        cin >> x;
        if (x == 1) {
            int n1 = 0, temp1 = 0;
            cout << "input want to change place:" << "\n";
            cin >> n1;
            cout << "input num:" << endl;
            cin >> temp1;
            change(head, n1, temp1);
            cout << "the new list is:" << "\n";
            print(head);
        }
        else if (x == 2) {
            int n2 = 0, temp2 = 0;
            cout << "input want to insert place after:" << "\n";
            cin >> n2;
            cout << "input num:" << endl;
            cin >> temp2;
            insert(head, n2, temp2);
            cout << "the new list is:" << "\n";
            print(head);
        }
        else if (x == 3) {
            int n3 = 0;
            cout << "input want to delet place:" << "\n";
            cin >> n3;
            delet(head, n3);
            cout << "the new list is:" << "\n";
            print(head);
        }
        else if (x == 4) {
            break;
        }
        else {
            cout << "error input" << endl;
        }
    }
    cout << "the final list is:" << "\n";
    print(head);
    memory(head);
    return 0;
}*/