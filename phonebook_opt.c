#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "phonebook_opt.h"

/* original version */
entry *findName(char lastname[], entry *root)
{

	while (root != NULL) {
		if (strcasecmp(lastname, root->lastName) == 0) {
			return root;
		} else {
			if (strcasecmp(lastname, root->lastName)) {
				root = root->rNext;
			}
			else
				root = root->lNext;
		}
	}
	return NULL;
}

entry *append(char lastName[], entry *root)
{
	/* allocate memory for the new entry and put lastName */
	if (strcasecmp("\0", root->lastName) == 0)
	{
		strcpy(root->lastName, lastName);
	}
	else {
		entry *tmp, *current, *parent;
		tmp = (entry *) malloc(sizeof(entry));
		strcpy(tmp->lastName, lastName);
		tmp->lNext = NULL;
		tmp->rNext = NULL;
		current = root;
		while (current != NULL) {
			parent = current;
			if (strcasecmp(lastName, current->lastName))
				current = current->rNext;
			else
				current = current->lNext;
		}
		if (strcasecmp(lastName, parent->lastName))
			parent->rNext = tmp;
		else
			parent->lNext = tmp;
	}
	return root;
}
void free_tree(entry *root)
{
	if (root != NULL)
	{
		free_tree(root->lNext);
		free_tree(root->rNext);
	}
	free(root);
	root = NULL;
}
void show_tree(entry *root)
{
	if (root != NULL) {
		printf("%s", root->lastName);
		show_tree(root->rNext);
		show_tree(root->lNext);
	}
}
/*
int str_num(char *ptr1, char *ptr2)
{
	while (*ptr1 != '\0' && *ptr2 != '\0') {
		if (*ptr1 > *ptr2)
			return 1;
		else if (*ptr1 < *ptr2)
			return 0;
		else {
			ptr1++;
			ptr2++;
		}
	}
	return 0;
}
*/