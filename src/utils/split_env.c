/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:52:19 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:58:00 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	first_sep(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

int	char_count_env(char *str, char set, int pos)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (pos == 0)
		return (first_sep(str, set));
	i = first_sep(str, set) + 1;
	while (i < (int)ft_strlen(str) && str[i])
	{
		i++;
		k++;
	}
	return (k);
}

void	ft_putword_env(char *str, char *tab, char set, int pos)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	if (pos == 0)
	{
		while (++i < first_sep(str, set))
		{
			tab[k] = str[i];
			k++;
		}
	}
	else
	{
		i = first_sep(str, set) + 1;
		while (i < (int)ft_strlen(str) && str[i])
		{
			tab[k] = str[i];
			i++;
			k++;
		}
	}
}

char	**ft_split_env(char	*str, char set)
{
	int		j;
	char	**tab;

	j = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(3, sizeof(char *));
	if (!tab)
		return (NULL);
	while (j < 2)
	{
		tab[j] = ft_calloc(char_count_env(str, set, j) + 1, 1);
		if (!tab[j])
			return (free_tab_split(tab, j), NULL);
		ft_putword_env(str, tab[j], set, j);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
