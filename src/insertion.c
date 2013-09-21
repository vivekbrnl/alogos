/*
 * insertion.c
 *
 *  Created on: Sep 21, 2013
 *      Author: vivek
 */
#include"inc.c"
#include <string.h>


typedef enum bool{
	false,true
}bool;
typedef struct foo {
	int one;
}foo;
bool compare(void* first,void* second){
	return ((foo*)first)->one<((foo*)second)->one;
}
typedef bool comparator(void*, void*);

void print_array(foo* array,char* str){
		printf("%s----------",str);
		printf("%d ",array[0].one);
		printf("%d ",array[1].one);
		printf("%d ",array[2].one);
		printf("%d ",array[3].one);
		printf("%d ",array[4].one);
		printf("%d ",array[5].one);
		printf("%d\n",array[6].one);
}

void insertion_sort(void* array,size_t size, size_t element_size,comparator* comp){
	void *elem,*key,*temp;
	int i = 1, j ;

	for(; i<size; ++i){
		 key=malloc(element_size);
		 memcpy(key,array+(i*element_size),element_size);
		for(j=i-1; j>=0; --j){
			elem=array+j*element_size;
			if(comp(key,elem)){
				temp=array+(j+1)*element_size;
				memcpy(temp,elem,element_size);
			}
			else{
				break;
			}
		}
		temp=array+(j+1)*element_size;
		memcpy(temp,key,element_size);
		free(key);
	}
}


int Main(){
	foo array[] ={{2},{3},{1},{5},{1},{3},{2}};

	insertion_sort(array,sizeof(array)/sizeof(array[0]),sizeof(array[0]),&compare);
	print_array(array,"");
	return 0;
}

