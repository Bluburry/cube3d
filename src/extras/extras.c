#include "cube.h"

char	*cpy_line(const char *src)
{
	if (!src || !src[2] || !src[3])
		return (NULL);
	auto int i = 2;
	while (src[i] && src[i] == ' ')
		i++;
	auto size_t	s = ft_strlen(src + i);
	auto char *dst = (char *) malloc ((s) * sizeof(char));
	if (!dst)
	{
		printf("Memory allocation error.\n");
		return (NULL);
	}
	ft_memcpy(dst, src + i, s - 1);
	s -= 2;
	while (dst[s] && dst[s] == ' ')
		s--;
	dst[s + 1] = 0;
	return (dst);
}
