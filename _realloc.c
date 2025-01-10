#include "shell.h"

/**
 * *_realloc - reallocates a memory block using malloc and free.
 * @ptr : pointer to the memory previously allocated.
 * @old_size :  is the size, in bytes, of the allocated space for ptr.
 * @new_size : is the new size, in bytes of the new memory block.
 * Return: the pointer to the new memory block of NULL if error.
 **/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int min_size;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		min_size = old_size < new_size ? old_size : new_size;
		_memcpy(new_ptr, ptr, min_size);
		free(ptr);
	return (new_ptr);
}

/**
 * _memcpy - copies memory area.
 * @dest: memory area of destination.
 * @n: number of byte to copy.
 * @src : memory area to copy.
 * Return: a pointer to the memory area dest.
 **/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
