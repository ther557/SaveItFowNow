#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}Node,*Link;

Link NewList(int arr[],int n);
bool DeleteNode(Link head,int x);//x为要删除的数据
void ClearLink(Link head);
void bubble_sort(int arr[],int n);

int main(){
    int n;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d ",&arr[i]);
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){            //BreakPoint
        if
    }
    Link head;
    head=(Link)malloc(sizeof(Node));
    Link NewList(arr,n);
    bool m;
    m=bool DeleteNode(head,)
}

void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++){
        for (j = 0; j < len - 1 - i; j++){
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
