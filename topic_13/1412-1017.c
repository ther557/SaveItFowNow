#include <stdio.h>

typedef struct{
    int score;
    int num;
}Stu;

void swap(Stu *a,Stu *b)
{
    Stu temp = *a;
    *a = *b;
    *b = temp;
    printf("%d %d\n",a,b);
}
void selection_sort(Stu arr[], int len) 
{
    int i,j,cnt=0;
 
    for (i = 0 ; i < len - 1 ; i++) 
    {
        int min = i;
        for (j = i + 1; j < len; j++){
            if (arr[j].score > arr[min].score){
                min = j;
                swap(&arr[min],&arr[i]);
            }
            else if(arr[j].score == arr[min].score && arr[j].num > arr[min].num){
                min = j;
                swap(&arr[min], &arr[i]);
            }
        }
    }
}


int main(){
    int cnt=0;
    Stu arr[100];
    while(scanf("%d %d\n",&arr[cnt].num,&arr[cnt].score)&&arr[cnt].num!=-1){
        cnt++;
    }
    selection_sort(arr,cnt);
    for(int i=0;i<cnt;i++){
        printf("%d %d\n",arr[i].num,arr[i].score);
    }
    return 0;
}
