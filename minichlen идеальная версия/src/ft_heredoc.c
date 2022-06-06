/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:06:02 by cgretche          #+#    #+#             */
/*   Updated: 2022/05/31 19:58:20 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_heredoc(t_lst *o)
{
	char	*tmp;
	char	*res;

	res = NULL;
	while (1)
	{
		tmp = readline("> ");
		if (ft_strcmp(tmp, o->next->str) == 0)
			break ;
		if (!tmp)
			return (free(res));
		if (ft_strlen(res))
			res = ft_sjoin(res, "\n", 1, 0);
		res = ft_sjoin(res, tmp, 1, 1);
	}
	res = ft_sjoin(res, "\n", 1, 0);
	pipe(g_o.pipe);
	write(g_o.pipe[1], res, ft_strlen(res));
	g_o.fd_in = g_o.pipe[0];
	close(g_o.pipe[1]);
	free(tmp);
	free(res);
	free(o->str);
	o->str = NULL;
}
