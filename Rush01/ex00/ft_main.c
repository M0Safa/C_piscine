/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:13:21 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/27 13:37:35 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	backtracking(int tab[][4], int cnd[][4], int row, int col);

int	check_input(char *input)
{
	int	i;

	i = 0;
	if (*input == '\0')
		return (0);
	while (i < 30)
	{
		if (input[i] >= '1' && input[i] <= '4' && input[i + 1] == ' ')
			i = i + 2;
		else
			return (0);
	}
	if (i == 30 && input[i + 1] == '\0')
	{
		if (input[i] >= '1' && input[i] <= '4')
			return (1);
	}
	return (0);
}

void	insert(char *input, int cnd[][4])
{
	int	row;
	int	col;
	int	i;

	i = 0;
	row = 0;
	col = 0;
	while (row < 4)
	{
		cnd[row][col] = input[i] - '0';
		i = i + 2;
		if (col == 3)
		{
			row++;
			col = 0;
		}
		else
			col++;
	}
}

void	print_tab(int tab[][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write (1, &c, 1);
			if (j != 3)
				write (1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	tab[4][4];
	int	cnd[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			tab[i][j++] = 0;
		i++;
	}
	if (argc == 2 && check_input(argv[1]) == 1)
	{
		insert(argv[1], cnd);
		if (backtracking(tab, cnd, 0, 0) == 1)
			print_tab(tab);
		else
			write (1, "Error\n", 6);
	}
	else
		write (1, "Error\n", 6);
	return (0);
}
