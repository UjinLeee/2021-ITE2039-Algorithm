//Assembly_line.cpp
//2018008931_이유진_class2(12838)
#include <iostream>
using namespace std;

int main(){

    int num_stations;

    cin>> num_stations;

    int n = num_stations + 1;
    
    int* e = new int[2];

    cin>> e[0];
    cin>> e[1];

    int* x = new int[2];

    cin>> x[0];
    cin>> x[1];

//    int** a = new int[2][n];
    
    int** a = new int*[n];
    int** t = new int*[n];
    int** s = new int*[n];
    int** l = new int*[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[2];
        t[i] = new int[2];
        s[i] = new int[2];
        l[i] = new int[2];
    }

    a[0][0] = 0;
    a[1][0] = 0;

    for(int i = 1; i < n; i++){
        cin>> a[1][i] ;
    }

    for(int i = 1; i < n; i++){
        cin >> a[2][i];
    }

//    int** t = new int[2][n];
    t[0][0] = 0;
    t[1][1] = 0;
    
    for(int i = 1; i < n; i++)
        cin>>t[0][i];
    for(int i = 1; i < n; i++)
        cin>>t[1][i];

//    int** s = new int[2][n];
    s[0][0] = 0;
    s[1][0] = 0;

    s[0][1] = e[0] + a[0][1];
    s[1][1] = e[1] + a[1][1];

//    int** l = new int[2][n];
    l[0][0] = 0;
    l[1][0] = 0;

    for(int j = 2; j <= n ; j++){
        if(s[0][j-1] <= s[1][j-1] + t[1][j-1]){
            s[0][j] = s[0][j-1] + a[0][j];
            l[0][j] = 1;   
        }else{
            s[0][j] = s[1][j-1] + t[1][j-1] + a[0][j];
            l[0][j] = 2;
        }

        if(s[1][j-1] <= s[0][j-1] + t[0][j-1]){
            s[1][j] = s[1][j-1] + a[1][j];
            l[1][j] = 2;
        }else{
            s[1][j] = s[0][j-1] + t[0][j-1] + a[1][j];
            l[1][j] = 1;
        }

    }

    int sum, l_star;

    if(s[0][num_stations] + x[0] <= s[1][num_stations] + x[1]){
        sum = s[0][num_stations] + x[0];
        l_star = 1;       
    }else{
        sum = s[1][num_stations] + x[1];
        l_star = 2;
    }

    cout << sum << endl;
    cout << l_star ;
    cout << " ";
    cout << num_stations <<endl;

    int i = l_star;
    for(int j = num_stations; j > 0; j--){
        i = l[i][j];
        cout<< i;
        cout << " ";
        cout << j-1 <<endl;
    }
    delete[] e;
    delete[] x;

    
    for(int i = 0; i <n; i++){
        delete[] s[i];
        delete[] a[i];
        delete[] t[i];
        delete[] l[i];
    }   

    delete[] s;
    delete[] a;
    delete[] t;
    delete[] l;
    return 0;
}
