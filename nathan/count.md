```cpp
#include<iostream>
#include<vector>

using namespace std;

void countingsort(vector<int> &v){
    
    int min = v[0];
    int max = v[0];
    
    for(int i=1; i<v.size(); i++){
        if(v[i] < min)
            min = v[i];
        if(v[i] > max)
            max = v[i];
    }
    
    // frequentie tabel aanmaken
    int length = max - min + 1;            // +1 !!
    vector<int> freq(length, 0);
    
    // frequenties tellen
    for(int i=0; i<v.size(); i++){
        freq[v[i] - min]++;             // minimum komt op index 0
    }
    
    // cummulatief
    for(int i=1; i<freq.size(); i++){     // i=1 !!
        freq[i] += freq[i-1];
    }
    
    vector<int> sorted(v.size());        // hulptabel
    // output naar hulptabel
    for(int i = v.size()-1; i >= 0; i--){
        int index = v[i] - min;
        sorted[ freq[index]-1 ] = move(v[i]);
        freq[index]--;
    }
    
    v = move(sorted);
}


```