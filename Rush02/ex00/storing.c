/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:14:57 by mosafa            #+#    #+#             */
/*   Updated: 2025/08/03 22:05:33 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	**ft_split(char *str, char *charset);

void	trim2(char *fl, char *h);

void	trim(char *h);

char	**storing(char *fl)
{
	int		i;
	int		fd;
	char	*h;
	char	**arr;
	char	reader;

	i = 0;
	fd = open(fl, O_RDONLY);
	while (read(fd, &reader, 1) > 0)
		i++;
	close(fd);
	h = malloc(i + 1);
	i = 0;
	fd = open(fl, O_RDONLY);
	while (read(fd, &reader, 1) > 0)
		h[i++] = reader;
	h[i] = '\0';
	close(fd);
	trim(h);
	arr = ft_split(h, "\n");
	free(h);
	return (arr);
}

int	finish(int *start, char *str)
{
	int	s;

	s = *start;
	while (str[s + 1] != '\n' && str[s + 1])
		s++;
	*start = s + 2;
	while (str[s] == ' ')
		s--;
	return (s);
}

int	counting(char *h)
{
	int		i;
	int		sz;

	i = 0;
	sz = 0;
	while (h[i])
	{
		if (h[i] == '\n')
			sz++;
		i++;
	}
	return (sz);
}

void	trim(char *h)
{
	int	j;
	int	s;
	int	end;
	int	sz;
	int	start;

	s = 0;
	start = 0;
	sz = counting(h);
	while (sz > 0)
	{
		j = start;
		end = finish(&start, h);
		while ((h[j] >= '0' && h[j] <= '9'))
			h[s++] = h[j++];
		while ((h[j] == ' ' || h[j] == ':') && h[j])
			j++;
		h[s++] = ':';
		while (j <= end)
			h[s++] = h[j++];
		h[s++] = '\n';
		sz--;
	}
	h[s] = '\0';
}
