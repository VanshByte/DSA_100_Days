#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int canPlace(int*pos,int n,int k,int dist){
    int cnt=1,last=pos[0];
    for(int i=1;i<n;i++){
        if(pos[i]-last>=dist){
            cnt++;
            last=pos[i];
            if(cnt==k) return 1;
        }
    }
    return 0;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int pos[n];
    for(int i=0;i<n;i++) scanf("%d",&pos[i]);

    qsort(pos,n,sizeof(int),cmp);

    int lo=1,hi=pos[n-1]-pos[0];
    while(lo<hi){
        int mid=lo+(hi-lo+1)/2;
        if(canPlace(pos,n,k,mid)) lo=mid;
        else hi=mid-1;
    }

    printf("%d",lo);
    return 0;
}