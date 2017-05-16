```cpp
#include<iostream>
#include<vector>
#include "Eenvoudig.h"
using namespace std;

template<class T>
void bucketSort(vector<T> &v, int amount_buckets) {
    if (v.size() > 1) {
    	
    	//Buckets met elementen (vector van vectoren)
    	vector <vector<T>> buckets(amount_buckets);
    	
    	//Max vinden
        T max = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (max < v[i]) {
                max = v[i];
            }
        }
		
		//Onderverdelen in buckets
        int partition_size = (int) (max / amount_buckets) + 1;				//+1 niet vergeten
        for (int i = 0; i < v.size(); i++) {
        	int bucket = (int) (v[i] / partition_size % amount_buckets);	//mod want we willen enkel gehele getallen
            buckets[bucket].push_back(v[i]);
            
        }

        int index = 0;
        for (int i = 0; i < buckets.size(); i++) {
        	
        	//insertion sort over kleine vectoren om te sorteren
        	insertion_sort(buckets[i]);
			
			//terug kopieren.							
            for (int j = 0; j < buckets[i].size(); j++) {
                v[index] = move(buckets[i][j]);
                index++;
            }
        }
    }
}
```