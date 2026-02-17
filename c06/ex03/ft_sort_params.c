/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:15:02 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/28 09:35:44 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_writer(char **argv, int argc)
{
	int		i;
	int		j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			write (1, &argv[j][i], 1);
			i++;
		}
		write (1, "\n", 1);
		j++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char *argv[])
{
	int	j;
	int	i;

	j = 1;
	while (j < argc)
	{
		i = j;
		while (i < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) < 0)
				ft_swap (&argv[i], &argv[j]);
			i++;
		}
		j++;
	}
	ft_writer(argv, argc);
}
