/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:34:08 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 04:07:18 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	fill_dollar_tab(t_list *tmp)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	tmp->dollar = ft_calloc(count_dollars(tmp->str), sizeof(int));
	if (!tmp->dollar)
		return (0);
	while (tmp->str[i])
	{
		if (tmp->str[i] == '$')
			fill_dollar(tmp, &i, &index);
		else if (tmp->str[i] == '"')
			fill_dollar_dq(tmp, &i, &index);
		else if (tmp->str[i] == 39)
			fill_dollar_sq(tmp, &i, &index);
		i++;
	}
	return (1);
}

void	fill_dollar_dq(t_list *tmp, int *i, int *index)
{
	(*i)++;
	while (tmp->str[*i] != '"')
	{
		if (tmp->str[*i] == '$')
		{
			if (tmp->str[(*i) + 1] == '$')
			{
				tmp->dollar[(*index)++] = 0;
				(*i)++;
				tmp->dollar[(*index)++] = 0;
			}
			else if (!tmp->str[(*i) + 1] || tmp->str[(*i) + 1] == '"'
				|| !ft_isalpha(tmp->str[(*i) + 1]))
				tmp->dollar[(*index)++] = 0;
			else
				tmp->dollar[(*index)++] = 1;
			(*i)++;
		}
		else
			(*i)++;
	}
}

void	fill_dollar_sq(t_list *tmp, int *i, int *index)
{
	(*i)++;
	while (tmp->str[*i] != 39)
	{
		if (tmp->str[*i] == '$')
		{
			if (tmp->str[(*i) + 1] == '$')
			{
				tmp->dollar[(*index)++] = 0;
				(*i)++;
				tmp->dollar[(*index)++] = 0;
			}
			else
				tmp->dollar[(*index)++] = 0;
			(*i)++;
		}
		else
			(*i)++;
	}
}

void	fill_dollar(t_list *tmp, int *i, int *index)
{
	if (tmp->str[(*i) + 1] == '$')
	{
		tmp->dollar[*index] = 0;
		(*i)++;
		(*index)++;
		tmp->dollar[*index] = 0;
		(*index)++;
	}
	else if (!tmp->str[(*i) + 1])
		tmp->dollar[(*index)++] = 0;
	else
		tmp->dollar[(*index)++] = 1;
}
