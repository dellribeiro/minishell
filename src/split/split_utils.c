/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:45:19 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:46:44 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_in_charset(char c)
{
	if (c == '<' || c == '>')
		return (1);
	if (c == '|')
		return (2);
	if (c == ' ' || c == '\t')
		return (3);
	if (c == '"' || c == 39)
		return (4);
	return (0);
}

int	is_end_of_string(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' ' || c == '\t' || c == '\0')
		return (1);
	return (0);
}
