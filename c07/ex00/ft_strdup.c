/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:20:24 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/29 08:34:31 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
