//2018008931_이유진_12838

#include <stdio.h>
#include <iostream>
using namespace std;


void heap(int* data, int num){

    for(int i = 1; i < num; i++){
        int c = i;
        
        while(c>0){
            int r = (c-1)/2;
            if(data[r] <data[c]){
                int tmp = data[r];
                data[r] = data[c];
                data[c] = tmp;
            }
        c= r;
        }
    }
}
int main(){

int n, k;

cin>>n;
cin>>k;

int* array = new int[n];

    for(int i = 0; i < n; i++){
    
        cin>>array[i];
    }

    heap(array, n);

    for(int i=n-1; i>=0; i--){
        int tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;

        heap(array, i);
    }

    for(int i =n-1; i >=n- k; i--){
        cout<<array[i] ;
        cout<<' ';
    }
    cout<<endl;
    for(int i = n-k-1; i >=0 ; i--){
        cout<<array[i];
        cout << ' ';
    }

return 0;
}