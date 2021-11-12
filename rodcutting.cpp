//2018008931 이유진 class2(12838)

#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int* p = new int[n+1];
    
    p[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>> p[i];
    }

    int* r = new int[n+1];
    r[0] = 0;
    int* s = new int[n+1];
    s[0] = 0;

    int q;
    for(int j = 1; j <= n; j++){
         q= -1;
        for(int i = 1; i <=j; i++){
            if(q < p[i] + r[j-i]){
                q=p[i] + r[j-i];
                s[j] = i;
            }
       
            r[j] = q;
        }
    }

    cout << r[n] << endl;
    while(n>0){
        cout << s[n] ;
        cout << " ";
        n = n - s[n];
    }
    cout<<endl;

    delete[] r;
    delete[] s;
    delete[] p;
} 