#ifndef list_h
#define list_h

typedef struct NODE node;
typedef struct CONTACT contact;
typedef struct LIST list;
typedef int (*comparator)(node*,node*);
struct contact{
	char *name;
	char *surname;
	char *birthDate;
	char *mail;
	char *phone;
	char *address;
};
struct node{
	node* next;
	node* prev;
	contact data;
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
	void (*print_list)(node*);
};

void delete_list(list* list);
void remove_person(list* list, char* name, char* surname);
void add_person(list* list, data* data);
list* create_list();
node* get_person(list* list, char* name, char* surname);
char* list_to_string(list* list);
node* quickersort(node* head,comparator cmp);
#endif




