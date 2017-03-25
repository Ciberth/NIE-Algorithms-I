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


## Dual pivot Quicksort (= Yaroslavskiy / JDK)


```cpp 

template <class T>
void dualPivot(vector<T> &v, int l, int r) {

    if (l < r) {

        T p1 = v[l];
        T p2 = v[r];

        if(p1 > p2) {
            v[l] = move(p2);
            v[r] = move(p1);
            p1 = v[l];
            p2 = v[r];
        }

        int k = l + 1;
        int g = r - 1;
        int m = k;

        while (m <= g) {

            if(v[m] < p1) {
                T temp = move(v[k]);
                v[k] = move(v[m]);
                v[m] = move(temp);
                k++;
            } else if (v[m] >= p2) {

                while(v[g] > p2 && m < g) {
                    g--;
                }

                T temp = move(v[g]);
                v[g] = move(v[m]);
                v[m] = move(temp);
                g--;

                if(v[m] < p1) {
                    T temp = move(v[m]);
                    v[m] = move(v[k]);
                    v[k] = temp;
                    k++;
                }
            }
            m++;
        }

        k = k - 1;
		g = g + 1;
		
		T temp = move(v[k]);
		v[k] = move(v[l]);
		v[l] = move(temp);

		temp = move(v[g]);
		v[g] = move(v[r]);
		v[r] = move(temp);


		dualPivot(v, l, k-1);
		dualPivot(v, k+1, g-1);
		dualPivot(v, g+1, r);

    }

}

template <class T>
void dualPivot(vector<T> &v) {
    dualPivot(v, 0, v.size()-1);
}



```

## Mergesort 

### Attributes:

- **Worst-case:** O(n log n)
- **Best-case:** O(n log n)
- **Average-case:** O(n log n)

### Key conceptual elements & notes:

- Recursion


```cpp

template <class T>
void merge(vector<T> & from, int begin, int mid, int end, vector<T> & temp) {

    int i=begin;
    int left=begin;
    int right=mid+1;

    while(left <= mid && right <= end) {
        temp[i++] = move(from[left] < from[right] ? from[left++] : from[right++]);
    }

    while(left <= mid) {
        temp[i++] = move(from[left++]);
    }

    while(right <= end) {
        temp[i++] = move(from[right++]);
    }

    for(int j = begin ; j <= end ; j++) {
        from[j] = move(temp[j]);
    }

}


template <class T>
void mergeSort(vector<T> &v, int l, int r, vector<T> & temp) {
    if (l < r-1) {
        int m = l+(r-l)/2;
        mergeSort(v, l, m, temp);
        mergeSort(v, m+1, r, temp);
        merge(v, l, m, r, temp);
    }
}

template <class T>
void mergeSort(vector<T> &v) {

    vector<int> temp(v);
    mergeSort(v, 0, v.size()-1, temp);

}



```


## Countingsort 

### Attributes:

- **Worst-case:** 
- **Best-case:** 
- **Average-case:** 

### Key conceptual elements & notes:

- Cummulative tabel
- We assume ints in this example 
- Theta(n+k) with n elements and k different keys

```cpp 


template <class T>
void countingSort(vector<T> &v) {
    
    int max = v[0];

    for(int i=1; i<v.size(); i++) {
        if(max < v[i])
            max = v[i];
    }
    
    vector<T> freq(max+1, 0);

    for(int i=0; i<v.size(); i++) {
        freq[v[i]]++;
    }

    // make cummulative
    for(int i=0; i<freq.size(); i++) {
        freq[i] += freq[i-1];
    }

    vector<T> sorted(v.size(), 0);

    for(int i=v.size()-1; i>=0; i--) {
         sorted[freq[v[i]]-1] = move(v[i]); // hier min 1!
        freq[v[i]]--;
    }

    v = move(sorted);

}

```


TODO 

LSD
MSD
BOTTOM UP MERGESORT 
