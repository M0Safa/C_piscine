/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:31:37 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/23 12:20:36 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ds;

	i = 0;
	ds = 0;
	while (*dest)
	{
		dest++;
		ds++;
	}
	while (src[i])
		i++;
	if (ds >= size)
		return (size + i);
	i = 0;
	while (i < size - ds - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i + ds);
}
