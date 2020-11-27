#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	int weight;
	int parent;
	int rchild;
	int lchild;
}HTNode;

typedef struct{
	char bit[100];
	int start;
}HTCode;

void select(HTNode tree[],int i,int*i1,int *i2);
void HuffmanTree(HTNode tree[],int w[],int n);
void HuffmanTreeEncode(HTNode tree[],char *HuffCode[],int n);
void printout(HTNode tree[],int n);

void HuffmanTreeEncode(HTNode tree[],HTCode *Huffcode[],HTcode temp;int n){
	
}

void select(HTNode tree[],int i,int *i1,int *i2){//挑选出数组内最小和次小并分别赋值i1，i2
	int min1=INT_MAX,min2=INT_MAX;
	*i1=*i2=-1;
	for(int k=0,cnt=0;k<i;k++){
		if(tree[k].parent==-1){
			if(tree[k].weight<min1)
				{
					min2=min1;
					*i2=*i1;
					min1=tree[k].weight;
					*i1=k;
				}
				else if(tree[k].weight<min2)
				{
					min2=tree[k].weight;
					*i2=k;
				}
		}
	}
	printf("%d %d\n",*i1,*i2);
}
void HuffmanTree(HTNode tree[],int w[],int n){   //构建HuffmanTree编码
	int i1,i2;
	for(int i=0;i<2*n-1;i++){
		tree[i].parent=-1;
		tree[i].lchild=-1;
		tree[i].rchild=-1;
	}
	for(int i=0;i<n;i++){
		tree[i].weight=w[i];
	}
	for(int i=n;i<2*n-1;i++){
		select(tree,i,&i1,&i2);
		tree[i].weight=tree[i1].weight+tree[i2].weight;
		tree[i1].parent=i;
		tree[i2].parent=i;
		tree[i].lchild=i1;
		tree[i].rchild=i2;
	}
		
}

void printout(HTNode tree[],int n){
	printf("weight parent lchild rchild\n");
	for(int i=0;i<2*n-1;i++){
		printf("%-6d ",tree[i].weight);
		printf("%-6d ",tree[i].parent);
		printf("%-6d ",tree[i].lchild);
		printf("%-6d\n",tree[i].rchild);
	}
}
int main(){
	int n;
	printf("请输入结点个数：\n");
	scanf("%d\n",&n);
	HTNode tree[2*n+1];
	int w[n];
	printf("请输入%d个权值：\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	HuffmanTree(tree,w,n);
	printout(tree,n);
	char *Huffcode[n];
	HuffmanTreeEncode(tree,&Huffcode[n],n);
	for(int i=0;i<n;i++){
		printf("%s",*Huffcode[i]);
	}
	free(Huffcode);
}
