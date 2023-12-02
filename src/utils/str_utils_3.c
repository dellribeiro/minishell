/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:52:57 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 04:08:42 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_substr(char *str, int n)
{
	int		i;
	char	*res;

	i = 0;
	if (!str || n <= 0)
		return (NULL);
	res = ft_calloc(n + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

int	is_sep(int a)
{
	if (!ft_isalpha(a) && ft_strchr("{}()", a))
		return (1);
	return (0);
}

char	*ft_strdup_until(char *str, int n)
{
	int		i;
	char	*dup;

	i = 0;
	if (n <= 0)
		return (NULL);
	dup = ft_calloc(n + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

void	fill(char *str, long long nb, int j)
{
	j--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (j >= 0 && str[j] != '-')
	{
		str[j] = (nb % 10) + 48;
		nb /= 10;
		j--;
	}
}

char	*ft_itoa(long long n)
{
	long long	nb;
	int			j;
	char		*str;

	nb = n;
	j = 0;
	if (n <= 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	str = ft_calloc(j + 1, sizeof(char));
	if (!str)
		return (NULL);
	fill(str, nb, j);
	return (str);
}
