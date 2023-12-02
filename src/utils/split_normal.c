/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 04:52:33 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 04:08:28 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h" 

int	word_count_normal(char *str, char set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	return (j);
}

int	char_count_normal(char *str, char set, int pos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (j == pos)
				k++;
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	return (k);
}

char	*putword_normal(char *str, char *tab, char set, int pos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (j == pos)
			{
				tab[k] = str[i];
				k++;
			}
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	tab[k] = '\0';
	return (tab);
}

void	free_tab_split(char **tab, int i)
{
	int	j;

	j = 0;
	while (i < j)
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

char	**ft_split_normal(char	*str, char set)
{
	int		i;
	char	**tab;

	i = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(word_count_normal(str, set) + 1, sizeof(char *));
	if (!tab)
		return (ft_free(tab), NULL);
	while (i < word_count_normal(str, set))
	{
		tab[i] = ft_calloc(char_count_normal(str, set, i) + 1, 1);
		if (!tab[i])
			return (free_tab_split(tab, i), NULL);
		tab[i] = putword_normal(str, tab[i], set, i);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
