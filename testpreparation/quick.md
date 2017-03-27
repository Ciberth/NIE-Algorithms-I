# Quick

## (Standard) Quicksort

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

## Dual Pivot Quicksort

```cpp
template <class T>
void dualPivot(vector<T> &v, int l, int r) {
    if (l < r) {

        T p1 = v[l];
        T p2 = v[r];

        if(p1 > p2) 
            swap(v[l], v[r]);

        int k = l + 1;
        int g = r - 1;
        int m = k;

        while(m<=g){
            if(v[m] < p1){
                swap(v[m], v[k]);
                m++;
                k++;
            } else if (v[m] > p2){
                swap(v[m], v[g]);
                g--;
            } else {
                m++;
            }
        }

        swap(v[l], v[k-1]);
        swap(v[r], v[g+1]);

        dualPivot(v, l, k-1);
        dualPivot(v, k, m-1);
        dualPivot(v, m, r);
    }
}

template <class T>
void dualPivot(vector<T> &v) {
    dualPivot(v, 0, v.size()-1);
}
```