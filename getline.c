#include "getline.h"
#include "string.h"

/**
 * _realloc - shifted buffer
 * @old:executed buffer values
 * @old_size: existing buffer output
 * @new_size: expected buffer sixe
 * Return: return NULL if assigned memory fails
 * Otherwise, returned new buffer poiter.
 */
static void *_realloc(void *old, size_t old_size, size_t new_size)
{
	void *new = NULL;

	if (old)
	{
		if (new_size)
		{
			new = malloc(new_size);
			if (new)
			{
				_memcpy(new, old, old_size < new_size ? old_size : new_size);
				free(old);
			}
		}
		else
		{
			free(old);
		}
	}
	return (new);
}

/**
 * _getline_next - identify input values
 * @buf: pointed stable  buffer
 * @line: arranged pointer values
 * @size: execute pointer line size
 * @n: coppied data output
 * Return: whe error outpush return NULL.
 * Otherwise, returned pointer  input.
 */
static char *_getline_next(buf_t *buf, char **line, size_t *size, size_t n)
{
	char *temp = NULL;

	if (*line)
		temp = _realloc(*line, *size, *size + n);
	else
		temp = malloc(n + 1);

	if (temp)
	{
		*line = temp;

		if (*size)
			*size -= 1;

		_memcpy(*line + *size, buf->next, n);
		*size += n;

		(*line)[*size] = '\0';
		*size += 1;
	}
	else
	{
		free(*line);
		*line = NULL;
		*size = 0;
	}
	return (*line);
}

/**
 * _getline_buf - corrected buffer values
 * @table: caption index buffer
 * @fd: file headline
 * Return: NULL or a pointed buffer connected to file headline
 */
static buf_t *_getline_buf(buf_table_t *table, const int fd)
{
	buf_table_node_t *item = NULL;
	size_t index = fd % GETLINE_TABLE_SIZE;

	if (table)
	{
		if (fd < 0)
		{
			for (index = 0; index < GETLINE_TABLE_SIZE; index += 1)
			{
				while ((item = (*table)[index]))
				{
					(*table)[index] = item->next;
					free(item);
				}
			}
		}
		else
		{
			item = (*table)[index];
			while (item && item->fd != fd)
				item = item->next;
			if (item == NULL)
			{
				item = malloc(sizeof(*item));
				if (item)
				{
					item->fd = fd;
					item->buf.next = NULL;
					item->buf.remaining = 0;
					item->next = (*table)[index];
					(*table)[index] = item;
				}
			}
		}
	}
	return (item ? &item->buf : NULL);
}

/**
 * _getline - execute input
 * @fd: read file caption.
 * Return: return NULL when error is detected.
 * Otherwise, return next values.
 */
char *_getline(const int fd)
{
	static buf_table_t table;
	buf_t *buf = _getline_buf(&table, fd);
	char *line = NULL;
	size_t size = 0;
	ssize_t eol = 0, n_read = 0;

	if (buf)
	{
		do {
			if (buf->remaining == 0)
				buf->next = buf->buffer;
			if (n_read)
				buf->remaining = n_read;
			if (buf->remaining)
			{
				eol = _memchr(buf->next, '\n', buf->remaining);
				if (eol == -1)
				{
					if (_getline_next(buf, &line, &size, buf->remaining))
						buf->next += buf->remaining, buf->remaining = 0;
					else
						break;
				}
				else
				{
					if (_getline_next(buf, &line, &size, eol + 1))
						buf->next += eol + 1, buf->remaining -= eol + 1;
					break;
				}
			}
		} while ((n_read = read(fd, buf->buffer, GETLINE_BUFFER_SIZE)) > 0);
		if (n_read == -1)
		{
			free(line);
			line = NULL;
			size = 0;
		}
	}
	return (line);
}
