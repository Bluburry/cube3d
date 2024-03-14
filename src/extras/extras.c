#include "cube.h"

char	*cpy_line(const char *src)
{
	if (!src || !src[2] || !src[3])
		return (NULL);
	auto size_t	s = ft_strlen(src + 3);
	auto char *dst = (char *) malloc ((s) * sizeof(char));
	if (!dst)
	{
		printf("Memory allocation error.\n");
		return (NULL);
	}
	ft_memcpy(dst, src + 3, s - 1);
	dst[s - 1] = 0;
	return (dst);
}

int	creatergb(unsigned int *clr, char *sub_str)
{
	if (!ft_isdigit(sub_str[0]))
		return (0);
    auto char **values = ft_split(sub_str, ',');
    auto int rgb[3];
    auto int i = -1;
    while (values[++i])
    {
		if (i >= 3 || (!ft_check_alnum(values[i]) && \
			values[i][ft_strlen(values[i]) - 1] != '\n'))
		{
        	printf("Wrong rgb values!\n");
			break ;
		}
        rgb[i] = ft_atoi(values[i]);
        if (rgb[i] > 255 || rgb[i] < 0)
        {
            printf("rgb wrong value!\n");
			break ;
        }
    }
	clear_matrix(values, -1);
	if (i != 3)
		return (0);
	*clr = ((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + (rgb[2] & 0xff);
	return (1);
}

/*
	ret for debugging purposes
	ret = 1 -> error from previous function (duplicate texture/colour error)
	^ now already returned returned from calling function
	ret = 2 -> duplicate colour/missing texture
	ret = 3 -> invalid character found in map section
*/
int	final_checker(int fd, char *checker, char *ptr)
{
	auto int ret = 0, i = -1, j;
	while (!ret && ++i < 6)
		if (checker[i] != 1)
			ret = 2;
	while (!ret)
	{
		ptr = get_next_line(fd, 1000);
		if (!ptr)
			break ;
		j = -1;
		while(!ret && ptr[++j])
		{
			if (ptr[j] != ' ' && ptr[j] != '0' && ptr[j] != '1' && \
				ptr[j] != 'N' && ptr[j] != 'S' && ptr[j] != 'W' && \
				ptr[j] != 'E' && ptr[j] != '\n')
				ret = 3;
		}
		free(ptr);
	}
	return (ret);
}
