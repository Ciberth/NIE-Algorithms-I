```cpp
#include<iostream>
#include<vector>

using namespace std;

// INSERTION SORT
template<class T>
void insertion_sort(vector<T> &v){
	for(int i=1; i<v.size(); i++){ 		// i=1
		T key = move(v[i]);
		int j= i-1;
		
		while(j >= 0 && key < v[j]){
			v[j+1] = move(v[j]);
			j--;			
		}
		v[j+1] = move(key);
	}	
}

// SHELL SORT
template<class T>
void shell_sort(vector<T> &v){
	vector<int> increments = { 1,4,9,20,46 }; 	// Tokuda
	int inc = increments.size()-1;
	int k = increments[inc];
	
	while(k >= 1){
		
		// insertion sort
		for(int i=1; i<v.size(); i++){
			T temp = move(v[i]);
			int j = i-1;
			
			while(j >= 0 && temp < v[j]){
				v[j+1] = move(v[j]);
				j--;
			}
			
			v[j+1] = move(temp);
		}	
		
		k = increments[inc--];
	}

}

// SELECTION SORT
template<class T>
void selection_sort(vector<T> &v){
	for(int i=v.size()-1; i>0; i--){
		int max = i;
		
		for(int j=0; j<i; j++){
			if(v[j] > v[max]){
				max = j;
			}
		}		
		swap(v[i], v[max]);
	}
}
```