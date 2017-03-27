# Radix

## Binaire quicksort (= radix-exchange sort)

```cpp
template<class T>
void radixsort_binair(vector<T> &v, int l, int r, int bin){
    if(l < r && bin){

        int i = l;
        int j = r;

        while(!(v[i] & bin))
            i++;

        while(v[j] & bin)
            j--;

        while(i < j){
            swap(v[i], v[j]);
            i++;
            j--;

            while(!(v[i] & bin))
                i++;

            while(v[j] & bin)
                j--;
        }

        bin = bin >> 1; 

        radixsort_binair(v, l, j, bin);
        radixsort_binair(v, j+1, r, bin);

    }
}

template<class T>
void radixsort_binair(vector<T> &v){
    // max bepalen
    int imax = 0;
    for(int i=1; i<v.size(); i++){         // i=1
        if(v[i] > v[imax]){
            imax = i;
        }
    }

    // binair patroon bepalen
    int bin = 1;
    while(bin < v[imax])
        bin = bin << 1;     // shift left

    bin = bin >> 1;         // één teveel

    radixsort_binair(v, 0, v.size()-1, bin);
}




```

## Ternaire radix quicksort 

```cpp
template <class T>
void tqs(vector<T> &v, int l , int r, int base) {
    if(l < r && base != 0){
        int p = v[l]/ base % 10;
        int vm = v[l] / base % 10;
        int m = l, k = l, g = r+1;
        while(m<g){
            if(vm<p){
                swap(v[m], v[k]);
                m++;
                k++;
            } else if(vm > p){
                swap(v[m], v[g-1]);
                g--;
            } else {
                m++;
            }
            vm = v[m]/base%10;
        }
        tqs(v, l, k-1, base);
        tqs(v, k, g-1, base/10);
        tqs(v, g, r, base);
    }
}
```

## LSD

```cpp
int findMax(vector<int> &v) {
    int max = v[0];

    for(int el : v) {
        if(el > max)
            max = el;
    }
    return max;
}

template <class T>
void lsd(vector<T> &v) {

    if(v.size() > 1){
        T max = findMax(v);
        int abuckets = 10;
        vector<vector<T>> buckets(abuckets);
        for(int i=1; i <=max ; i *= abuckets) {
            for(int j=0 ; j <v.size(); j++){
                buckets[(int)(v[j]/i)%abuckets].push_back(v[j]);
            }
            int index = 0;

            for(int j=0; j <abuckets ; j++){
                for(int k=0 ; k <buckets[j].size() ; k++){
                    v[index++] = buckets[j][k];
                }
                buckets[j].clear();
            }
        }
    }

}
```