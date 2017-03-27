```cpp
#include<iostream>
#include<vector>

using namespace std;


// BINAIR
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
	for(int i=1; i<v.size(); i++){ 		// i=1
		if(v[i] > v[imax]){
			imax = i;
		}
	}
	
	// binair patroon bepalen
	int bin = 1;
	while(bin < v[imax])
		bin = bin << 1; 		// shift left
	
	bin = bin >> 1;				// één teveel
	
	radixsort_binair(v, 0, v.size()-1, bin);
}








// TERNAIR
template <class T>
void radixSortTernair(vector<T> &v, int l , int r, int base) {
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
        radixSortTernair(v, l, k-1, base);
        radixSortTernair(v, k, g-1, base/10);
        radixSortTernair(v, g, r, base);
    }
}

template <class T>
void radixSortTernair(vector<T> &v) { 
	radixSortTernair(v, 0 , v.size()-1, 10);		//10 want max is 99
}






// LSD
template<class T>
void radixSortLSD(vector<T> &v) {
    if (v.size() > 1) {
    	
    	//Tabel van buckets met in elke bucket verschillende elementen (vector van vectoren)
    	int amount_buckets = 10;							//want getallen gaan tot 10, strings met 26
    	vector <vector<T>> buckets(amount_buckets);
    	
    	//Zoek max
        T max = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (max < v[i]) {
                max = v[i];
            }
        }       

        for (int i = 1; i <= max; i *= amount_buckets) {			//voor msd / door amount_buckets, i = max en i >=0
            // Buckets opvullen
            for (int j = 0; j < v.size(); j++) {
            	int index = (int) (v[j] / i) % amount_buckets;
                buckets[index].push_back(v[j]);
            }

            // Buckets legen
            int index = 0;
            for (int j = 0; j < amount_buckets; j++) {
                for (int k = 0; k < buckets[j].size(); k++) {
                    v[index++] = buckets[j][k];
                }

                // clear buckets
                buckets[j].clear();
            }
        }
    }
}
```