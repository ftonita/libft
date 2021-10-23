#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len)
	{
		((char *)dst)[len - 1] = ((char *)src)[len - 1];
		len--;
	}
	return (dst);
}
