/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:09:02 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/27 13:43:39 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_table(int tab[][4], int cnd[][4]);

int	check_validation(int tab[][4], int col, int row, int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (val == tab[row][i] || val == tab[i][col])
			return (0);
		i++;
	}
	return (1);
}

int	backtracking(int tab[][4], int cnd[][4], int row, int col)
{
	int	i;

	if (col == 0 && row == 4)
		return (check_table(tab, cnd));
	i = 1;
	while (i < 5)
	{
		if (check_validation(tab, col, row, i) == 1)
		{
			tab[row][col] = i;
			if (col < 3)
			{
				if (backtracking(tab, cnd, row, col + 1) == 1)
					return (1);
			}
			else
				if (backtracking(tab, cnd, row + 1, 0) == 1)
					return (1);
		}
		tab[row][col] = 0;
		i++;
	}
	return (0);
}
