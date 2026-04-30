#include<stdio.h>

int canAllocate(int* a,int n,int m,int maxp){
    int students=1,sum=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]>maxp){
            students++;
            sum=a[i];
        }else sum+=a[i];
    }
    return students<=m;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int lo=0,hi=0;
    for(int i=0;i<n;i++){
        if(a[i]>lo) lo=a[i];
        hi+=a[i];
    }

    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(canAllocate(a,n,m,mid))
            hi=mid;
        else
            lo=mid+1;
    }

    printf("%d",lo);
    return 0;
}