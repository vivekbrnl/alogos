/*
 * heapSort.c
 *
 *  Created on: Sep 21, 2013
 *      Author: vivek
 */


#include "heap.c"

typedef struct foo {
	int element;
}foo;
bool compare(void* first,void* second){
	return ((foo*)first)->element<((foo*)second)->element;
}

void print_array(foo* array,char* str){
		printf("%s----------",str);
		printf("%d ",array[0].element);
		printf("%d ",array[1].element);
		printf("%d ",array[2].element);
		printf("%d ",array[3].element);
		printf("%d ",array[4].element);
		printf("%d ",array[5].element);
		printf("%d\n",array[6].element);
}


void heapsort(void* array,size_t size,size_t element_size,comparator* cmp){
	int i = 0;
	void* temp = malloc(element_size);
	heap heap;
	heap_init(&heap, array, size, element_size, cmp);
	build_heap(&heap);
	for(; i < size ; ++i){

		 memcpy(temp,array,element_size);
		 memcpy(array,array+(heap.size-1)*element_size,element_size);
		 memcpy(array+(heap.size-1)*element_size,temp,element_size);
		 --heap.size;

		 heapify(&heap, 0);
	}
	free(temp);
}


int Main(){
	foo array[] ={{2},{3},{1},{5},{1},{3},{2}};

	heapsort(array,sizeof(array)/sizeof(array[0]),sizeof(array[0]),&compare);
	print_array(array,"");
	return 0;
}
