/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:57:00 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/30 11:11:07 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);

int	ft_atoi_base(char *str, char *base);

char	*ft_helper(char *str, long int nb, int div, char *base)
{
	int	h[35];
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (nb < 0)
	{
		nb = -nb;
		j++;
	}
	while (nb != 0)
	{
		h[i] = (nb % div);
		i++;
		nb = nb / div;
	}
	i--;
	while (i >= 0)
		str[j++] = base[h[i--]];
	str[j] = '\0';
	return (str);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int			i;
	long int	l;
	char		*str;

	i = check_base(base);
	if (i < 2)
		return (NULL);
	l = nbr;
	str = malloc(34 * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nbr == 0)
	{
		*str = base[0];
		str[1] = '\0';
		return (str);
	}
	if (nbr < 0)
		*str = '-';
	return (ft_helper(str, l, i, base));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (check_base(base_from) < 2)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(nb, base_to));
}
