#include "get_next_line.h"

# include <stdio.h>

char	*ft_strchr(char *s, int c)
{
	int i = 0;
		while(s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			return s + i;
		else
			return NULL;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return NULL;
	if (src == dest || n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char *)src)[i];
		i++;
	}
	return dest;
}

size_t	ft_strlen(char *s)
{
	size_t i;

	if (!s)
		return ((size_t)NULL);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	str_append_mem(char *s1, char *s2, size_t size2)
{
	size_t size1 = ft_strlen(s1);
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return 0;
	ft_memcpy(tmp, s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	//free(s1);
	printf("%s\n", tmp);
	*s1 = *tmp;
	return 1;
}

int	str_append_str(char *s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return ft_memcpy(dest, src, n);
	else if (dest == src)
		return dest;
		size_t i = ft_strlen((char *)src) - 1;
	while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	return dest;
}

char	*get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char *ret = NULL;
	char *tmp = ft_strchr(b, '\n');
	while (!tmp) {
		if (!str_append_str(ret, b))
			return NULL;
		int read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return NULL;
		b[read_ret] = 0;
	}
	if (!str_append_mem(ret, b, tmp - b + 1))
	{
		free(ret);
		return NULL;
	}
	return ret;
}

int		main(void)
{
	char *line;
	int	fd;

	fd = open("get_next_line.c", O_RDONLY);
	if (fd)
		printf("success opening file. fd = %i\n", fd);
	line = get_next_line(fd);
	printf("%s", line);

	return (0);
}
