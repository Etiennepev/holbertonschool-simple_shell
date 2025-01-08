#include "shell.h"

/**
 * _realloc - Reallocate a memory block.
 * @ptr: Pointer to the previously allocated memory block.
 * @old_size: Size of the old memory block in bytes.
 * @new_size: Size of the new memory block in bytes.
 *
 * Return: Pointer to the newly allocated memory block,
 *         or NULL if the allocation fails or new_size is 0 and ptr is not NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;
    unsigned int i;

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
    {
        new_ptr = malloc(new_size);
        if (new_ptr == NULL)
            return (NULL);
        return (new_ptr);
    }
    if (new_size == old_size)
        return (ptr);

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return (NULL);

    for (i = 0; i < old_size && i < new_size; i++)
        new_ptr[i] = ((char *)ptr)[i];

    free(ptr);

    return (new_ptr);
}
