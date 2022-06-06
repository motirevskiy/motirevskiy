/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:23:42 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/04 19:06:42 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_check_syntax(void)
{
	t_lst	*tmp;
	int		i;

	tmp = g_o.args;
	i = ft_lstsize(tmp);
	while (tmp && g_o.error_f != -121)
	{
		if (i == 1 && (!ft_strncmp(tmp->str, ">", 1)
				|| !ft_strncmp(tmp->str, "<", 1)
				|| !ft_strncmp(tmp->str, "|", 1)))
			g_o.error_f = -121;
		else if (!ft_strncmp(tmp->str, "|", 1)
			&& !ft_strncmp(tmp->next->str, "|", 1))
			g_o.error_f = -121;
		else if ((!ft_strncmp(tmp->str, ">", 1)
				|| !ft_strncmp(tmp->str, "<", 1))
			&& ((tmp->next->next && !ft_strncmp(tmp->next->next->str, "|", 1))
				|| !ft_strncmp(tmp->next->str, "|", 1)))
			g_o.error_f = -121;
		tmp = tmp->next;
	}
}
