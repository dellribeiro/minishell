/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 01:25:58 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:40:58 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_list(t_list *list)
{
	int	i;

	i = 1;
	while (list)
	{
		printf("\n");
		printf("*****************  [%i]  *****************\n\n", i);
		printf("STRING : %s\n", list->str);
		printf("TYPE : %d\n", list->type);
		i++;
		list = list->next;
	}
	printf("\n");
}

void	print_struct_cmd(t_data *data)
{
	t_cmd	*tmp;
	int		i;

	tmp = data->cmd;
	i = 0;
	while (tmp)
	{
		printf("CMD : %s	I : %d\n", tmp->cmd, tmp->index);
		printf("// CMD->TOKEN //\n");
		print_tab(tmp->token);
		printf("// CMD->TYPE //\n");
		print_int_tab(data, tmp->type);
		printf("// CMD->OPT //\n");
		print_tab(tmp->opt);
		printf("\n");
		tmp = tmp->next;
		i++;
	}
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		printf("tab[%d] : %s\n", i, tab[i]);
		i++;
	}
}

void	print_pipe_fd(int **tab, int until)
{
	int	i;

	i = 0;
	if (!tab)
	{
		printf("tab NULL");
	}
	while (i < until)
	{
		printf("index : %d\n", i);
		printf("pipe_fd[%d][%d] : %d\n", i, 0, tab[i][0]);
		printf("pipe_fd[%d][%d] : %d\n", i, 1, tab[i][1]);
		printf("\n");
		i++;
	}
}
