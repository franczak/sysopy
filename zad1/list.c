#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

list * create_list(){
	list* list = malloc(sizeof(list));
	list->head=null;
	list->tail=null;
	return list;
}
 void delete_list(list *list){
	node* tmp=list->head->next;
	node* tmp2;
	while(tmp->next!=NULL){
		tmp2=tmp;
		tmp=tmp->next;
		tmp2->next=null;
		free(tmp2);
	}
	free(list);
 }
