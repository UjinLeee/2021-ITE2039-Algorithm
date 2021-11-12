//2018008931_이유진_class2(12838)

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

void merge_sort(int *array, int start, int mid, int end){
    
    int p,q,r,n1,n2;
    p = start;
    r = end-start+1;//length
    q = mid;
    n1 = mid-start+2;
    n2 = end-mid+1;
    
    int *L = (int*)malloc(sizeof(int)*n1);
    int *R = (int*)malloc(sizeof(int)*n2);
    
    for(int i = 0; i < n1-1; i++)
        L[i]= array[start+i];
    for(int j = 0; j < n2-1 ; j++)
        R[j] = array[mid+1+j];
    L[n1-1] = 0;
    R[n2-1] = 0;
    
    int x = 0;
    int y = 0;
    for(int k = start; k< end+1; k++){
       
        if(L[x] > R[y]){
            array[k] = L[x];
            x++;
           
        }else{
            array[k] = R[y];
            y++;
        }

    }
    free(L);
    free(R);   

}
void merge_sort(int *data, int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(data, start, mid);
        merge_sort(data, mid+1, end);
        merge_sort(data, start, mid, end);
    }
}

int main(){

    int length;
    
    scanf("%d", &length);

    int *array = new int[length];
    
    for(int i = 0; i < length; i++){
        scanf("%d", &array[i]);
    }


    merge_sort(array, 0, length-1);   

    for(int i = 0; i < length; i++){
        printf("%d\n", array[i]);
    }
    
    delete[] array;   
/*    delete[] array;
    delete[] L;
    delete[] R;*/
    return 0;
} 