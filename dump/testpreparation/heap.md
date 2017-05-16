# Heap

## Create Heap

```cpp
template <class T>
void create_heap(vector<T> &v){
    for(int i= (v.size())/2-1 ; i>=0; i--){
        heapify(v, i, v.size());
    }
}
```

## Heapify 

```cpp
//1e mogelijkheid samenvoegen
template<class T>
void heapify(vector<T> & v, int i, int size){
    int index_left = i*2+1;
    int index_right = i*2+2;

    int greatest = i;

    if(index_left < size && v[index_left]>v[greatest])
        greatest = index_left;
    
    if(index_right < size && v[index_right]>v[greatest])
        greatest = index_right;

    if(greatest!=i){
        swap(v[i],v[greatest]);
        heapify(v, greatest, size);
    }
}
```

## Heapify Add 

```cpp
//2e mogelijkheid top down implementatie = minst efficient!!!
template <class T>
void heapify_add(vector<T> &v){
    for(int i =1 ; i<v.size() ; i++){
        int index = 1;
        int parent_index = (index-1)/2;
        T temp = move(v[index]);
        while(parent_index >= 0 && temp > v[parent_index]){
            v[index] = move(v[parent_index]);
            index = parent_index;
            parent_index = (index-1)/2;
        } // we zitten aan root of plaats vh nieuwe elem
        v[index] = move(temp);
    } 
}
```

## Heapsort

- Niet stabiel
- Ter plaatse

```cpp
template <class T>
void heapSort(vector<T> &v) {
    if(v.size() > 1){
        create_heap(v);
        for(int i=v.size()-1 ; i> 0; i--){
            swap(v[0], v[i]);
            heapify(v, 0, i);
        }
    }    
}
```

