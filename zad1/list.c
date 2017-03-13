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
		tmp2->next=null;
		free(tmp2);
	}
	free(list);
 }
