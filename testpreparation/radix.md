# Radix

## Binaire quicksort (= radix-exchange sort)

```cpp


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