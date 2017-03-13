#ifndef list_h
#define list_h

typedef struct node node;
typedef struct data data;
typedef struct list list;
typedef int (*comparator)(node*,node*);
struct data{
	char name[30];
	char surname[30];
	char birthDate[30];
	char mail[30];
	char phone[12];
	char address[30];
};
struct node{
	node* next;
	node* prev;
	data data;
};
struct list{
	node* head;
	node* tail;
	void (*delete_list)(list *);
	void (*remove_person)(list*,char*,char*);
	void (*add_person)(list*,data*);
	list (*create_list)();
	node* (*get_person)(*list,char*,char*);
	char* (*list_to_string)(*list);
	void (*sort)(list*,comparator);
};

void delete_list(list* list);
void remove_person(list* list, char* name, char* surname);
void add_person(list* list, data* data);
list* create_list();
node* get_person(list* list, char* name, char* surname);
char* list_to_string(list* list);
node* quickersort(node* head,comparator cmp);
#endif




