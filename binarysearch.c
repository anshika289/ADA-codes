// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// int binary_search(int arr[],int x,int size){
    
//     int n=size;
//     int l=0;
//     int r=n-1;
//     while(l<=r){
//         int m=l+(r-l)/2;
//         if(arr[m]==x){
//             return 1;
//         }
//         if(arr[m]>x){
//             r=m-1;
//         }
//         else if(arr[m]<x){
//             l=m+1;
//         }
        
//     }
//     return 0;
    
// }
// void randarr(int arr[],int n){
//     arr[0]=rand()%10;
//     for(int i=1;i<n;i++){
//         arr[i]=arr[i-1]+rand()%10;
//     }
// }
// int main(){
//     printf("enter no of elements: ");
//     int n;
//     scanf("%d",&n);
//     if(n>=5000){
//         printf("enter a value less than 5000\n");
//         return 1;

//     }
//     int *arr=(int)malloc(n*sizeof(int));
//     if(arr==NULL){
//         printf("memory allocaton failed!!");
//         return 1;
        
//     }
//     srand(time(NULL));
//     randarr(arr,n);
//     int x=arr[rand()%n];
//     clock_t start=clock();
//     for(int i=0;i<1000000;i++){
//         binary_search(arr,x,n);
//     }
//     clock_t end=clock();
//     double total_time=(double)(end-start)/CLOCKS_PER_SEC;
//     double time=total_time/1000000;
//     printf("Time taken for %d elements is %e",n,time);
// }


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int binary_search(int a[],int x,int size){
    
    int n=size;
    int l=0;
    int r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x){
            return 1;
        }
        if(a[m]>x){
            r=m-1;
        }
        else if(a[m]<x){
            l=m+1;
        }
        
    }
    return 0;
    
}
void randarr(int a[],int n){
    a[0]=rand()%10;
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+rand()%10;
    }
}
int main(){
    printf("enter no of elements: ");
    int n;
    scanf("%d",&n);
    if(n>=5000){
        printf("enter a value less than 5000\n");
        return 1;

    }
    int *arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("memory allocaton failed!!");
        return 1;
        
    }
    randarr(arr,n);
    int x=arr[rand()%n];
    clock_t start=clock();
    for(int i=0;i<1000000;i++){
        binary_search(arr,x,n);
    }
    clock_t end=clock();
    double total_time=(double)(end-start)/CLOCKS_PER_SEC;
    double time=total_time/1000000;
    printf("Time taken for %d elements is %e",n,time);
}