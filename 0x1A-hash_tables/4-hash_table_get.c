4-hash_table_get.c
#include "hash_tables.h"

/**
 * hash_table_get - Get value associated with
 *                  a key in a hash table.
 * @ht: Pointer to hash table.
 * @key: key.
 *
 * Return: If key not matched return NULL.
 *         else the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}
