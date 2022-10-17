#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int ft_printf(const char *format, ... );
int	ft_putstr(char *str);
int	ft_putnumber(long nb, int base, char *base_char);
int	ft_puthexa(unsigned nb, unsigned base, char *base_char);

int ft_putstr(char *str)
{
	int	n = 0;
	char *s;

	s = str;
	if (!s)
		s = "(null)";
	while (s[n])
		++n;
	write(STDOUT_FILENO, s, n);
	return (n);
}

int	ft_putnumber(long nb, int base, char *base_char)
{
	int i = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(STDOUT_FILENO, "-", 1);
	}
	if (nb >= base)
		i += ft_putnumber(nb / base, base, base_char);
	write(STDOUT_FILENO, base_char + (nb % base), 1);
	return (i + 1);
}

int	ft_puthexa(unsigned nb, unsigned base, char *base_char)
{
	int i = 0;
	if (nb >= base)
		i += ft_puthexa(nb / base, base, base_char);
	write(STDOUT_FILENO, base_char + (nb % base), 1);
	return (i + 1);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n = 0;
	char	*str;
	long	dec;
	int		hex;

	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 's')
			{
				str = va_arg(ap, char *);
				n += ft_putstr(str);
			}
			if (*format == 'd')
			{
				dec = va_arg(ap, int);
				n += ft_putnumber(dec, 10, "0123456789");
			}
			if (*format == 'x')
			{
				hex = va_arg(ap, int);
				n += ft_puthexa(hex, 16, "0123456789abcdef");
			}
		}
		else
			n += write(STDOUT_FILENO, format, 1);
		++format;
	}
	va_end(ap);
	return (n);
}

int main()
{
	int	a, b;
	char	*empty = NULL;
	a = ft_printf("%s\n", "toto");
	b = printf("%s\n", "toto");
	printf("a,b:%d,%d\n", a, b);
	a = ft_printf("Magic %s is %d\n", "number", INT_MAX);
	b = printf("Magic %s is %d\n", "number", INT_MAX);
	printf("a,b:%d,%d\n", a, b);
	a = ft_printf("Hexadecimal for %d is %x\n", INT_MAX, INT_MAX);
	b = printf("Hexadecimal for %d is %x\n", INT_MAX, INT_MAX);
	printf("a,b:%d,%d\n", a, b);
	a = ft_printf("empty %s\n", empty);
	b = printf("empty %s\n", empty);
	printf("a,b:%d,%d\n", a, b);
	return (0);
}