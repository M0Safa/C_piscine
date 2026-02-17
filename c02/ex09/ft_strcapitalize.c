/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosafa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:47:32 by mosafa            #+#    #+#             */
/*   Updated: 2025/07/21 08:47:44 by mosafa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

void	ft_lower(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

void	ft_upper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	ft_check(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	if (c >= 'A' && c <= 'Z')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	check;

	i = 1;
	ft_upper(str);
	while (str[i])
	{
		check = ft_check(str[i - 1]);
		if (check == 1)
			ft_upper(str + i);
		else
			ft_lower(str + i);
		i++;
	}
	return (str);
}
