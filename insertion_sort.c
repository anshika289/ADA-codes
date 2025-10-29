#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion_sort(int a[],int n){
for(int i=0;i<n;i++){
    int key = a[i];
    int j=i-1;
    while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=key;

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
            insertion_sort(temp,n);
        }
        clock_t end=clock();
        double total_time=(double)(end-start)/CLOCKS_PER_SEC;
        double time=total_time/1000;
        printf("Time taken for %d elements is %f \n",n,time);
}}