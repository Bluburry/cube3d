#include "cube.h"

int	cpy_line(char *dst, const char *src)
{
	size_t	s;

	if (!src)
		return (0);
	s = ft_strlen(src);
	dst = (char *) malloc ((s) * sizeof(char));
	if (!dst)
	{
		printf("Memory allocation error.\n");
		return (0);
	}
	ft_memcpy(dst, src, s);
	dst[s - 1] = 0;
	return (1);
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
