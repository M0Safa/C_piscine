/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:59:44 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/20 08:30:07 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	fct_l(char c, int n)
{
	if (n <= 0)
		return ;
	while (n-- > 0)
	{
		ft_putchar(c);
	}
}

void	fct_h(int x)
{
	ft_putchar('o');
	fct_l('-', x - 2);
	if (x != 1)
		ft_putchar('o');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x <= 0 || y <= 0)
	{
		write (1, "error enter only positive nb", 28);
		return ;
	}
	fct_h(x);
	while (i < y - 2)
	{
		ft_putchar('\n');
		ft_putchar('|');
		fct_l(' ', x - 2);
		if (x != 1)
			ft_putchar('|');
		i++;
	}
	if (y != 1)
	{
		ft_putchar('\n');
		fct_h(x);
	}
}
