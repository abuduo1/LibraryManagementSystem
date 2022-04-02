#include<stdio.h>
#include<string.h>
#include"head.h"

void SortAny(void* head, int n, void* (*next)(void* p), void* (*befo)(void*bp), int (*comp)(void* fri, void* sec), void (*exch)(void* fri, void* sec, void* (*next)(void* p), void* (*befo)(void*bp))){
	int i, j, k;
	void *p, *q, *r;
	for(i = 0, p = head; i < n - 1; i++, p = next(p)){
		r = p;
		for(j = i + 1, q = next(p); j < n; j++, q = next(q))
			if(comp(r, q))	r = q;
		if(r != p)	exch(r, p, next, befo);
	}
}

void exch(void* fri, void* sec, void* (*next)(void* p), void* (*befo)(void*bp)){
	struct book* temp, **temp2;

		
	if(*(struct book**)next(fri) == NULL)	*(struct book ***)befo(next(sec)) = (struct book**)next(fri);
	else if(*(struct book**)next(sec) == NULL) *(struct book ***)befo(next(fri)) = (struct book**)next(sec);
	else{
		temp2 = *(struct book ***)befo(next(sec));
		*(struct book ***)befo(next(sec)) = *(struct book ***)befo(next(fri));
		*(struct book ***)befo(next(fri)) = temp2;
	}
	
	temp2 = *(struct book ***)befo(sec);
	*(struct book ***)befo(sec) = *(struct book ***)befo(fri);
	*(struct book ***)befo(fri) = temp2;

	temp = *(struct book**)fri;
	*(struct book**)fri = *(struct book**)sec;
	*(struct book**)sec = temp;
	
	temp = *(struct book**)next(fri);
	*(struct book**)next(fri) = *(struct book**)next(sec);
	*(struct book**)next(sec) = temp; 
	
}
//sign

void* next_sign(void* p){
	return	&(*(struct book**)p)->next;
}
int comp_sign(void* fri, void* sec){
	return (*(struct book**)fri)->sign > (*(struct book**)sec)->sign;
}

//name

void* next_name(void* p){
	return &(*(struct book**)p)->next_name;
}
int comp_name(void* fri, void* sec){
	int  i = strcmp((*(struct book**)fri)->name, (*(struct book**)sec)->name);
	if(i > 0)	return 1;
	else return 0; 
}

//writer

void* next_writer(void* p){
	return &(*(struct book**)p)->next_writer;
}
int comp_writer(void* fri, void* sec){
	int  i = strcmp((*(struct book**)fri)->writer, (*(struct book**)sec)->writer);
	if(i > 0)	return 1;
	else return 0; 
}

//publish

void* next_publish(void* p){
	return &(*(struct book**)p)->next_publish;
}
int comp_publish(void* fri, void* sec){
	int  i = strcmp((*(struct book**)fri)->publish, (*(struct book**)sec)->publish);
	if(i > 0)	return 1;
	else return 0; 
}

//price

void* next_price(void* p){
	return	&(*(struct book**)p)->next_price;
}
int comp_price(void* fri, void* sec){
	return (*(struct book**)fri)->price > (*(struct book**)sec)->price;
}


