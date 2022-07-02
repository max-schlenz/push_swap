/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:24:36 by mschlenz          #+#    #+#             */
/*   Updated: 2022/05/27 15:13:54 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	print_var(const char f_specifier, va_list args)
{
	int	ret;

	ret = 0;
	if (f_specifier == 'c')
		ret = print_char(args);
	else if (f_specifier == 's')
		ret = print_string(args);
	else if (f_specifier == 'p')
		ret = print_pointer(args);
	else if (f_specifier == 'd' || f_specifier == 'i')
		ret = print_int(args);
	else if (f_specifier == 'u')
		ret = print_uint(args);
	else if (f_specifier == 'x')
		ret = print_hex(args, 1);
	else if (f_specifier == 'X')
		ret = print_hex(args, 0);
	else if (f_specifier == '%')
	{
		ft_putchar_fd('%', 1);
		ret = 1;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	int		ret_tmp;
	va_list	args;

	va_start(args, format);
	i = 0;
	ret = 0;
	ret_tmp = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret_tmp = print_var(format[i + 1], args);
			ret += ret_tmp - 2;
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
	i++;
	}
	va_end(args);
	return (ret + i);
}

/*
#include "libft/ft_putchar_fd.c"
#include "libft/ft_putstr_fd.c"
#include "libft/ft_strlen.c"
#include "libft/ft_itoa.c"
#include "libft/ft_tolower.c"
#include "ft_printf_csi.c"
#include "ft_printf_p.c"
#include "ft_printf_u.c"
#include "ft_printf_xX.c"
#include <limits.h>

int	main(void)
{
	//char *a = "42";
	//int ret = 0;
	//int ret2 = 0;

//	ret = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
//	ret2 = printf(" %p %p ", LONG_MIN, LONG_MAX);
	
//	printf("\n%d, %d\n", ret, ret2);

//	ret = printf(" %p %p ", LONG_MIN, LONG_MAX);
//	printf("\n%d\n", ret);
// ret = ft_printf("this is the real number: %x", -1u);;
// 	printf("\n%d\n", ret);
//ret = printf("this is the real number: %x", -1u);;
//printf("\n%d\n", ret);

	// ret = ft_printf("\n   char: %c, %c\n", 'a', 'b');
	// //	printf("%d\n", ret);
	// ret = ft_printf(" string: %s, %s\n", "abc", "123");
	// //	printf("%d\n", ret);
	// ret = ft_printf("pointer: %p\n", a);
	// //	printf("%d\n", ret);
	// ret = ft_printf("decimal: %d, %d\n", -123, 456);
	// //	printf("%d\n", ret);
	// ret = ft_printf("percent: %%\n");
	// //	printf("%d\n", ret);
	// ret = ft_printf("   hexa: %X\n", 42);
	// //	printf("%d\n", ret);
	// ret = ft_printf("lc hexa: %x\n", 42);
	// //	printf("%d\n", ret);
	// ret = ft_printf("   uint: %u\n", 42);
	// //	printf("%d\n", ret);

//	ft_printf("\n  mixed >> string: %s, int/dec: %d, \
	unsigned int: %u, hexa: %X, hexa lowercase: %x, \
	char: %c, pointer-addr: %p, percent sign: %%\n", \
	"abc", -123, 123, 1234, 1234, 'd', a);
// 	printf("\n%c\n", '0');
// 	ft_printf("%c\n", '0');
}
*/