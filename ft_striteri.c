#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	count;

	if (!s || !f)
		return ;
	count = 0;
	while (*(s + count))
	{
		f(count, (s + count));
		++count;
	}
}