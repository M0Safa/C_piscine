/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:28:25 by mosafa            #+#    #+#             */
/*   Updated: 2025/08/03 22:33:03 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	**storing(char *fl);

void	rd_number(char *nb, char **arr);

int	input_check(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	if (i > 39)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*fl;
	char	**arr;

	fl = "numbers.dict";
	if ((argc == 3 || argc == 2) && input_check(argv[1]))
	{
		if (argc == 3)
			fl = argv[2];
		arr = storing(fl);
		if (arr == NULL)
		{
			write (1, "Error", 5);
			return (0);
		}
		rd_number(argv[1], arr);
	}
	else
		write(1, "Error", 5);
	return (0);
}
