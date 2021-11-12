//2018008931_이유진_class2(12838)

#include <stdio.h>
#include <stdlib.h>


int main(){

    int a;

    scanf("%d", &a);
   
    if(a > 30000 || a < 1)
	return 0;

    int *array = new int[a];

    for(int i = 0; i < a; i++){
        scanf("%d", &array[i]);
    }

    for(int i = 0 ; i < a - 1; i++){
       
        int key = array[i+1];
      	int j;
	for(j = i; j>-1; j--){
		if(array[j] < key){
			array[j+1] = array[j];
		}else break;
		
		
	}
        array[j+1] = key;
    }

    for(int i = 0; i < a; i++){
        printf("%d\n", array[i]);
    }

    delete[] array;

    return 0;
} 
