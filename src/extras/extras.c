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
    char    **values;
    int     rgb[3];

    values = ft_split(sub_str, ',');
    auto int     i = -1;
    while (values[++i])
    {
		if (i > 3)
		{
        	printf("rgb wrong amount of values!\n");
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
