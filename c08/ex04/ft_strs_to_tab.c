/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:29:29 by mosafa            #+#    #+#             */
/*   Updated: 2025/08/04 12:58:08 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		size;
	char	*ptr;

	size = 0;
	while (src[size])
		size++;
	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	size = 0;
	while (src[size])
	{
		ptr[size] = src[size];
		size++;
	}
	ptr[size] = '\0';
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*strs;
	int					i;

	strs = malloc(sizeof(t_stock_str) * (ac + 1));
	if (strs == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		(strs[i]).size = ft_strlen(av[i]);
		(strs[i]).str = av[i];
		(strs[i]).copy = ft_strdup(av[i]);
		i++;
	}
	(strs[i]).str = 0;
	(strs[i]).copy = 0;
	return (strs);
}
