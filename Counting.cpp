//2018008931_이유진_class2(12838)

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, range, q_r;

    cin >> n;
    cin >> range;
    cin >> q_r;

    int* a1 = new int[q_r];
    int* a2 = new int[q_r];

    for(int i = 0; i <q_r; i++){
        cin >> a1[i];
        cin >> a2[i];
    }

    int* array = new int[range];

    int insert;
    
    int* keys = new int[n+1];
    for(int i = 0; i < n; i++){
        cin >> insert;
        keys[i] = insert;
        array[insert] = -3;           
    }
    keys[n] = -1;

    int count = 0;

    for(int i = range-1; i >= 0; i--){
        if(array[i] == -3){
            count++;
        }
        array[i] = count;
    }
    
    
    int p = 0;

    vector<int> myvector(keys,keys+n+1);
    vector<int>::iterator i1;   
    vector<int>::iterator i2;

    for(int i = 0; i < q_r; i++){
       
        i1 = find(myvector.begin(),myvector.end(), a1[i]);
        i2 = find(myvector.begin(),myvector.end(), a2[i]);

        if(i1!=myvector.end() && i2!=myvector.end())
            p =1;
	if(i1==myvector.end() && i2 != myvector.end())
		p=1;

        if(p == 0){
        cout<< array[a1[i]] - array[a2[i]] <<endl;}
        if(p == 1){
        cout <<( array[a1[i]] - array[a2[i]] + 1) <<endl;}
        p = 0;
    }

    delete[] a2;
    delete []a1;
    delete [] array;
    delete[] keys;       
    

    return 0;
} 