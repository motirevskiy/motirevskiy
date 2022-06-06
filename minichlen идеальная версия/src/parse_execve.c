/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:37:18 by cgretche          #+#    #+#             */
/*   Updated: 2022/05/31 19:42:41 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_put_final_args(void)
{
	if (!g_o.final)
		g_o.final = ft_put_lst_new();
	else
		ft_lstadd_back(&g_o.final, ft_put_lst_new());
}

void	ft_parse_execve(void)
{
	int	i;

	i = 0;
	g_o.execve = malloc(sizeof(char *) * g_o.count_ex + 1);
	while (g_o.args && !g_o.args->pipe_flag)
	{
		if (g_o.args->str != NULL)
			g_o.execve[i++] = ft_strdup_mod(g_o.args->str, 1);
		free(g_o.args);
		g_o.args = g_o.args->next;
	}
	g_o.execve[i] = NULL;
	ft_put_final_args();
	if (g_o.args)
		ft_check_list();
}
