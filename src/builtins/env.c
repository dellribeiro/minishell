/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:17:04 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:35:33 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_env(t_envp *envp, char **args)
{
	int	i;

	i = 0;
	if (args && args[0])
	{
		while (args[i] && is_same(args[i], "env"))
			i++;
		if (args[i])
			return (err_msg("env: '", args[i], "' No such file or directory",
					127));
	}
	while (envp)
	{
		if (envp->tab[1])
		{
			printf("%s=", envp->tab[0]);
			printf("%s\n", envp->tab[1]);
		}
		else if (ft_strcmp(envp->tab[0], "="))
			printf("%s=", envp->tab[0]);
		envp = envp->next;
	}
	return (0);
}
