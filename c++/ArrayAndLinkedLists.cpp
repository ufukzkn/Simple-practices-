#include <iostream>
using namespace std;

//Exercise 1
//array based stack
class ArrayStack{
private:
        int* items;
        int capacity;
        int top;
    public:
        ArrayStack(int c){ //same but more recent usage: ArrayStack(int c) : capacity(c), top(-1) {  items = new int[capacity];}
            capacity = c;
            items = new int[capacity];
            top = -1;
        }        //creates an empty stack of capacity c
        bool empty(){
            return top==-1;
        }            //returns true if the stack is empty, false otherwise
        bool full(){
            return top==capacity-1;
        }            //returns true if the stack is full, false otherwise
        void push(int x){
            if (!full())
            {
            top++;
            items[top]=x;
            }
            else cout<<"can't push, stack is full\n";

        }        //inserts an item x into the stack
        int peek(){
            if (!empty())
                return items[top];
            else {
                cout << "can't peek, stack is empty\n";
                return -1;
            }
        }                //returns an item (value)
        void pop(){
            if (!empty()){
                items[top]=0;
                top--;
            }
            else cout<<"can't pop, stack is empty";

        }                //removes/destroys an item (value)
        void clear(){
            top = -1;
            for (int i=0;i<capacity;i++) items[i]=0;
        }            //removes all items
        void print(){
            for (int i=0;i<=top;i++) cout<<items[i]<<" ";
            cout <<"\n";
            if (top==-1) cout <<" printed nothing, the stack is empty";
        }            //prints the content of the stack
        //or
        friend std::ostream& operator<<(std::ostream& out, ArrayStack& s);
        ~ArrayStack();
};

ArrayStack::~ArrayStack() {
    delete[] items;
}

class Item {
private:
    int value;
    Item* next;
public:
    Item(int x, Item* next=nullptr) {
        this->value = x;
        this->next = next;
    }
    int getValue() {
        return value;
    }
    void setValue(int value) {
        this->value = value;
    }
    Item* getNext() {
        return next;
    }
    void setNext(Item* p) {
        next = p;
    }
};

class LinkedFifo {
private:
    Item* head;
    Item* tail;
public:
    LinkedFifo() {
        head = nullptr;
        tail = nullptr;
    }
    bool empty() {
        return (head == nullptr);
    }
    void enqueue(int x) {
        Item* newItem = new Item(x);
        if (tail) {
            tail->setNext(newItem);
        } else head = newItem;
        tail = newItem;
    }
    int peek() {
        if (!empty()) {
            return head->getValue();
        } else {
            cout << "Queue is empty\n";
            return -1;
        }
    }
    void dequeue() {
        if (!empty()) {
            Item* temp = head;
            head = head->getNext();
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            cout << "Queue is empty\n";
        }
    }
    void clear() {
        while (!empty()) {
            dequeue();
        }
    }
    void print() {
        Item* current = head;
        while (current) {
            cout << current->getValue() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
    ~LinkedFifo() {
        clear();
    }
};

int main() {
    cout << endl << "Exercise 1 - tests" << endl;

    ArrayStack s(5);

    cout << endl << "empty(): " << s.empty();
    s.print();
    if (s.empty()) cout <<" stack is empty";
    else cout <<" stack is not empty";

    cout << endl << "push(4): ";
    s.push(4);
    s.print();

    cout << endl << "push(2): ";
    s.push(2); 
    s.print();

    cout << endl << "peek(): " << s.peek()<<" ";

    cout << endl << "push(7): ";
    s.push(7);
    s.print();

    cout << endl << "empty(): " << s.empty(); 
    if (s.empty()) cout <<" stack is empty";
    else cout <<" stack is not empty";


    cout << endl << "pop(): ";
    s.pop();
    s.print();

    cout << endl << "clear(): ";
    s.clear();
    s.print();

    cout << endl << "Pushing to full stack:";
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.print();

    cout << endl << "Popping from empty stack:";
    s.clear();
    s.pop();

    cout << endl << endl << "Exercise 2 - tests" << endl;

    LinkedFifo q;

    cout << endl << "empty(): " << q.empty();
    q.print();

    cout << endl << "enqueue(4): ";
    q.enqueue(4);
    q.print();

    cout << endl << "enqueue(2): ";
    q.enqueue(2);
    q.print();

    cout << endl << "peek(): " << q.peek();

    cout << endl << "enqueue(7): ";
    q.enqueue(7);
    q.print();

    cout << endl << "empty(): " << q.empty();

    cout << endl << "dequeue(): ";
    q.dequeue();
    q.print();

    cout << endl << "clear(): ";
    q.clear();
    q.print();

    cout << endl << "Dequeuing from empty queue:";
    q.dequeue();

    cout << endl << "Multiple operations:";
    cout << endl << "using enqueue(1) ";
    q.enqueue(1);
    cout << endl << "using enqueue(2) ";
    q.enqueue(2);
    cout << endl << "using enqueue(3) ";
    q.enqueue(3);
    cout << endl << "Current queue: ";
    q.print();
    cout << endl << "using dequeue(): ";
    q.dequeue();
    cout << endl << "using enqueue(4): ";
    q.enqueue(4);
    cout << endl << "Current queue: ";
    q.print();

    return 0;
}
