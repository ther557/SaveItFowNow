#include <stdio.h>
#include <malloc.h>

typedef struct node {    //定义结点结构体，数据域data和指针域next
    int data;
    struct node *next;
} Node, *Link;

Link NewList(int arr[], int n);//创建链表，尾插法
Link DeleteNode(Link head, int x);//删除下一位拥有相同指定值的结点
void ClearLink(Link head);//清除链表
void bubble_sort(int arr[], int n);
void DisplayNode(Link head);//输出链表中结点个数及各节点值

int main() {
    int n, x = 0;。               //将输入数据存入数组
    scanf("%d\n", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);
    bubble_sort(arr, n);
    Link head;。                  //创建头结点
    head = (Link)malloc(sizeof(Node));
    head = NewList(arr, n);。     //创建链表
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] == arr[j]) {
                x = arr[j];
                head=DeleteNode(head, x);     //查重并删除
            }
        }
    }
    DisplayNode(head);     //打印结果
    ClearLink(head);       //清除链表
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
    rear = head;//头尾指针指向同一结点
    for (int i = 0; i < n; i++) {
        Link node = (Link)malloc(sizeof(Node));//建立结点
        node->data = arr[i];//将对应数据存入结点数据域
        rear->next = node;//建立终端结点和新建立结点的关系
        rear = node;//移动尾指针，此处也可写为"rear = rear->next"
    }
    rear->next = NULL;//将终端结点指针域指向NULL
    return head;
}

Link DeleteNode(Link head, int x) {//本函数未设置报错功能，仅可作为本题使用函数，详细说明可参照教材P366
    Link p=head, q=head;
    int cnt = 0;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    while (x!=p->data&&p->next!=NULL){
        q=p;
        p=p->next;
    }
    if(x==p->data&&p->next!=NULL){
        cnt++;
        q=p;
        p=p->next;
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
        head = head->next;//移动头指针
        free(q);//释放结点
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
