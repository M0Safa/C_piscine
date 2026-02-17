/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:10:36 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/27 13:21:39 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_line(int *line, int cl, int cr)
{
	int	taller_l;
	int	taller_r;
	int	i;

	taller_l = line[0];
	taller_r = line[3];
	i = 1;
	while (i < 4)
	{
		if (line[i] > taller_l)
		{
			taller_l = line[i];
			cl--;
		}
		if (line[3 - i] > taller_r)
		{
			taller_r = line[3 - i];
			cr--;
		}
		i++;
	}
	if (cl == 1 && cr == 1)
		return (1);
	return (0);
}

int	check_table(int tab[][4], int cnd[][4])
{
	int	i;
	int	j;
	int	arr[4];

	i = 0;
	while (i < 4)
	{
		if (check_line(tab[i], cnd[2][i], cnd[3][i]) == 0)
			return (0);
		j = 0;
		while (j < 4)
		{
			arr[j] = tab[j][i];
			j++;
		}
		if (check_line(arr, cnd[0][i], cnd[1][i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
