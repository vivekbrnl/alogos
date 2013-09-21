/*
 * heap.c
 *
 *  Created on: Sep 21, 2013
 *      Author: vivek
 */

#include "inc.c"

#define exchange(i,j) do{\
	void* temp = malloc(heap->element_size);\
	memcpy(temp,heap->array+i*heap->element_size,heap->element_size);\
	memcpy(heap->array+i*heap->element_size,heap->array+j*heap->element_size,heap->element_size);\
	memcpy(heap->array+j*heap->element_size,temp,heap->element_size);\
	free(temp);\
}while(false)\
#define left(i) ((i<<1)+1)
#define right(i) ((i<<1)+2)
#define parent(i) ((i-1)/2)
#define array(i) (heap->array+i*heap->element_size)
typedef enum bool{
	false,true
}bool;

typedef bool comparator(void*, void*);

typedef struct heap{
	size_t element_size;
	size_t size;
	void *array;
	bool (*comparator) (void*, void*);
}heap;

static void heapify(heap* heap,int index){
	int left=left(index), right=right(index), largest = index;
	void *l = heap->array+left*heap->element_size,
		 *r = heap->array+right*heap->element_size,
		 *i = heap->array+index*heap->element_size,*temp;
	if(left < heap->size && heap->comparator(i,l)){
		largest = left;
		i = l;
	}
	if(right < heap->size && heap->comparator(i,r)){
		largest = right;
	}

	if(largest != index){
		temp = malloc(heap->element_size);
		memcpy(temp,heap->array+index*heap->element_size,heap->element_size);
		memcpy(heap->array+index*heap->element_size,heap->array+largest*heap->element_size,heap->element_size);
		memcpy(heap->array+largest*heap->element_size,temp,heap->element_size);
		free(temp);
		heapify(heap,largest);
	}
}

static void build_heap(heap* heap){
	int i = heap->size / 2;
	while(i >= 0){
		heapify(heap, i);
		--i;
	}
}

void heap_init(heap* heap,void* array,size_t size,size_t element_size,comparator* cmp){
	heap->array = array;
	heap->size = size;
	heap->element_size = element_size;
	heap->comparator = cmp;
}
void heap_bubble_up(heap* heap,int key){
	while(key > 0 && heap->comparator(array(parent(key)),array(key))){
		exchange(parent(key),key);
		key = parent(key);
	}
}
void heap_insert(heap* heap,void* element){
	memcpy(heap->array+heap->size*heap->element_size,element,heap->element_size);
	heap_bubble_up(heap,heap->size);
	++heap->size;
}
void* heap_erase(heap* heap){
	void* temp = malloc(heap->element_size);
	memcpy(temp,heap->array,heap->element_size);
	--heap->size;
	exchange(0,(heap->size-1));
	heapify(heap,0);
	return temp;
}
void* heap_top(heap* heap){
	void* temp = malloc(heap->element_size);
	memcpy(temp,heap->array,heap->element_size);
	return temp;
}
