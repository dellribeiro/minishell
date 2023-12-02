/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:16:03 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:35:26 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_a_dir(char *str)
{
	if (access(str, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

int	check_cd(char **args, int m)
{
	int	i;

	i = 0;
	if (!args[0])
	{
		if (m == 1)
			err_msg("minishell: no relative or absolute path", 0, 0, 1);
		return (1);
	}
	while (args[i])
		i++;
	if (i > 1)
	{
		if (m == 1)
			err_msg("minishell: too many arguments", NULL, NULL, 1);
		return (1);
	}
	if (!is_a_dir(args[0]))
	{
		if (m == 1)
			err_msg("minishell: ", args[0], ": is not a directory", 1);
		return (1);
	}
	return (0);
}

int	ft_cd(t_data *data, char **args, int m)
{
	g_return_val = check_cd(args, m);
	if (g_return_val)
		return (1);
	chdir(args[0]);
	replace_pwd_my_env(data->envp);
	return (0);
}
