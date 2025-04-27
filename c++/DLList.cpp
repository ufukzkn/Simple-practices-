#include <iostream>

using namespace std;

class Item {
private:
    int value;
    Item* next;
    Item* prev;
public:
    Item(int value, Item* next, Item* prev) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
    int getValue() { return value; }
    Item* getNext() { return next; }
    Item* getPrev() { return prev; }
    void setValue(int v) { value = v; }
    void setNext(Item* p) { next = p; }
    void setPrev(Item* p) { prev = p; }
};

class DLList {
private:
    Item* head;
    Item* tail;
    int size;
public:
    DLList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool empty() { return size == 0; }
    
    Item* getFirst() { return head; }
    Item* getLast() { return tail; }
    Item* getNext(Item* p) { 
        if (p == NULL) return NULL;
        return p->getNext();
    }
    Item* getPrev(Item* p) {
        if (p == NULL) return NULL; 
        return p->getPrev();
    }
    int getSize() { return size; }
    int retrieve(Item* p) {
        if (p == NULL) return -1;
        return p->getValue();
    }

    void append(int x) {
        Item* newItem = new Item(x, NULL, tail);
        if (empty()) {
            head = newItem;
        } else {
            tail->setNext(newItem);
        }
        tail = newItem;
        size++;
    }

    void prepend(int x) {
        Item* newItem = new Item(x, head, NULL);
        if (empty()) {
            tail = newItem;
        } else {
            head->setPrev(newItem);
        }
        head = newItem;
        size++;
    }

    Item* locate(int x) {
        Item* current = head;
        while (current != NULL) {
            if (current->getValue() == x) {
                return current;
            }
            current = current->getNext();
        }
        return NULL;
    }

    bool insert(Item* p, int x) {
        if (p == NULL && !empty()) return false;
        
        if (empty() || p == NULL) {
            prepend(x);
            return true;
        }

        Item* current = head;
        while (current != NULL && current != p) {
            current = current->getNext();
        }
        
        if (current == NULL) return false;

        Item* newItem = new Item(x, current, current->getPrev());
        if (current->getPrev() != NULL) {
            current->getPrev()->setNext(newItem);
        } else {
            head = newItem;
        }
        current->setPrev(newItem);
        size++;
        return true;
    }

    bool del(Item* p) {
        if (p == NULL || empty()) return false;

        Item* current = head;
        while (current != NULL && current != p) {
            current = current->getNext();
        }

        if (current == NULL) return false;

        if (current == head) {
            head = current->getNext();
            if (head) head->setPrev(NULL);
            else tail = NULL;
        } else if (current == tail) {
            tail = current->getPrev();
            tail->setNext(NULL);
        } else {
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
        }

        delete current;
        size--;
        return true;
    }

    void clear() {
        while (!empty()) {
            Item* temp = head;
            head = head->getNext();
            delete temp;
        }
        head = tail = NULL;
        size = 0;
    }

    friend ostream& operator<<(ostream& out, DLList& l) {
        Item* current = l.head;
        while (current != NULL) {
            out << current->getValue() << " ";
            current = current->getNext();
        }
        return out;
    }

    ~DLList() {
        clear();
    }
};

int main(int argc, char** argv) {
    cout << endl << "Exercise 1 and 2 - tests" << endl;
    DLList* l = new DLList();
    
    cout << endl << "empty(): 1 -> " << l->empty();
    cout << endl << "getSize(): 0 -> " << l->getSize();
    cout << endl << "append(4): 4 -> "; l->append(4); cout << *l;
    cout << endl << "append(5): 4 5 -> "; l->append(5); cout << *l;
    cout << endl << "prepend(3): 3 4 5 -> "; l->prepend(3); cout << *l;
    cout << endl << "getSize(): 3 4 5 -> " << l->getSize();
    cout << endl << "prepend(2): 2 3 4 5 -> "; l->prepend(2); cout << *l;
    
    Item* pos = l->locate(3);
    cout << endl << "locate(3): found -> " << (pos != NULL);
    cout << endl << "located value is: " << pos->getValue(); // Print the value to verify it's 3
    cout << endl << "insert at 3's position with value 6: 2 6 3 4 5 -> "; 
    l->insert(pos, 6);
    cout << *l;
    cout << endl << "getSize(): 2 6 3 4 5 -> " << l->getSize();
    
    cout << endl << "delete at position of 3: 2 6 4 5 -> "; 
    l->del(pos);
    cout << *l;
    
    cout << endl << "clear list";
    l->clear();
    cout << endl << "empty(): 1 -> " << l->empty();
    cout << endl << "getSize(): 0 -> " << l->getSize();
    
    delete l;
    return 0;
}
