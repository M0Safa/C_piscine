/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:48:46 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/26 10:52:45 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_helper(char *str, char *base, int div)
{
	long int	sum;
	int			f;
	int			i;

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
	while (ft_check(str[i], base))
	{
		sum = (sum + ft_index(str[i], base)) * div;
		i++;
	}
	return (f * (sum / div));
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i;
		while (base[j++])
			if (base[i] == base[j])
				return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		i++;
	}
	if (i > 1)
		return (ft_helper(str, base, i));
	return (0);
}
