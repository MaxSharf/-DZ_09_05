#include <iostream>
using namespace std;
class Animal
{
public:
	string Name;
	string sound;
	string type;
	virtual void Sound() = 0;
	virtual void Show() = 0;
	virtual void Type() = 0;
};

class Sebek : virtual public Animal {
public:
	Sebek() {
		this->Name = "Bitkoin";
	}
	void Sound()override {
		this->sound = "zvyk padinna";
	}
	void Type()override {
		this->type = "dog";
	}
	void Show()override {
		cout << Name << endl;
		cout << type << endl;
		cout << sound << endl;
	}
};

class Cat :virtual public  Animal {
public:
	Cat() {
		this->Name = "Vasia";
	}
	void Sound()override {
		this->sound = "kyshat mnogo kyshat";
	}
	void Type()override {
		this->type = "cat";
	}
	void Show()override {
		cout << Name << endl;
		cout << type << endl;
		cout << sound << endl;
	}
};
class Papyga :virtual public  Animal {
public:
	Papyga() {
		this->Name = "Kesha";
	}
	void Sound()override {
		this->sound = "Gav Gav";
	}
	void Type()override {
		this->type = "Papyga";
	}
	void Show()override {
		cout << Name << endl;
		cout << type << endl;
		cout << sound << endl;
	}
};

class Node
{
public:
    int  value;
    Node* next;
    Node* prev;
    Node() {
        value = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int valueP) {
        value = valueP;
        next = nullptr;
        prev = nullptr;
    }
    int getValue() { return value; }
};

class List
{
public:
    Node* head;
    Node* tail;
    int length;
    List() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    virtual void Push(int elem) = 0;
    virtual void Pop() = 0;
    virtual void Print() = 0;
};


class Queue : virtual public List
{
public:
    void Pop()override {
        Node* tmp = new  Node();
        tmp = head;
        head = tmp->prev;
        head->next = nullptr;
        delete tmp;
    }
    void Push(int elem)override {
        Node* tmp = new  Node(elem);
        if (length == 0)
        {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        length++;
    }
    void Print()override {
        Node* tmp = new  Node();
        tmp = tail;
        while (tmp != nullptr) {
            cout << tmp->getValue() << ", ";
            tmp = tmp->next;
        }
    }
};

class Stack : virtual public List {

public:
    void Pop()override {
        Node* tmp = new Node();
        tmp = tail;
        tail = tmp->prev;
        tail->next = nullptr;
        delete tmp;
    }
    void Push(int elem)override {
        Node* tmp = new Node(elem);
        if (length == 0)
        {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        length++;
    }
};
int main()
{
    int size = 4;
    Animal** a = new  Animal * [size] {
        new Sebek(),
            new Cat(),
            new Papyga(),
    };

    for (size_t i = 0; i < size; i++) {
        a[i]->Type();
        a[i]->Sound();
        a[i]->Show();
    }

    List* l = new Queue();
    l->Push(1);
    l->Push(2);
    l->Print();
    return 0;
}