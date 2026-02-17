/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:02:14 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/26 10:16:01 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_writer(int *h, int n, char *base)
{
	char	c;

	while (n >= 0)
	{
		c = base[h[n]];
		write (1, &c, 1);
		n--;
	}
}

void	ft_helper(long int nb, int div, char *base)
{
	int	h[35];
	int	i;

	if (nb == 0)
	{
		write (1, &base[0], 1);
		return ;
	}
	i = 0;
	while (nb != 0)
	{
		h[i] = (nb % div);
		i++;
		nb = nb / div;
	}
	ft_writer (h, i - 1, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				j;
	long int		l;

	i = 0;
	l = nbr;
	while (base[i])
	{
		j = i;
		while (base[j++])
			if (base[i] == base[j])
				return ;
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (nbr < 0)
	{
		write (1, "-", 1);
		l = -l;
	}
	if (i > 1)
		ft_helper(l, i, base);
}
