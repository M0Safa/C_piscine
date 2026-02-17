/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:31:09 by mosafa            #+#    #+#             */
/*   Updated: 2025/08/07 15:51:40 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*a;

	i = 0;
	a = malloc(sizeof(int) * length);
	while (i < length)
	{
		a[i] = f(tab[i]);
		i++;
	}
	return (a);
}
