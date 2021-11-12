//2018008931_이유진_class2(12838)

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

    int n, m;

    cin >> n;
    cin >> m;

    int * N = new int[n];
    int* M = new int[m];

    int i = 0;

    for(i = 0; i < n; i++){
        cin>>N[i];
    }

    for(i = 0; i < m; i++){
        cin>>M[i];
    }

    
    int count = 0;
    for(i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(N[i] == M[j])
                count++;
        }
    }
    
    cout << count <<endl;

    delete[] N;
    delete[] M;

    return 0;   

} 