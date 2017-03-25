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

- **Worst-case:** O(n log n)
- **Best-case:** O(n log n) 
- **Average-case:** depends on gap sequence 

### Key conceptual elements & notes:

- while in a for in a while
- shell = insertionSort with increments 



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


## Selection Sort 

### Attributes:

- **Worst-case:** O(n²)
- **Best-case:** O(n²)
- **Average-case:** O(n²)

### Key conceptual elements & notes:

- for in a for and swap
- search largest (or smallest) and swap 



```cpp

template <class T>
void selectionSort(vector<T> &v) {

    for(int i=v.size()-1 ; i > 0 ; i--) {
        int imax = i;
        for(int j = 0 ; j < i ; j++) {
            if (v[j]> v[imax])
                imax = j;
        }
        swap(v[i], v[imax]);
    }
}

```


## Quicksort 

### Attributes:

- **Worst-case:** O(n²)
- **Best-case:** O(n log n) (not that this is NOT a three-way partition with equal keys but rather the default quicksort)
- **Average-case:** O(n log n)

### Key conceptual elements & notes:

- dual while and a swap in a while next to a while in an if + recursion
- make pivot and check pivot increase/decrease pointers and recursion


```cpp

template <class T>
void quickSort(vector<T> &v, int l, int r) {

    if(l<r){

        T pivot = v[l];
        int i = l;
        int j = r;

        while(v[j] > pivot)
            j--;
        
        while(i < j) {
            swap(v[i], v[j]);
            i++;

            while(v[i] < pivot)
                i++;
            
            j--;
            while(v[j] > pivot)
                j--;
            
        }

        quickSort(v, l, j);
        quickSort(v, j+1, r);

    }

}

template <class T>
void quickSort(vector<T> &v) {
    quickSort(v, 0, v.size()-1);
}


```