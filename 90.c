#include<stdio.h>

int canPaint(int* a,int n,int k,int maxTime){
    int p=1,sum=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]>maxTime){
            p++;
            sum=a[i];
        }else sum+=a[i];
    }
    return p<=k;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int lo=0,hi=0;
    for(int i=0;i<n;i++){
        if(a[i]>lo) lo=a[i];
        hi+=a[i];
    }

    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(canPaint(a,n,k,mid))
            hi=mid;
        else
            lo=mid+1;
    }

    printf("%d",lo);
    return 0;
}