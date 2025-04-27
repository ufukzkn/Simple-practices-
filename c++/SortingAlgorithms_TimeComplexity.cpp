#include <iostream>
#include <ctime>

using namespace std;

void fill(int* S, int n){
    for(int i = 0; i < n; i++) {
        S[i] = rand() % 101; 
                            
    }
}

void print(int* S, int n){
    for(int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

void selectionSort(int* S, int n){
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(S[j] < S[minIndex]) {
                minIndex = j;
            }
        }
        swap(S[i], S[minIndex]);
    }
}

void bubbleSort(int* S, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(S[j] > S[j+1]) {
                swap(S[j], S[j+1]);
            }
        }
    }
}

void quicksort(int* t, int left, int right){
    if(left < right) {
        int pivot = t[right];
        int i = left - 1;
        for(int j = left; j < right; j++) {//i for the smaller ones, j for the larger ones
            if(t[j] < pivot) {             
                i++;
                swap(t[i], t[j]);
            }
        }
        swap(t[i + 1], t[right]);   //now pivot is just after the small ones
        int pivotIndex = i + 1;

        quicksort(t, left, pivotIndex - 1);     //used the simplest partition according to the web
        quicksort(t, pivotIndex + 1, right);    //basically just putting the mostright to the between 
                                                // smaller and larger repeating until they all are sorted 
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    // Exercise 1 - tests
    cout << endl << "Exercise 1 - tests" << endl;
    {
        int n = 20;    
        int* S = new int[n];
        cout << "\nTesting selectionSort" << endl;
        fill(S, n);
        print(S, n);
        selectionSort(S, n);
        print(S, n);
        delete [] S;

        S = new int[n];
        cout << "\nTesting bubbleSort" << endl;
        fill(S, n);
        print(S, n);
        bubbleSort(S, n);
        print(S, n);
        delete [] S;
    }

    // Exercise 2 and 3 - tests
    cout << endl << "Exercise 2 and 3 - tests" << endl;
    {
        int sizes[] = {1000, 5000, 10000, 20000};
        
        for(int n : sizes) {
            cout << "\nTesting with array size: " << n << endl;
            
            int* S1 = new int[n];
            int* S2 = new int[n];
            int* S3 = new int[n];
            
            fill(S1, n);
            copy(S1, S1 + n, S2);
            copy(S1, S1 + n, S3);
            
            clock_t start, end;
            double result_time;
            
            
            start = clock();
            selectionSort(S1, n);
            end = clock();
            result_time = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "SelectionSort time: " << result_time << " seconds" << endl;
            
            
            start = clock();
            bubbleSort(S2, n);
            end = clock();
            result_time = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "BubbleSort time: " << result_time << " seconds" << endl;
            
            
            start = clock();
            quicksort(S3, 0, n-1);
            end = clock();
            result_time = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "QuickSort time: " << result_time << " seconds" << endl;
            
            delete [] S1;
            delete [] S2;
            delete [] S3;
        }
    }
    return 0;
}

/*
as we can see the quicksort is literally "quick"
I couldnt even measure the time for the small arrays with seconds
time complexity for the first two sorting methods are seems to be O(n^2)
but bubble is almost always slower since it does too much swappings so it works closer to
the worst case scenario
but the quicksort has a O(n logn) soooo it is faster?
*/
