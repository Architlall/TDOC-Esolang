#include<stdio.h>
#include<stdlib.h>
int main(){
    int predefsize = 2;
    int *ptr = (int *)malloc(sizeof(int)*predefsize);
    int n;  scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;    scanf("%d",&val);
        if(i==predefsize){
            ptr = (int*)realloc(ptr,sizeof(int)*predefsize*2);
            predefsize=predefsize*2;
        }
        *(ptr + i) = val;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",*(ptr+i));
    }
    return 0;
}