# Own (clean) overview part 1: Sorting Algorithms

This section will cover an overview of some implementations and short notices about the different sorting algorithms discussed in the course (on the other pages). Note that the worst, best and average cases under attributes relate to the performance (not space) complexity.


# Notice when you want to test yourself

All algorithms have been tested in the same way in the following context:

```cpp 
template <class T>
void printVector(vector<T> &v) {
    for(T el : v) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {

    vector<int> v;
    
    v.push_back(3);
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(10);
    v.push_back(12);
    // if you want to see visually what the strenghts and weaknesses are of some algorithms
    //v.push_back(100000000); 
    

    cout << "Start vector:" << endl;
    printVector(v);


    // type of sort for example: insertionSort(v);

    
    cout << "Vector after sort:" << endl;
    printVector(v);

    return 0;
}

```


## Insertion Sort 

### Attributes:

- **Worst-case:** O(n²) comparisons, swaps
- **Best-case:** O(n) comparisons, O(1) swaps
- **Average-case:** O(n²) comparisons, swaps 

### Key conceptual elements & notes:

- while in a for 
- make use of a temporary element when moving


```cpp

template <class T>
void insertionSort(vector<T> &v) {
    
   for(int i=1 ; i<v.size() ; i++) {

        T temp = move(v[i]);
        int j = i-1;
        while(j>= 0 && temp < v[j]) {
            v[j+1] = move(v[j]);
            j--;
        }
        v[j+1] = move(temp);
   }
}

```


## Shell Sort 

### Attributes:

- **Worst-case:** O(n log n) comparisons, swaps
- **Best-case:** O(n log n) comparisons, O(1) swaps
- **Average-case:** depends on gap sequence 

### Key conceptual elements & notes:

- shell = insertionSort with increments 
- while in a for in a while


```cpp

template <class T>
void shellSort(vector<T> &v) {

    vector<int> increments = {1, 4, 9, 20, 46}; // Tokuda
    int inc = 0; 
    int k = increments[inc]; // first increment

    while (k >= 1) {
        for(int i=k ; i<v.size() ; i++) {
            T temp = move(v[i]);
            int j = i-k;

            while(j>= 0 && temp < v[j]){
                v[j+k] = move(v[j]);
                j -= k;
            }
            v[j+k] = move(temp);
        }
        k = increments[++inc]; // next increment
    }
}


```