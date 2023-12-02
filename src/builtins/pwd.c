/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:18:37 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:35:51 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	ft_putstr(buf);
	write(STDOUT_FILENO, "\n", 1);
	ft_free(buf);
	return (0);
}

void	replace_oldpwd_my_env(t_envp *envp)
{
	t_envp	*tmp;
	t_envp	*pwd_node;

	if (!envp)
		return ;
	tmp = search_node(envp, "OLDPWD");
	if (!tmp)
		return ;
	pwd_node = search_node(envp, "PWD");
	if (!pwd_node)
		return ;
	if (tmp->tab[1])
		ft_free(tmp->tab[1]);
	tmp->tab[1] = ft_strndup(pwd_node->tab[1], 0);
}

void	replace_pwd_my_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return ;
	replace_oldpwd_my_env(envp);
	tmp = search_node(envp, "PWD");
	if (!tmp)
		return ;
	if (tmp->tab[1])
		ft_free(tmp->tab[1]);
	tmp->tab[1] = getcwd(NULL, 0);
}
