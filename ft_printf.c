#include "ft_printf.h"

void		ft_dump_buff(t_tab *tab)
{
	write(1, tab->buf, tab->buf_count);
	tab->buf_count = 0;
}

void		ft_add_to_buff(t_tab *tab, char *str, int len)
{
	int	i;

	i = 0;
	tab->ret += len;
	while (i < len)
	{
		tab->buf[tab->buf_count] = str[i];
		tab->buf_count++;
		if (tab->buf_count == BUFFER_SIZE)
			ft_dump_buff(tab);
		i++;
	}
}

void		ft_print(t_tab *tab, char *str)
{
	int	len;

	len = 0;
	while (str[tab->i] && str[tab->i] != '%')
	{
		tab->buf[tab->buf_count] = str[tab->i];
		tab->buf_count++;
		len++;
		if (tab->buf_count == BUFFER_SIZE)
			ft_dump_buff(tab);
		tab->i++;
	}
	tab->ret += len;
	tab->i--;
}

void		init_struct(t_tab *tab)
{
	tab->buf_count = 0;
	tab->ret = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->precision_width = 0;
	tab->precision_parsing = 0;
	tab->conv = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->plus = 0;
	tab->space = 0;
	tab->sharp = 0;
	tab->len = 0;
	tab->sp_len = 0;
	tab->is_int = 0;
	tab->h_count = 0;
	tab->l_count = 0;
	tab->n = 0;
	tab->u = 0;
	tab->i = 0;
}

int			ft_printf(const char *format, ...)
{
	t_tab		tab;
	va_list		ap;

	init_struct(&tab);
	va_start(ap, format);
	while (format[tab.i])
	{
		if (format[tab.i] == '%')
		{
			if (format[tab.i + 1] == '\0')
				break ;
			if (ft_is_from_pf(format[tab.i + 1]))
				ft_parse((char *)format, ap, &tab);
		}
		else
			ft_print(&tab, (char *)format);
		tab.i++;
	}
	va_end(ap);
	ft_dump_buff(&tab);
	return (tab.ret);
}
