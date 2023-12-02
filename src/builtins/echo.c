/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:16:37 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 04:06:36 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_option_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i] && str[i] == 'n')
		i++;
	if (!str[i] && i != 1)
		return (1);
	return (0);
}

int	echo_each_arg(char **args, int i)
{
	int		j;
	int		boule;
	char	**one;

	while (args[i])
	{
		boule = 0;
		one = ft_split_echo(args[i], ' ');
		if (!one)
			return (1);
		j = 0;
		while (one[j])
		{
			ft_putstr(one[j]);
			boule = 1;
			j++;
		}
		i++;
		free_tab(one);
		if (args[i] && boule == 1)
			write(STDOUT_FILENO, " ", 1);
	}
	return (0);
}

int	ft_echo(char **args)
{
	int		i;
	int		boule;

	boule = 0;
	i = 0;
	while (args[i] && is_option_n(args[i]))
	{
		i++;
		boule = 1;
	}
	g_return_val = echo_each_arg(args, i);
	if (boule == 0)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

char	**ft_split_echo(char	*str, char set)
{
	int		i;
	char	**tab;

	i = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(word_count_echo(str, set) + 1, sizeof(char *));
	if (!tab)
		return (ft_free(tab), NULL);
	while (i < word_count_echo(str, set))
	{
		tab[i] = ft_calloc(char_count_echo(str, set, i) + 1, 1);
		if (!tab[i])
			return (free_tab_split(tab, i), NULL);
		tab[i] = putword_echo(str, tab[i], set, i);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
