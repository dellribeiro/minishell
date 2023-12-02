/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:53:38 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 04:37:52 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_return_val;

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	g_return_val = 0;
	if (argc != 1)
		return (err_msg(INVALID_ARGUMENT, NULL, NULL, 1));
	handle_signal();
	get_prompt(envp);
	return (0);
}
