# Merge

## Merge Top Down (full size temp table)

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

## Merge Bottom Up 

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
void mergeBu(vector<T> &v) {

    vector<T> hulp(v.size());
    bool a = true;
    for(int i=2 ; i < v.size()*2 ; i*=2) {
        for(int j=0; j < v.size() ; j+=i) {
            if(a) {
                merge(v, j, i, hulp);
            } else {
                merge(hulp, j, i, v);
            }
        }
        a = !a;
    }
    if(!a) {
        for(int i=0; i < hulp.size() ; i++) 
            v[i] = move(hulp[i]);
    }
}
```