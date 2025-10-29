#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                // swap
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void randarr(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%10000;
    }
    
}
int main(){
    
    

    for(int n=1000;n<10000;n+=1000){
        int *arr=(int*)malloc(n*sizeof(int));
        int *temp=(int*)malloc(n*sizeof(int));
        if(arr==NULL||temp==NULL){
            printf("memory allocaton failed!!");
            return 1;
            
        }
        randarr(arr,n);
        
        
        clock_t start=clock();
        for(int i=0;i<1000;i++){
            for(int j=0;j<n;j++){
                temp[j]=arr[j];
            }
            bubble_sort(temp,n);
        }
        clock_t end=clock();
        double total_time=(double)(end-start)/CLOCKS_PER_SEC;
        double time=total_time/1000;
        printf("Time taken for %d elements is %f \n",n,time);
}}