#ifndef list_h
#define list_h

typedef struct NODE node;
typedef struct CONTACT contact;
typedef struct LIST list;

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
	contact* data;
};
struct list{
	node* head;
	node* tail;
};

list * create_list();

void add_contact(list* lista, node* contact);

void remove_contact(list* lista, char* surname, char* phone);

node * create_contact(char *name, char *surname, char *day, char *mail, char *phone, char *address);

void print_list(node* head);

void delete_list(list *list);

void swap(node *node1, node *node2, list *list);

void insert_sort(list *list, char *key);

int comparator(node *node1, node *node2, char *key);

#endif




