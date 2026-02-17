/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:38:29 by mosafa            #+#    #+#             */
/*   Updated: 2025/08/07 17:00:00 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int a, int b);

int	sub(int a, int b);

int	div(int a, int b);

int	modulo(int a, int b);

int	mult(int a, int b);

int	ft_atoi(char *str)
{
	int	sum;
	int	f;
	int	i;

	sum = 0;
	i = 0;
	f = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			f = -f;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (f * sum);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	do_op(int a, int b, char c, int (*op[5])(int, int))
{
	if (c == '+')
		ft_putnbr (op[0](a, b));
	else if (c == '-')
		ft_putnbr (op[1](a, b));
	else if (c == '*')
		ft_putnbr (op[4](a, b));
	else if (c == '/' && b != 0)
		ft_putnbr (op[2](a, b));
	else if (c == '/' && b == 0)
		write(1, "Stop : division by zero", 23);
	else if (c == '%' && b != 0)
		ft_putnbr (op[3](a, b));
	else if (c == '%' && b == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	int	(*op[5])(int, int);
	int	a;
	int	b;

	op[0] = &add;
	op[1] = &sub;
	op[2] = &div;
	op[3] = &modulo;
	op[4] = &mult;
	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (argv[2][1] == '\0')
			do_op(a, b, argv[2][0], op);
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
	return (0);
}
