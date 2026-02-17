/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:28:39 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/28 10:49:34 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*ptr;

	if (min >= max)
		return (0);
	i = min;
	j = 0;
	ptr = malloc(4 * (max - min));
	while (i < max)
		ptr[j++] = i++;
	return (ptr);
}
