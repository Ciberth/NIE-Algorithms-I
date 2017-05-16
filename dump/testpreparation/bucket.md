# Bucket

## Bucketsort

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

int findMax(vector<int> &v) {
    int max = v[0];

    for(int el : v) {
        if(el > max)
            max = el;
    }
    return max;
}

template <class T>
void bucketSort(vector<T> &v, int abuckets){

    if(v.size() > 1){
        T max = findMax(v);
        int partitionSize = (int) (max/abuckets) + 1; // grootte van de bucket 
        vector<vector<T>> buckets(abuckets);

        for(int i=0; i < v.size() ; i++){
            buckets[(int)(v[i]/partitionSize)%abuckets].push_back(v[i]);
        }

        for(int i=0; i < buckets.size() ; i++){
            insertionSort(buckets[i]);
        }

        int index = 0;

        for(int i=0; i < buckets.size() ; i++){
            for(int j=0; j < buckets[i].size() ; j++){
                v[index++] = buckets[i][j];
            }
        }

    }

}
```