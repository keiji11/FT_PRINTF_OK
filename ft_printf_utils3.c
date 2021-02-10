#include "ft_printf.h"

size_t		ft_intlen(intmax_t n)
{
	size_t	len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa_base(uintmax_t n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_intlen_base(n, base);
	base_len = ft_strlen(base);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

char		*ft_uitoa(uintmax_t n)
{
	char	*str;
	int		num_len;

	num_len = ft_uintlen(n);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
