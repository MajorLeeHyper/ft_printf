/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 15:46:10 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/31 20:02:23 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct		s_bday
{
	size_t			open;
	size_t			close;
	char			type;
	int				width;
	int				width_found;
	int				width_wild_found;
	size_t			width_open;
	size_t			width_close;
	int				precision;
	int				precision_found;
	int				precision_wild_found;
	size_t			precision_index;
	int				negative;
	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				h_len;
	int				hh_len;
	int				l_len;
	int				ll_len;
	int				j_len;
	int				z_len;
	char			unterminated_char;
	int				exit;
}					t_bday;

typedef struct		s_wstring
{
	wchar_t			*data;
	int				bytes;
}					t_wstring;

typedef size_t		(*t_convert)(t_bday *flags, va_list *ap);

int					ft_printf(const char *format, ...);
void				ft_set_zero_values(t_bday *flags);
int					ft_parse_input(const char *format, va_list *ap,
		t_bday *flags);
int					ft_assign_flag(const char *format, t_bday *flags,
		va_list *ap);
int					ft_parse_len(const char *format, t_bday *flags);
int					ft_parse_prefix(const char *format, t_bday *flags);
int					ft_open_flag(const char *format, t_bday *flags);
int					ft_close_flag(const char *format, t_bday *flags,
		size_t index);
size_t				ft_flag_check(t_bday *flags, va_list *ap);
t_convert			ft_identify_flag(char c);
void				ft_initialize_identifier(t_convert *identifier);
int					ft_false_flag(char c);
int					ft_flag_char(char c);
int					ft_valid_flag(char c);
int					ft_skip_flag(const char *format, t_bday *flags);
int					ft_parse_width(const char *format, t_bday *flags,
		va_list *ap);
int					ft_find_width(const char *format, t_bday *flags);
void				ft_skip_wild_arg_width(const char *format, t_bday *flags,
		va_list *ap);
int					ft_str_intlen(const char *format, size_t index,
		size_t close);
int					ft_revstr_intlen(const char *format, t_bday *flags);
int					ft_parse_precision(const char *format, t_bday *flags,
		va_list *ap);
int					ft_find_precision(const char *format, t_bday *flags);
void				ft_skip_wild_arg_prec(const char *format, t_bday *flags,
		va_list *ap);
size_t				ft_process_unterm(const char *format, t_bday *flags,
		va_list *ap);
int					ft_force_close(const char *format, t_bday *flags);
size_t				ft_print_flag(char *str, t_bday *flags);
size_t				ft_print_width(char *str, t_bday *flags);
size_t				ft_convert_char(t_bday *flags, va_list *ap);
size_t				ft_print_flag_char(char *value, t_bday *flags);
size_t				ft_print_width_char(t_bday *flags);
size_t				ft_convert_string(t_bday *flags, va_list *ap);
size_t				ft_print_flag_string(char *str, t_bday *flags);
size_t				ft_print_width_string(char *str, t_bday *flags);
char				*ft_precision_text_value(char *str, t_bday *flags);
char				*pf_itoa_base(uintmax_t num, char *base_chars, size_t base);
size_t				ft_convert_int(t_bday *flags, va_list *ap);
size_t				ft_convert_uint(t_bday *flags, va_list *ap);
size_t				ft_convert_octal(t_bday *flags, va_list *ap);
size_t				ft_convert_upper_hex(t_bday *flags, va_list *ap);
size_t				ft_convert_lower_hex(t_bday *flags, va_list *ap);
intmax_t			ft_int_len(intmax_t num, t_bday *flags);
uintmax_t			ft_uint_len(uintmax_t num, t_bday *flags);
size_t				ft_zero(t_bday *flags);
size_t				ft_convert_float(t_bday *flags, va_list *ap);
char				*ft_float_to_string(double num, t_bday *flags);
double				ft_round(t_bday *flags);
size_t				ft_convert_dlong(t_bday *flags, va_list *ap);
size_t				ft_convert_ulong(t_bday *flags, va_list *ap);
size_t				ft_convert_olong(t_bday *flags, va_list *ap);
intmax_t			ft_negative_num(intmax_t num, t_bday *flags);
intmax_t			ft_negative_width(intmax_t num, t_bday *flags);
size_t				ft_convert_pointer(t_bday *flags, va_list *ap);
size_t				ft_print_flag_pointer(char *str, t_bday *flags);
size_t				ft_print_width_pointer(char *str, t_bday *flags);
size_t				ft_convert_escape(t_bday *flags, va_list *ap);
size_t				ft_print_flag_escape(char *value, t_bday *flags);
size_t				ft_print_width_escape(char *value, t_bday *flags);
size_t				ft_convert_wstring(t_bday *flags, va_list *ap);
void				ft_precision_int_value(char **value, t_bday *flags);
void				ft_set_prefix(t_bday *flags);
size_t				ft_print_prefix(t_bday *flags);
int					ft_find_w_ignore_p(const char *format, t_bday *flags);
int					ft_widthlen_prefix(int len, t_bday *flags);
void				ft_putwchar(wchar_t c);
size_t				ft_putwstr(wchar_t *str, size_t bytes);
int					ft_width_only(const char *format, t_bday *flags);
size_t				ft_parse_width_only(const char *format, t_bday *flags,
		va_list *ap);
size_t				ft_print_width_only(t_bday *flags);
int					ft_parse_w_ignore_p(const char *format, t_bday *flags,
		va_list *ap);
#endif
