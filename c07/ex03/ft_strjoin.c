/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:42:23 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/30 09:13:43 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
}

char	*ft_empty(void)
{
	char	*p;

	p = malloc(1);
	if (p == NULL)
		return (p);
	*p = '\0';
	return (p);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sz;
	char	*str;
	int		i;

	if (size == 0)
		return (ft_empty());
	sz = 0;
	i = 0;
	while (i < size)
		sz = sz + (ft_size(strs[i++]));
	sz = sz + (ft_size(sep) * (size - 1));
	str = malloc(sizeof(char) * (sz + 1));
	if (str == NULL)
		return (str);
	str[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i != size - 1)
			ft_strcat(str, sep);
		i++;
	}
	ft_strcat(str, "\0");
	return (str);
}
