#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *lNext;
    struct __PHONE_BOOK_ENTRY *rNext;
} entry;

entry *findName(char lastname[], entry *root);
entry *append(char lastName[], entry *root);
void free_tree(entry *root);
void show_tree(entry *root);
//int str_num(char *ptr1,char *ptr2);
#endif
