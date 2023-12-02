/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:23:54 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:36:19 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*create_data(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->env_path = NULL;
	data->cmd = NULL;
	data->list = NULL;
	data->envp = NULL;
	data->proc = NULL;
	if (!create_env(data, envp))
		return (free_data(data), NULL);
	data->proc = create_proc();
	if (!data->proc)
		return (free_data(data), NULL);
	return (data);
}
