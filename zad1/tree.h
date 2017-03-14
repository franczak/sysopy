#ifndef tree_h
#define tree_h

typedef struct BTNODE btnode;
typedef struct CONTACT contact;
typedef struct TREE tree;

struct contact{
	char *name;
	char *surname;
	char *birthDate;
	char *mail;
	char *phone;
	char *address;
};

struct btnode{
	btnode* left;
	btnode* right;
	btnode* parent;
	int level;
	contact data;
};

struct tree{
	btnode *root;
};

#endif
