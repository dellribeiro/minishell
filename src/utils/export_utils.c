/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:51:30 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:56:53 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_concat(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' && !str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	concat_inexist(t_data *data, char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] == '=')
		{
			res = ignore_charset(str, "+", 0);
			add_last_env(data, res);
			if (res)
				ft_free(res);
			return (1);
		}
		i++;
	}
	return (0);
}

int	concat(t_envp *node, char **tab)
{
	char	*tab_1;

	if (is_concat(tab[0]))
	{
		tab_1 = ft_strndup(node->tab[1], 0);
		if (!tab_1)
			return (0);
		ft_free(node->tab[1]);
		tab[1] = ignore_charset(tab[1], "\'\"", 1);
		node->tab[1] = ft_strjoin(tab_1, tab[1]);
		ft_free(tab_1);
		if (!node->tab[1])
			return (0);
		return (1);
	}
	return (0);
}

int	is_valid_name(char *str)
{
	int	i;

	i = 0;
	if (str && str[0] >= '0' && str[0] <= '9')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha((int)str[i]))
			if (str[i] != '=' && (str[i] != '+' || str[i + 1] != '='))
				return (0);
		i++;
	}
	return (1);
}

int	replace_value(t_envp *node, char *value)
{
	if (!value)
		return (1);
	ft_free(node->tab[1]);
	node->tab[1] = ft_strndup(value, 0);
	if (!node->tab[1])
		return (0);
	return (1);
}
