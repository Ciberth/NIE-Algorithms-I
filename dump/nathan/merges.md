```cpp
#include<iostream>
#include<vector>

using namespace std;

template<class T>
void merge(vector<T> &v, vector<T> &h, int l, int m, int r) {
	
    // Kopieer de eerste helft naar de hulptabel
    for (int i = l; i <= m; i++)
        h[i - l] = move(v[i]);
    
    
    // Merge dan beide tabellen naar v
    int i = l;			// Algemene loper
    int li = 0;			// Linkse loper
    int ri = m + 1;		// Rechtse loper

	
	// De eerste while loopt tot een van de tabellen leeg is.
    while (li + l <= m && ri <= r) {
        if (h[li] < v[ri]) {
            v[i] = move(h[li]); 			//alt: v[i++] = move(v[li++]);
            i++;
            li++;
        }
        else {
            v[i] = move(v[ri]);
            i++;
            ri++;
        }
    }

	// Een van de tabellen is leeg, voeg de rest van de andere toe.
    while (li + l <= m) {
        v[i] = move(h[li]);
        i++;
        li++;
    }
    while (ri <= r) {
        v[i] = move(v[ri]);        
        i++;
        ri++;
    }
}



//MERGE SORT TOP DOWN (recursief met halve tabel)
//-----------------------------------------------------
template<class T>
void mergeSort1(vector<T> &v, vector<T> &h, int l, int r) {
    if (l < r) {									//Stopconditie als begin < einde dan stoppen met splitsen	
        int m = l + (r - l) / 2; 					//zelfde maar beter dan m = (l + r)/2 want dan geen overflow
        mergeSort1(v, h, l, m);						//Links deel		vb: 0-4
        mergeSort1(v, h, m+1, r);					//Rechts deel		vb: 5-9

        merge(v, h, l, m, r);						
    }
}

template<class T>
void mergeSort1(vector<T> &v) {
    vector<T> h;
    h.reserve(v.size()/2);							
    mergeSort1(v, h, 0, v.size()-1);				
}






//MERGE SORT BOTTUM UP (niet recussief)
//-----------------------------------------------------
template<class T>
void mergeSort2(vector<T> &v) {
    vector<T> h(v.size());				
    
    int subvector_size = 2;

    while(subvector_size < v.size()){		//<= vs <
    	int l = 0;
    	int r = subvector_size - 1;
        while(r < v.size()){				//<= vs <
        	int m = l + (r - l) / 2;
            merge(v, h, l, m, r);
            l += subvector_size;
            r += subvector_size;
        }
        
        if(l < v.size()){
            int m = l + subvector_size / 2 - 1;
            if(m < v.size())
                merge(v, h, l, m, v.size()-1);
        }

        subvector_size *= 2;
    }

    int m = subvector_size / 2 - 1;
    merge(v, h, 0, m, v.size()-1);
}

template<class T>
void mergeSort3(vector<T> &v) {
	vector<T> h(v.size()/2);
	for(int width = 1; width < v.size(); width += width) {
		for(int i = 0; i < v.size(); i++) {
			int l = i;
			int r = i + 2*width;
			int m = i + width;
			merge(v,h,l,m,r);
		}
	}
}
```