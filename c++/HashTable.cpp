#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    string* t;            
    int capacity;        
    int size;            
public:
    HashTable(int c) {
        capacity = c;
        size = 0;
        t = new string[capacity];
        for(int i = 0; i < capacity; i++) {
            t[i] = "";
        }
    }
    
    bool full() {
        return size == capacity;
    }
    
    bool empty() {
        return size == 0;
    }
    
    int hashF(string s) {
        int key = 0;
        for(char c : s) {
            key += (int)c;
        }
        return key%capacity;  // took the simplest one
    }
    void insert(string s) {
        if(full()) {
            cout << "Hash table is full" << endl;
            return;
        }
        
        int index = hashF(s);
        while(t[index] != "") {
            index = (index + 1) % capacity;//that's the linear probing thingy
        }
        t[index] = s;
        size++;
        cout << "Inserted " << s << " at position " << index << endl;
        print();
    }
    
    void del(string s) {
        int pos = search(s);
        if(pos == -1) {
            cout << "String not found" << endl;
            return;
        }
        t[pos] = "";
        size--;
        cout << "Deleted " << s << " from position " << pos << endl;
        print();
    }
    
    int search(string s) {
        int index = hashF(s);
        int startIndex = index;
        
        do {
            if(t[index] == s) {
                return index;
            }
            index = (index + 1) % capacity;
        } while(index != startIndex && t[index] != "");
        
        return -1;
    }
    
    void print() {
        cout << "\nHash Table Contents:" << endl;
        for(int i = 0; i < capacity; i++) {
            cout << i << ": " << (t[i] == "" ? "empty" : t[i]) << endl;
        }
        cout << endl;
    }
};

int main(int argc, char** argv) {
    int noOfStrings = 40;
    string testData[] = {"Julia", "Zuzanna", "Zofia", "Lena", "Maja", "Hanna", "Amelia", 
                        "Alicja", "Maria", "Aleksandra", "Oliwia", "Natalia", "Wiktoria", 
                        "Emilia", "Antonina", "Laura", "Pola", "Iga", "Anna", "Liliana", 
                        "Antoni", "Jakub", "Jan", "Szymon", "Franciszek", "Filip", 
                        "Aleksander", "Mikolaj", "Wojciech", "Kacper", "Adam", "Michal", 
                        "Marcel", "Stanislaw", "Wiktor", "Piotr", "Igor", "Leon", 
                        "Franciszek", "Mateusz"};

    HashTable ht(50);  // Create hash table with capacity 50
    
    // Test insertions
    cout << "Testing insertions:" << endl;
    for(int i = 0; i < noOfStrings; i++) {
        ht.insert(testData[i]);
    }
    
    // Test searching
    cout << "\nTesting searches:" << endl;
    cout << "Searching for 'Julia': " << ht.search("Julia") << endl;
    cout << "Searching for 'Franciszek': " << ht.search("Franciszek") << endl;
    cout << "Searching for 'Mateusz': " << ht.search("Mateusz") << endl;
    cout << "Searching for 'NotInTable': " << ht.search("NotInTable") << endl;
    
    // Test deletions
    cout << "\nTesting deletions:" << endl;
    ht.del("Julia");
    ht.del("Mateusz");
    ht.del("Franciszek");
    ht.del("NotInTable");
    
    return 0;
}
