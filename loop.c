#include<stdio.h>
#include<string.h>
#include"head.h"

void add_loop(struct book** head, struct book* n, void* (*next)(void* np), void* (*befo)(void *bp)){ //next是np为地址所指向的节点的struct book* next的地址，befo是bp为地址所指向的节点的struct book** befo的地址 
	struct book** p, ***q;
	if(*head == NULL){
		*head = n;
		p = (struct book**)next(&n);
		*p = NULL;
		q = (struct book***)befo(&n);
		*q = head;
		return;
	}
	p = (struct book**)next(head);
	if(*p == NULL){
		*p = n;
		q =  (struct book***)befo(&n);
		*q = p;
		p = (struct book**)next(&n);
		*p = NULL;
		return;
	} 
	p = (struct book**)next(&n);
	*p = *(struct book**)next(head);
	q = (struct book***)befo(&n);
	*q = *(struct book***)befo(p);
	p = (struct book**)next(head);
	*p = n;
	q = (struct book***)befo(p);
	*q = (struct book**)next(&n);
	return;
}

void* befo_sign(void *bp){
	return &(*(struct book**)bp)->befo;
}

void* befo_name(void *bp){
	return &(*(struct book**)bp)->befo_name;
}

void* befo_writer(void *bp){
	return &(*(struct book**)bp)->befo_writer;
}

void* befo_publish(void *bp){
	return &(*(struct book**)bp)->befo_publish;
}

void* befo_price(void *bp){
	return &(*(struct book**)bp)->befo_price;
}

void delete_loop(struct book** head, struct book* now){//通过书号的链表，用书名或书号删除 
	if(head == NULL || *head == NULL)	return;	
	*now->befo = now->next;
	if(now->next != NULL)	now->next->befo = now->befo;
	*now->befo_name = now->next_name;
	if(now->next_name != NULL)	now->next_name->befo_name = now->befo_name;
	*now->befo_writer = now->next_writer;
	if(now->next_writer != NULL)	now->next_writer->befo_writer = now->befo_writer;
	*now->befo_publish = now->next_publish;
	if(now->next_publish != NULL)	now->next_publish->befo_publish = now->befo_publish;
	*now->befo_price = now->next_price;  
	if(now->next_price != NULL)	now->next_price->befo_price = now->befo_price;
	
	return;
	
//	befo = *head;
//	if(equal(*befo, n)){ 
//		*head = befo->next;
//		return befo;
//	}
//	else if(befo->next == NULL) return NULL;
//	now = befo->next;
//	while(!equal(*now, n)){
//		befo = now;
//		now = now->next;
//		if(now == NULL) return NULL;
//	}
//	now->next = befo->next;
//	return now;
}

int equal_sign(struct book h, void* n){
	return h.sign == *(unsigned int*)n;
}

int equal_name(struct book h, void* n){
	return !(strcmp(h.name, (char*)n));
}


