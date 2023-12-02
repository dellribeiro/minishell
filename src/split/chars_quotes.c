/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:44:29 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:46:11 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_chars_double(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] && str[(*i)] != '"')
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[(*i)] == '"')
		return (chars += count_chars_double_inner(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}

int	count_chars_double_inner(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] != 39 && str[*i] != '"' && !is_end_of_string(str[*i]))
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[*i] == '"')
		return (chars += count_chars_double(str, i, count, n));
	else if (str[*i] == 39)
		return (chars += count_chars_single(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}

int	count_chars_single(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] && str[(*i)] != 39)
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[(*i)] == 39)
		return (chars += count_chars_single_inner(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}

int	count_chars_single_inner(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] != 39 && str[*i] != '"' && !is_end_of_string(str[*i]))
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[*i] == 39)
		return (chars += count_chars_single(str, i, count, n));
	else if (str[*i] == '"')
		return (chars += count_chars_double(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}
