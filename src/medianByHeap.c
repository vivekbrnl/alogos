/*
 * medianByHeap.c
 *
 *  Created on: Sep 22, 2013
 *      Author: vivek
 */
#include "heap.c"
#define M 10


heap max_heap,min_heap;

bool max_compare(int* first,int* second){
	return *first<*second;
}
bool min_compare(int* first,int* second){
	return *first>*second;
}

void insert_element(int i){
	int max_top, min_top;
	if(max_heap.size == min_heap.size){
		min_top = *((int*)heap_top(&min_heap));
		if(i <= min_top){
			heap_insert(&max_heap,&i);
		}
		else{
			free(heap_erase(&min_heap));
			heap_insert(&min_heap,&i);
			heap_insert(&max_heap,&min_top);
		}
		free(min_top);
	}
	else{
		//max_heap.size is greater
		max_top = *((int*)heap_top(&max_heap));
		if(i >= max_top){
			heap_insert(&min_heap,&i);
		}
		else{
			free(heap_erase(&max_heap));
			heap_insert(&max_heap,&i);
			heap_insert(&min_heap,&max_top);
		}
		free(max_top);
	}
}



int Main(){

	heap_init(&max_heap,malloc(sizeof(int)*M),0,sizeof(int),&max_compare);
	heap_init(&min_heap,malloc(sizeof(int)*M),0,sizeof(int),&min_compare);

	return 0;
}

