#include<stdio.h>
#include<stdlib.h>
struct book{//struct book** befo指向前一个节点对应的struct book* next
	unsigned int sign;
	char name[20];
	char writer[20];
	char publish[20];
	double price;
	char intr[200]; 
	struct book* next;
	struct book** befo; 
	struct book* next_name;
	struct book** befo_name; 
	struct book* next_writer;
	struct book** befo_writer;
	struct book* next_publish;
	struct book** befo_publish;
	struct book* next_price;
	struct book** befo_price;
	
	struct book* next_hash_name;
	struct book* next_hash_sign;
	
};

void SortAny(void* head, int n, void* (*next)(void* p),  void* (*befo)(void*bp), int (*comp)(void* fri, void* sec), void (*exch)(void* fri, void* sec, void* (*next)(void* p), void* (*befo)(void*bp)));
void exch(void* fri, void* sec, void* (*next)(void* p), void* (*befo)(void*bp));
void* next_sign(void* p);
int comp_sign(void* fri, void* sec);
void* next_name(void* p);
int comp_name(void* fri, void* sec);
void* next_writer(void* p);
int comp_writer(void* fri, void* sec);
void* next_publish(void* p);
int comp_publish(void* fri, void* sec);
void* next_price(void* p);
int comp_price(void* fri, void* sec);

void add_loop(struct book** head, struct book* n, void* (*next)(void* np), void* (*befo)(void *bp));//next是np为地址所指向的节点的struct book* next的地址，befo是bp为地址所指向的节点的struct book** befo的地址 
void* befo_sign(void *bp);
void* befo_name(void *bp);
void* befo_writer(void *bp);
void* befo_publish(void *bp);
void* befo_price(void *bp);
void delete_loop(struct book** head, struct book* now); 
int equal_sign(struct book h, void* n);
int equal_name(struct book h, void* n);

void InsertIndex(struct book* p, int n);//n = 0添加书号的哈希表，n = 1添加书名的哈希表 
struct book* Search(void* s, int n);//n = 0按书号查找，n = 1按书名查找 
void Delete_hash(struct book* p, int n);


