#include "ft_printf.h"

size_t		ft_intlen_base(uintmax_t n, char *base)
{
	size_t		len;
	uintmax_t	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

size_t		ft_uintlen(uintmax_t n)
{
	size_t len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void		*ft_memset(void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void		*ft_calloc(size_t nitems, size_t size)
{
	void	*ret;

	if (!(ret = malloc(nitems * size)))
		return (NULL);
	ft_bzero(ret, nitems * size);
	return (ret);
}
