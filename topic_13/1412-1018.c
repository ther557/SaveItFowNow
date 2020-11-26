#include <stdio.h>

typedef struct {
    int num[50];
    int cnt;
} Num;

void bubble_sort(Num arr[], int len, int m) {
    int i, j;
    Num temp;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len; j++) {
            for(int k = 0; k < m; k++) {
                if (arr[j].num[k] > arr[j + 1].num[k]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }else if(arr[j].num[k] == arr[j + 1].num[k])
                    continue;
                else if(arr[j].num[k] == arr[j + 1].num[k]&&k==m-1&&arr[j].cnt>arr[j+1].cnt){
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    Num arr[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i].num[j]);
            arr[i].cnt=i+1;
        }
    }
    bubble_sort(arr, n, m);
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i].cnt);
    return 0;
}
