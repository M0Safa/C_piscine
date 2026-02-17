/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:27:50 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/20 09:50:43 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	min;
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = j;
		min = *(tab + j);
		while (i < size)
		{
			if (*(tab + i) < min)
			{
				min = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = min;
			}
			i++;
		}
		j++;
	}
}
