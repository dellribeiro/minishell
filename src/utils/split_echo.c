/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 06:52:08 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:57:47 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	word_count_echo(char *str, char set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		if (!str[i])
			j++;
		while (str[i] && str[i] != set)
		{
			if (str[i + 1] == set || !str[i + 1])
				j++;
			i++;
		}
	}
	return (j);
}

int	char_count_pos(char *str, int i, char set)
{
	int	k;

	k = 0;
	while (str[i] && str[i] == set)
	{
		k++;
		i++;
	}
	while (str[i] && str[i] != set)
	{
		i++;
		k++;
	}
	return (k);
}

int	char_count_echo(char *str, char set, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j == pos)
			return (char_count_pos(str, i, set));
		while (str[i] && str[i] == set)
			i++;
		if (str[i + 1] == set || !str[i + 1])
			j++;
		i++;
	}
	return (0);
}

char	*put_word_pos(char *str, int i, char *tab, char set)
{
	int	k;

	k = 0;
	while (str[i] && str[i] == set)
	{
		tab[k] = str[i];
		k++;
		i++;
	}
	while (str[i] && str[i] != set)
	{
		tab[k] = str[i];
		k++;
		i++;
	}
	return (tab);
}

char	*putword_echo(char *str, char *tab, char set, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j == pos)
			return (put_word_pos(str, i, tab, set));
		while (str[i] && str[i] == set)
			i++;
		if (!str[i])
			j++;
		if (str[i + 1] == set || !str[i + 1])
			j++;
		i++;
	}
	i++;
	return (tab);
}
