//2018008931_이유진_class2(12838)
//matrixchain.cpp
#include <iostream>
using namespace std;

int** s;
void print_optimal_parens( int i, int j){
    if(i == j){
        cout<<i;
    }else{
        cout<<"(";
        print_optimal_parens(i,s[i][j]);
        print_optimal_parens(s[i][j]+1,j);
        cout<<")";
    }
    return;
}
int main(){

    int n;
    cin >> n; //if n = 6

    int* p =new int[n+1];

    for(int i = 0; i <= n; i++){
        cin>>p[i];
    }

    //m[n+1][n+1]
    int** m = new int* [n+1];
    for(int i = 0; i < n+1; i++){
        m[i] = new int[n+1];
    }

    //s[n][n+1]
     s = new int* [n];
    for(int i = 0; i <n; i++){
        s[i] = new int[n+1];
    }


    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }
    
    int j,q;

    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            j = i+l-1;
            m[i][j] = 100000;
            for(int k = i; k <= j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }           
        }
    }
    
    cout<<m[1][n]<<endl;

    print_optimal_parens(1, n);

    for(int i = 0; i < n+1; i++){
        delete[] m[i];
    }
    for(int i = 0; i < n; i++){
        delete[] s[i];
    }

    delete[] p;
    delete[] m;
    delete[] s;

} 

 