```cpp
#include<iostream>
#include<vector>

using namespace std;


// BASIC QUICKSORT
template<class T>
void quicksort(vector<T> &v, int l, int r){
	
	if(l<r){
		T pivot = v[l]; 		// pivot links
								// pivot recht
								// pivot mediaan
		
		// mediaan van 3
		//int m = l + (r - l) / 2;
	   	//T pivot = max(min(v[l], v[m]), min(max(v[l], v[m]), v[r]));	
		
		int i = l;
		int j = r;
		
		while(v[i] < pivot)
			i++;
			
		while(v[j] > pivot)
			j--;
		
		while(i < j){
			swap(v[i], v[j]);
			i++,
			j--;
			
			while(v[i] < pivot)
				i++;
			
			while(v[j] > pivot)
				j--;
		}
		
		quicksort(v, l, j);
		quicksort(v, j+1, r);
	}
}

template<class T>
void quicksort(vector<T> &v){
	quicksort(v, 0, v.size()-1);
}


// JDK YAROSLAVSKIY
template<class T>
void quicksort_jdk(vector<T> &v, int l, int r){
	
	// 2 pivots (eerste < tweede)
	if(v[l] > v[r]){
		swap(v[l], v[r]);
	}
	T p1 = v[l];
	T p2 = v[r];
	
	int k = l+1;
	int m = k;
	int g = r-1;
	
	while(m <= g){
		if(v[m] < p1){
			swap(v[k], v[m]);
			k++;
			m++;
		}
		else if (v[m] > p2){
			swap(v[m], v[g]);
			g--;
		}
		else {
			m++;
		}
	}
	
	quicksort_jdk(v, l, k-1);
	quicksort_jdk(v, k+1, g-1);
	quicksort_jdk(v, g+1, r);
}

template<class T>
void quicksort_jdk(vector<T> &v){
	quicksort_jdk(v, 0, v.size()-1);
}
```