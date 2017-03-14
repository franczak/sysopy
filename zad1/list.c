#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

list * create_list(){
	list* list = malloc(sizeof(list));
	node *head = malloc( sizeof(node) );
	node *tail = malloc( sizeof(node) );
	head->next=tail;
	head->prev=NULL;
	tail->prev=head;
	tail->next=NULL;
	list->head=head;
	list->tail=tail;
	return list;
}

void add_contact(list* lista, node* contact){
	contact->next=lista->head;
	lista->head->prev=contact;
	lista->head=contact;
}

void remove_contact(list* lista, char* surname, char* phone){
	if(lista->head==NULL) printf("Empty list!");
	node* tmp=lista->head;
	if(lista->head->data.phone==phone && lista->head->data.surname==surname){
		lista->head=tmp->next;
		lista->head->prev=NULL;
		tmp->next=NULL;
		tmp->prev=NULL;
		free(tmp);
	}else if(lista->tail->data.phone==phone && lista->tail->data.surname==surname){
		tmp=lista->tail;
		tmp->prev->next=NULL;
		lista->tail=tmp->prev;
		tmp->prev=NULL;
		free(tmp);
	}else{
	for(tmp;tmp!=NULL;tmp=tmp->next)
	if(tmp->data.phone==phone && tmp->data.surname==surname){
			if(tmp->next!=NULL){
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
		}else if(tmp->prev)
			tmp->prev->next=NULL;
	tmp->next=tmp->prev=NULL;
	free(tmp);
	break;
	} 
	if(tmp==NULL) printf("No such contact");
}
}

node * create_contact(char *name, char *surname, char *day, char *mail, char *phone, char *address){
	node *contact=malloc(sizeof(node));
	contact->next=NULL;
	contact->prev=NULL;
	contact->data.name=name;
	contact->data.surname=surname;
	contact->data.birthDay=day;
	contact->data.mail=mail;
	contact->data.phone=phone;
	contact->data.address=address;
}

void print_list(node* head){
	if(head==NULL) printf("Empty list!\n");
	node *tmp=head;
	while(tmp!=NULL){
		printf("%s %s %s %s %s %s\n",tmp->data.name,
		tmp->data.surname,
		tmp->data.birthDate,
		tmp->data.mail,
		tmp->data.phone,
		tmp->data.address);
		tmp=tmp->next;
	}
}
 void delete_list(list *list){
	node* tmp=list->head->next;
	node* tmp2;
	while(tmp->next!=NULL){
		tmp2=tmp;
		tmp=tmp->next;
		free(tmp2);
	}
	free(list);
 }
 
void swap(node *node1, node *node2, list *list) {
    if((node1 != NULL && node2 != NULL) && (node1 != node2)) {
        node *tmp1, *tmp2;
        if(list->head == node1) {
            list->head = node2;
        } else if(list->head == node2) {
            list->head = node1;
        }

        if(list->tail == node1) {
            list->tail = node2;
        } else if(list->tail == node2) {
            list->tail = node1;
        }

        tmp1 = node1->next;
        tmp2 = node2->next;
        node1->next = tmp2;
        node2->next = tmp1;
        if(tmp1 != NULL) tmp1->prev = node2;
        if(tmp2 != NULL) tmp2->prev = node1;

        tmp1 = node1->prev;
        tmp2 = node2->prev;
        node1->prev = tmp2;
        node2->prev = tmp1;
        if(tmp1 != NULL) tmp1->next = node2;
        if(tmp2 != NULL) tmp2->next = node1;
    }
}
 
 
void insert_sort(list *list, char *key){
	if(list!=NULL){
		node *tmpH=list->head;
		node *current, *tmp;
		
		while(tmpH!=NULL){
			current=tmpH->next;
			while(current!=NULL && comparator(tmpH,current,key)<=0)
				current=current->next;
			if(current!=NULL){
				tmp = tmpH->next;
				swap(current,tmpH,list);
				tmpH=tmp;}
				else{
					tmpH=tmpH->next;
				}
			}
		}
}
 
int comparator(node *node1, node *node2, char *key) {
    if(node1 != NULL && node2 != NULL) {
        if(strcmp(key,"name") == 0 ) {
            return strcmp(node1->data.name, node2->data.name);

        }
        else if(strcmp(key,"surname") == 0 ) {
            return strcmp(node1->data.surname, node2->data.surname);
        }
        else if(strcmp(key,"phone") == 0 ) {
            return strcmp(node1->data.phone, node2->data.phone);
        }
        else if(strcmp(key,"email") == 0 ) {
            return strcmp(node1->data.mail, node2->data.mail);
        }
        else {
            fprintf(stderr, "Wrong argument!\n");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}



