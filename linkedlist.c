#include "shell.h"

/**
 * create_linkedt - creates empty linked list the size of the path variable
 * @path_var: PATH variable name
 *
 * Return: a pointer to the empty linked list
 */
linked_t *create_linkedt(char *path_var)
{
	int i = 0;
	int num_nodes = 1;
	linked_t *current_node, *list_head, *prev_node, *list_end;

	prev_node = malloc(sizeof(linked_t));

	if (prev_node == NULL)
		return (NULL);
	list_head = prev_node;

	list_end = malloc(sizeof(linked_t));
	if (list_end == NULL)
	{
		free(prev_node);
		return (NULL);
	}
	list_end->next = NULL;

	while (path_var[i] != '\0')
	{
		if (path_var[i] == ':')
			num_nodes++;
		i++;
	}

	while ((num_nodes - 2) > 0)
	{
		current_node = malloc(sizeof(linked_t));
	if (current_node == NULL)
	{
		free(prev_node);
		free(list_end);
		return (NULL);
	}
	prev_node->next = current_node;
	prev_node = prev_node->next;
	num_nodes--;
	}
	prev_node->next = list_end;
	return (list_head);
}

/**
 * addnodes_list - add PATH variable contents to empty
 * @new_str: PATH variable name
 * @new_list: pointer to the empty linked list
 * Return: pointer to the resultant linked list
 */

linked_t *addnodes_list(char *new_str, linked_t *new_list)
{
	linked_t *new_ptr, *new_head;
	char *new_dir;
	int new_i = 0, new_j = 0, new_stcnt = 0, new_dirlen = 0;

	if (new_str ==  NULL || new_list == NULL)
		return (NULL);
	new_head = new_list;
	new_ptr = new_head;
	while (new_ptr != NULL)
	{
		if (new_str[new_i] == ':' || new_str[new_i] == '\0')
		{
			if (new_str[new_i] != '\0')
				new_i++;
			new_dir = malloc(sizeof(char) * new_dirlen + 2);
			if (new_dir == NULL)
				return (NULL);
			while (new_str[new_stcnt] != ':' && new_str[new_stcnt] != '\0')
			{
				new_dir[new_j] = new_str[new_stcnt];
				new_stcnt++;
				new_j++;
			}
			new_dir[new_j++] = '/';
			new_dir[new_j] = '\0';
			new_stcnt = new_i;
			new_j = 0;
			new_ptr->directory = new_dir;
			new_ptr = new_ptr->next;
		}
		else
		{
			new_dirlen++;
			new_i++;
		}
	}
	return (new_head);
}
