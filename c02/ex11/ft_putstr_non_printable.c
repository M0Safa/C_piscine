/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:53:56 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/21 15:14:36 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int	ft__printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

void	ft_hex(char c)
{
	char	c1;
	char	c2;

	if (c / 16 > 9)
		c2 = (c / 16) - 10 + 'a';
	else
		c2 = (c / 16) + '0';
	if (c % 16 > 9)
		c1 = (c % 16) - 10 + 'a';
	else
		c1 = (c % 16) + '0';
	write (1, "\\", 1);
	write (1, &c2, 1);
	write (1, &c1, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = ft__printable(*str);
		if (i == 0)
			ft_hex(*str);
		else
			write (1, str, 1);
		str++;
	}
}
