/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:45:08 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:46:36 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_index(char *str, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] && !is_in_charset(str[i]))
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			if (count == n)
				return (i);
			if (is_end_of_string(str[i + 1]))
				count++;
			i++;
		}
		if (get_index_exp(str, &count, &i, n))
			return (i);
	}
	return (0);
}

int	get_index_exp(char *str, int *count, int *i, int n)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
	if (is_in_charset(str[(*i)]))
	{
		if ((*count) == n)
			return (1);
		else if (str[(*i)] == '"')
			get_index_dq(str, count, i);
		else if (str[(*i)] == 39)
			get_index_sq(str, count, i);
		else if (str[(*i)] != '|' && str[(*i) + 1] == str[(*i)])
			(*i)++;
		else
		{
			(*count)++;
			(*i)++;
		}
	}
	return (0);
}

void	get_index_dq(char *str, int *count, int *i)
{
	(*i)++;
	while (str[*i] && str[(*i)] != '"')
		(*i)++;
	if (str[(*i)] == '"' && !is_end_of_string(str[(*i) + 1]))
	{
		(*i)++;
		while (str[*i] != '"' && str[*i] != 39 && !is_end_of_string(str[*i]))
			(*i)++;
		if (str[*i] == '"')
			get_index_dq(str, count, i);
		else if (str[*i] == 39)
			get_index_sq(str, count, i);
		else if (is_end_of_string(str[(*i)]))
			(*count)++;
	}
	else
	{
		(*i)++;
		(*count)++;
	}
}

void	get_index_sq(char *str, int *count, int *i)
{
	(*i)++;
	while (str[*i] && str[(*i)] != 39)
		(*i)++;
	if (str[(*i)] == 39 && !is_end_of_string(str[(*i) + 1]))
	{
		(*i)++;
		while (str[*i] != 39 && str[*i] != '"' && !is_end_of_string(str[*i]))
			(*i)++;
		if (str[*i] == 39)
			get_index_sq(str, count, i);
		else if (str[*i] == '"')
			get_index_dq(str, count, i);
		else if (is_end_of_string(str[(*i)]))
			(*count)++;
	}
	else
	{
		(*i)++;
		(*count)++;
	}
}
