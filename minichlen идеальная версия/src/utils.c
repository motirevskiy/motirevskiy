/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:59:13 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/04 19:06:57 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_check_pipe(t_lst *tmp)
{
	if (tmp->next && (ft_strncmp(tmp->next->str, ">", 1) == 0
			|| ft_strncmp(tmp->next->str, "<", 1) == 0))
		g_o.error_f = -121;
	if (!tmp->meta_flag)
		tmp->pipe_flag = 1;
	else
		tmp->pipe_flag = 1;
	free(tmp->str);
	tmp->str = NULL;
	return (tmp);
}

void	ft_free_struct(t_lst *s)
{
	t_lst	*tmp;

	tmp = s;
	while (tmp)
	{
		free(tmp->str);
		if (tmp->execve)
			ft_free_mass(tmp->execve);
		close(tmp->fd_in);
		close(tmp->fd_out);
		tmp->str = NULL;
		if (tmp)
			free(tmp);
		tmp = tmp->next;
	}
}

void	ft_free_mass(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] != NULL)
			free(str[i]);
	free(str);
	str = NULL;
}

void	ft_free_args(void)
{
	while (g_o.args)
	{
		free (g_o.args->str);
		g_o.args->str = NULL;
		free (g_o.args);
		g_o.args = g_o.args->next;
	}
}

void	ft_free_all(void)
{
	free (g_o.splited);
	g_o.splited = NULL;
	free (g_o.g_l);
	g_o.g_l = NULL;
	ft_free_args();
	if (g_o.final)
		ft_free_struct(g_o.final);
	g_o.final = NULL;
}
