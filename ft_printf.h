#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
# endif

typedef struct	s_tab
{
	char			buf[BUFFER_SIZE + 1];
	int				buf_count;
	int				ret;
	int				width;
	int				precision;
	int				precision_width;
	int				precision_parsing;
	int				conv;
	int				minus;
	int				zero;
	int				plus;
	int				space;
	int				sharp;
	int				len;
	int				sp_len;
	int				is_int;
	int				h_count;
	int				l_count;
	intmax_t		n;
	uintmax_t		u;
	int				i;
}				t_tab;

int				ft_printf(const char *format, ...);
void			init_struct(t_tab *tab);
void			ft_str_it(va_list ap, t_tab *tab, char *str);
void			ft_parse(char *str, va_list ap, t_tab *tab);
int				ft_parse2(char *str, va_list ap, t_tab *tab);
void			ft_check_flag(char *str, va_list ap, t_tab *tab);
void			ft_add_to_buff(t_tab *tab, char *str, int len);
void			ft_dump_buff(t_tab *tab);
void			ft_print(t_tab *tab, char *str);
void			ft_conv_str(va_list ap, t_tab *tab);
void			ft_conv_int(va_list ap, t_tab *tab);
void			ft_conv_uint(va_list ap, t_tab *tab);
void			ft_conv_x(va_list ap, t_tab *tab);
void			ft_conv_p(va_list ap, t_tab *tab);
void			ft_conv_c(va_list ap, t_tab *tab);
void			ft_conv_n(va_list ap, t_tab *tab);
void			ft_conv_o(va_list ap, t_tab *tab);
void			ft_size_int(va_list ap, t_tab *tab);
void			ft_size_u(va_list ap, t_tab *tab);
char			*ft_strdup_l(char *s, t_tab *tab);
char			*ft_strdup(const char *s1);
char			*ft_print_sp(t_tab *tab);
char			*ft_num_precision(char *str, t_tab *tab);
void			ft_join_all(char *str, char *sp, t_tab *tab);
char			*ft_c_to_str(char c);
void			ft_add_sign(t_tab *tab);
void			ft_add_prefix(t_tab *tab);
int				ft_atoi_printf(char *str, int *i);
char			*itoa_printf(intmax_t n);
char			*uitoa_printf(uintmax_t n);
char			*ft_uitoa(uintmax_t n);
char			*itoa_base_pf(uintmax_t num, char *base);
char			*ft_itoa_base(uintmax_t n, char *base);
size_t			intlen_printf(intmax_t n);
size_t			ft_intlen(intmax_t n);
size_t			ft_intlen_base(uintmax_t n, char *base);
size_t			uintlen_printf(uintmax_t n);
size_t			ft_uintlen(uintmax_t n);
size_t			intlen_base_pf(uintmax_t n, char *base);
void			ft_set_precision(t_tab *tab);
void			ft_reset_flags(t_tab *tab);
size_t			ft_is_flag(char c);
size_t			ft_is_from_pf(char c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nitems, size_t size);

#endif
