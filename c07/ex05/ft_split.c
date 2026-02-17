/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:38:49 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/31 09:13:05 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		if (c == sep[i++])
			return (1);
	return (0);
}

int	ft_count(int start, char *str, char *charset, int stop)
{
	int	i;
	int	f;
	int	count;

	i = start;
	f = 0;
	count = 0;
	while (str[i])
	{
		if (check_sep(str[i], charset) && f == 1)
		{
			if (stop)
				return (i);
			count++;
			f = 0;
		}
		else if (check_sep(str[i], charset) == 0)
			f = 1;
		i++;
	}
	if (f == 1)
		count++;
	return (count);
}

void	ft_strncat(int s, char *dest, char *src, char *sep)
{
	int	i;
	int	f;
	int	j;

	i = s;
	f = 0;
	j = 0;
	while (src[i])
	{
		if (check_sep(src[i], sep) && f == 1)
			return ;
		else if (check_sep(src[i], sep) == 0)
		{
			dest[j++] = src[i];
			f = 1;
		}
		i++;
	}
	dest[j] = '\0';
}

void	ft_helper(char **split, char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_count(0, str, charset, 0))
	{
		ft_strncat(j, split[i++], str, charset);
		j = ft_count(j, str, charset, 1);
	}
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**split;

	split = malloc(sizeof(char *) * (ft_count(0, str, charset, 0) + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_count(0, str, charset, 0))
	{
		j = ft_count(j, str, charset, 1);
		split[i++] = malloc(j + 1);
		if (split[i - 1] == NULL)
			return (NULL);
	}
	split[i] = malloc(1);
	split[i] = NULL;
	ft_helper(split, str, charset);
	return (split);
}
