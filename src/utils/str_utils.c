/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:53:09 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:58:54 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcmp(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] && to_find[i] && str[i] == to_find[i])
		i++;
	if (!to_find[i])
		return (&str[i]);
	return (NULL);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dup;

	i = -1;
	if (!str)
		return (NULL);
	dup = ft_calloc(ft_strlen(str) + 1, 1);
	if (!dup)
		return (NULL);
	if (n == 0)
	{
		while (str[++i])
			dup[i] = str[i];
	}
	else
	{
		while (++i < n && str[i])
			dup[i] = str[i];
	}
	return (dup);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	write(STDOUT_FILENO, str, ft_strlen(str));
}

int	redir_type(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (PIPE);
	if (str[0] == '<' && str[1] && str[1] == '<')
		return (HERE);
	if (str[0] == '>' && str[1] && str[1] == '>')
		return (APPEND);
	if (str[0] == '<')
		return (IN);
	if (str[0] == '>')
		return (OUT);
	else
		return (WORD);
}
