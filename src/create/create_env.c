/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 01:24:17 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:36:23 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_length(char **envp)
{
	int	i;

	i = 0;
	if (!*envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

int	create_my_env(t_data *data)
{
	char	**tab;

	tab = ft_calloc(4, sizeof(char *));
	tab[0] = ft_strndup("OLDPWD", 0);
	tab[1] = ft_strndup("PWD", 0);
	tab[2] = ft_strndup("SHLVL=1", 0);
	tab[3] = 0;
	if (ft_export(data, tab, 1))
		return (0);
	replace_pwd_my_env(data->envp);
	free_tab(tab);
	return (1);
}

int	create_env(t_data *data, char **envp)
{
	int		env_lgt;

	env_lgt = env_length(envp);
	if (env_lgt == 0)
	{
		if (!create_my_env(data))
			return (0);
		return (1);
	}
	ft_export(data, envp, 1);
	data->env_path = find_path_in_env(envp);
	return (1);
}
