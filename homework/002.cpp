#include<iostream>
#define ma 41
typedef int ElemType;

typedef struct node{
	ElemType data;
	int length;
	struct node *next;
}node,*Linklist;

void Initlist(Linklist &L){
	L=new node;
	L->next=L; 
	L->length=0;
}

void inserttail(Linklist &L,ElemType e){
	if(L==NULL){
		return ;
	}
	Linklist p=L;
	while(p->next!=L){
		p=p->next;
	}
	Linklist newnode=new node;
	newnode->data=e;
	p->next=newnode;
	newnode->next=L;
	L->length++;	
}
void poplist(Linklist &L,Linklist p){
	if(L==NULL || L->next==L){
		return ;
	}
	Linklist tem=p->next;
	p->next=tem->next;
	delete tem;
	L->length--;
}

int main(){
	Linklist L;
	Initlist(L);
	for(int i=1;i<=ma;i++){
		inserttail(L,i);
	}
	Linklist cur=L->next;
	Linklist pre=L;
	while(L->length>2){
		for(int count=1;count<3;count++){
			pre=cur;
			cur=cur->next;
		}
		poplist(L,pre);
		cur=pre->next;
	}
	printf("%d\t%d",L->next->data,L->next->next->data);
	return 0;
}