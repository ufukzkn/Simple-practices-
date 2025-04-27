#include <iostream>
using namespace std;

//Exercise 1

class Heap{ //max-heap
    private:
        int* items;
        int capacity;
        int size;
    public:
        Heap(int c){
            this->capacity=c;
            this->size=0;
            this->items= new int[c];
            }                //create a heap of capacity c
        bool empty(){return size==0;}                //returns true if the heap is empty, false otherwise
        bool full(){return size==capacity;}                //returns true if the heap is full, false otherwise
        int getLeft(int i)
            {
            return 2*i+1;
            }            //returns the position (index) of the left child of i
        int getRight(int i)
            {
            return 2*i+2;
            }        //returns the position (index) of the right child of i
        int getParent(int i){
            return (i-1)/2;
        }        //returns the position (index) of the parent of i
        int getSize(){
            return size;
        }                //returns the size of the heap
        int getValue(int i)
        {
            return items[i];
        }        //return the value at position i
        
        void setValue(int i, int x){
            items[i]=x;
        }//sets the value at position i to be x
        void setSize(int s){size=s;}        //sets the size of the heap to be s
        void bottomUp(int i){
            while (getValue(i)>getValue(getParent(i)) && i>0)
            {
                swap(items[i],items[getParent(i)]);
                i=getParent(i);

            }
        }        //restore the heap ordering if the node at position i violates it
        void topDown(int i){
            int largest = i;
            int left = getLeft(i);
            int right = getRight(i);

            if (left < size && getValue(left) > getValue(largest))
                largest = left;

            if (right < size && getValue(right) > getValue(largest)) 
                largest = right;

            if (largest != i) {
                swap(items[i], items[largest]);
                topDown(largest);
            }
        }        //restore the heap ordering if the node at position i violates it
        bool insert(int x){
            if (!full()){
                items[size]=x;
                bottomUp(size);
                size++;
                return true;
            }
            return false;
        }            //inserts a node storing value x
        bool deleteMax(){ // it was bool but i actually didnt get why it is not void
            if(empty()) return false;
            
            items[0] = items[size-1];
            size--;
            
            if(size > 0) {
                topDown(0);
            }
            return true; 
        }            //delete the max node
        friend std::ostream& operator<<(std::ostream& out, Heap& h) {//ngl i took it from internet since i dont know how to use friend
    for (int i = 0; i < h.size; i++) {
        out << h.items[i] << " ";
    }
    return out;
}

};

#include <iostream>
using namespace std;

int main() {
    cout << "Exercise 1 - tests" << endl;

    Heap h(15);

    cout << "Initial heap: " << h << endl;

    cout << "empty(): " << h.empty() << " - Expected: 1" << endl;
    cout << "Heap state: " << h << endl;

    cout << "full(): " << h.full() << " - Expected: 0" << endl;
    cout << "Heap state: " << h << endl;

    h.insert(7);
    cout << "insert(7): " << h << " - Expected: 7" << endl;

    h.insert(10);
    cout << "insert(10): " << h << " - Expected: 10 7" << endl;

    h.insert(3);
    cout << "insert(3): " << h << " - Expected: 10 7 3" << endl;

    h.insert(15);
    cout << "insert(15): " << h << " - Expected: 15 10 3 7" << endl;

    h.deleteMax();
    cout << "Heap after deleteMax(): " << h << " - Expected: 10 7 3" << endl;

    cout << "empty(): " << h.empty() << " - Expected: 0" << endl;
    cout << "Heap state: " << h << endl;

    cout << "full(): " << h.full() << " - Expected: 0" << endl;
    cout << "Heap state: " << h << endl;

    return 0;
}
