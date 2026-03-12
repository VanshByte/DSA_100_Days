#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *heap;
int size = 0, cap = 0;

void swap(int *a, int *b){ int t = *a; *a = *b; *b = t; }

void up(int i){
    while(i > 0){
        int p = (i - 1) / 2;
        if(heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void down(int i){
    while(1){
        int l = 2*i + 1, r = 2*i + 2, s = i;
        if(l < size && heap[l] < heap[s]) s = l;
        if(r < size && heap[r] < heap[s]) s = r;
        if(s == i) break;
        swap(&heap[i], &heap[s]);
        i = s;
    }
}

void insert(int x){
    if(size == cap){
        cap = cap ? cap * 2 : 4;
        heap = realloc(heap, cap * sizeof(int));
    }
    heap[size] = x;
    up(size);
    size++;
}

int peek(){
    if(size == 0) return -1;
    return heap[0];
}

int extractMin(){
    if(size == 0) return -1;
    int m = heap[0];
    heap[0] = heap[--size];
    down(0);
    return m;
}

int main(){
    int n;
    scanf("%d", &n);
    char op[20];
    int x;

    for(int i = 0; i < n; i++){
        scanf("%s", op);
        if(strcmp(op, "insert") == 0){
            scanf("%d", &x);
            insert(x);
        } else if(strcmp(op, "peek") == 0){
            printf("%d\n", peek());
        } else if(strcmp(op, "extractMin") == 0){
            printf("%d\n", extractMin());
        }
    }
    free(heap);
    return 0;
}