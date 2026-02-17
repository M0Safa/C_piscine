/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:40:34 by mosafa            #+#    #+#             */
/*   Updated: 2025/08/03 23:06:02 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdlib.h>

char	**storing(char *fl);

void	value_wr(char *key, char **arr, int space);

void	rd_2(char *mult, char *nb, char **arr, int l);

void	fill(char *h)
{
	h[0] = '0';
	h[1] = '0';
	h[2] = '0';
	h[3] = '\n';
}

void	trio_wr(char a, char b, char c, char **arr)
{
	char	nb[4];

	fill(nb);
	if (a > '0')
	{
		nb[0] = a;
		nb[1] = '\0';
		value_wr(nb, arr, 1);
		value_wr("100", arr, 1);
	}
	nb[2] = '\0';
	nb[0] = b;
	nb[1] = '0';
	if (b > '1')
		value_wr(nb, arr, 1);
	else if (b == '1')
	{
		nb[1] = c;
		value_wr(nb, arr, 1);
		return ;
	}
	nb[1] = '\0';
	nb[0] = c;
	if (c > '0')
		value_wr(nb, arr, 1);
}

void	value_wr(char *key, char **arr, int space)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] == key[j] && key[j])
			j++;
		if (key[j] == '\0' && (arr[i][j] < '0' || arr[i][j] > '9'))
		{
			j++;
			while (arr[i][j])
				write(1, &arr[i][j++], 1);
			if (space)
				write(1, " ", 1);
			return ;
		}
		i++;
	}
}
int	if_0(char *nb)
{
	int 	i;
	
	i = 0;
	while(nb[i])
	{
		if(nb[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	rd_number(char *nb, char **arr)
{
	int		i;
	int		j;
	char	*mult;

	j = 0;
	if (if_0(nb))
	{
		value_wr("0", arr, 1);
		return ;
	}
	while (nb[j])
		j++;
	i = j - (j % 3) + 1;
	j = 1;
	mult = malloc(i + 1);
	mult[0] = '1';
	while (j < i)
		mult[j++] = '0';
	mult[j] = '\0';
	rd_2(mult, nb, arr, i);
}

void	rd_2(char *mult, char *nb, char **arr, int l)
{
	int		j;
	int		s;
	int		d;
	char 	set[4];

	fill(set);
	d = 0;
	j = 0;
	while (nb[d])
		d++;
	if (d % 3 == 2)
	{
		set[1] = nb[j++];
		set[2] = nb[j++];
	}
	if (d % 3 == 1)
		set[2] = nb[j++];
	s = d / 3 + 1;
	while (s > 0)
	{
		if (set[0] != '0' || set[1] != '0' || set[2] != '0')
		{
			trio_wr(set[0], set[1], set[2] ,arr);
			if (l != 1)
				value_wr(mult, arr, 1);
		}
		l = l - 3;
		mult[l] = '\0';
		set[0] = nb[j++];
		set[1] = nb[j++];
		set[2] = nb[j++];
		s--;
	}
	free(mult);
}



