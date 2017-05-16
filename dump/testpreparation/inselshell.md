# Ins + Sel + Shell 

## Insertion 

- Stabiel
- Rangschikt ter plaatse

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

## Selection

- Niet Stabiel
- Rangschikt ter plaatse 

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

## Shell 

- Niet stabiel 
- Rangschikt ter plaatse
- Insertion met incrementen

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