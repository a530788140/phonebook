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
		}
		else if (strlen(root->lastName) > strlen(lastname)) {
			root = root->rNext;
		}
		else
			root = root->lNext;
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
			if (strlen(current->lastName) > strlen(lastName))
				current = current->rNext;
			else
				current = current->lNext;
		}
		if (strlen(parent->lastName) > strlen(lastName))
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