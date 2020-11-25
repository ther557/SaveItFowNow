#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *next;
} Node, *Link;

Link NewList(int arr[], int n);
Link DeleteNode(Link head, int x);
void ClearLink(Link head);
void bubble_sort(int arr[], int n);
void DisplayNode(Link head);

int main() {
    int n, x = 0;
    scanf("%d\n", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);
    bubble_sort(arr, n);
    Link head;
    head = (Link)malloc(sizeof(Node));
    head = NewList(arr, n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] == arr[j]) {
                x = arr[j];
                head=DeleteNode(head, x);
            }
        }
    }
    DisplayNode(head);
    ClearLink(head);
    return 0;
}

void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

Link NewList(int arr[], int n) {
    Link head, rear;
    head = (Link)malloc(sizeof(Node));
    head->next = NULL;
    rear = head;
    for (int i = 0; i < n; i++) {
        Link node = (Link)malloc(sizeof(Node));
        node->data = arr[i];
        rear->next = node;
        rear = node;
    }
    rear->next = NULL;
    return head;
}

Link DeleteNode(Link head, int x) {
    Link p, q;
    int cnt = 0;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    while (x!=p->data&&p->next!=NULL&&cnt==0){
        q=p;
        p=p->next;
        cnt++;
    }
    if(x==p->data&&cnt!=0){
        if(p==head){
            head=p->next;
        }else{
            q->next=p->next;
        }
        free(p);
    }
    return head;
}

void ClearLink(Link head) {
    Link q;
    while (head != NULL) {
        q = head;
        head = head->next;
        free(q);
    }
}

void DisplayNode(Link head) {
    Link p, q;
    int cnt = 0;
    p = head->next;
    q = p;
    while(q != NULL) {
        q = q->next;
        cnt++;
    }
    printf("%d\n", cnt);
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
