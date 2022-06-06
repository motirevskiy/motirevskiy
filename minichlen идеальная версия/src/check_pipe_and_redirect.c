/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_and_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:10:50 by cgretche          #+#    #+#             */
/*   Updated: 2022/05/31 19:58:11 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_open_file(t_lst *tmp, int i)
{
	if (i == 1)
		g_o.fd_in = open(tmp->next->str, O_RDONLY, O_CLOEXEC);
	if (i == 2)
		g_o.fd_out = open(tmp->next->str, O_WRONLY
				| O_CLOEXEC | O_TRUNC | O_CREAT, 0644);
	if (i == 3)
		g_o.fd_out = open(tmp->next->str, O_WRONLY | O_CLOEXEC
				| O_APPEND | O_CREAT, 0644);
	if (i == 4)
		g_o.fd_in = -1;
	if (i == 5)
		ft_heredoc(tmp);
	if (g_o.fd_in == -1 || g_o.fd_out == -1)
		g_o.error_f = -113;
	free(tmp->str);
	free(tmp->next->str);
	tmp->str = NULL;
	tmp->next->str = NULL;
	return (tmp);
}

void	*ft_parse_redirect(t_lst *tmp)
{
	tmp->next = ft_check_q(tmp->next);
	if (ft_strncmp(tmp->next->str, "|", 1) == 0 && !tmp->next->meta_flag)
		g_o.error_f = -121;
	if (tmp->str[0] == '<' && !tmp->str[1])
		tmp = ft_open_file(tmp, 1);
	else if (tmp->str[0] == '>' && !tmp->str[1])
		tmp = ft_open_file(tmp, 2);
	else if (tmp->str[0] == '<' && tmp->str[1] == '>')
		tmp = ft_open_file(tmp, 2);
	else if (tmp->str[0] == '>' && tmp->str[1] == '>')
		tmp = ft_open_file(tmp, 3);
	else if (tmp->str[0] == '>' && tmp->str[1] == '<')
		tmp = ft_open_file(tmp, 4);
	else if (tmp->str[0] == '<' && tmp->str[1] == '<')
		tmp = ft_open_file(tmp, 5);
	return (tmp->next);
}
