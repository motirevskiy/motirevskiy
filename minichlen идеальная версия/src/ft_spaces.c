/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:52:55 by cgretche          #+#    #+#             */
/*   Updated: 2022/05/31 19:51:16 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_q(int i)
{
	if (g_o.g_l[i] == '"' || g_o.g_l[i] == '\'')
	{
		while (g_o.g_l[++i])
			if (g_o.g_l[i] == '"' || g_o.g_l[i] == '\'')
				break ;
		if (g_o.g_l[i] == '\0')
			return (-1);
	}
	return (i);
}

void	ft_paste_space(int i)
{
	int		len;
	char	*tmp;

	i++;
	len = strlen(g_o.g_l);
	if (i == len)
		return ;
	tmp = malloc(sizeof(char *) * len + 1);
	len = -1;
	g_o.n = 0;
	while (g_o.g_l[++len])
	{
		if (len != i || tmp[len] == ' ')
			tmp[g_o.n] = g_o.g_l[len];
		else if (len == i && tmp[len] != ' ')
		{
			tmp[len] = ' ';
			len--;
		}
		g_o.n++;
	}
	tmp[len + 1] = '\0';
	free (g_o.g_l);
	g_o.g_l = ft_strdup(tmp);
	free (tmp);
}

void	double_red(int i)
{
	if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<')
		&& (g_o.g_l[i - 1] != ' ' && g_o.g_l[i + 2] != ' '))
	{
		ft_paste_space(i - 1);
		ft_paste_space(i + 2);
	}
	else if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<')
		&& (g_o.g_l[i - 1] != ' ' && g_o.g_l[i + 2] == ' '))
		ft_paste_space(i - 1);
	else if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<')
		&& (g_o.g_l[i - 1] == ' ' && g_o.g_l[i + 2] != ' '))
		ft_paste_space(i + 1);
}

void	solo_red(int i)
{
	if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<' || g_o.g_l[i] == '|')
		&& (g_o.g_l[i - 1] != ' ' && g_o.g_l[i + 1] != ' '))
	{
		ft_paste_space(i - 1);
		ft_paste_space(i + 1);
	}
	else if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<' || g_o.g_l[i] == '|')
		&& (g_o.g_l[i - 1] != ' ' && g_o.g_l[i + 1] == ' '))
		ft_paste_space(i - 1);
	else if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<' || g_o.g_l[i] == '|')
		&& (g_o.g_l[i - 1] == ' ' && g_o.g_l[i + 1] != ' '))
		ft_paste_space(i);
}

int	check_spaces(void)
{
	int	i;

	i = -1;
	while (g_o.g_l[++i])
	{
		i = check_q(i);
		if (i == -1)
			return (-1);
		if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<')
			&& (((g_o.g_l[i - 1] != '>') && (g_o.g_l[i + 1] != '>'))
				&& ((g_o.g_l[i - 1] != '<') && (g_o.g_l[i + 1] != '<'))))
			solo_red(i);
		else if ((g_o.g_l[i] == '>' || g_o.g_l[i] == '<')
			&& ((g_o.g_l[i + 1] == '>') || (g_o.g_l[i + 1] == '<'))
			&& ((g_o.g_l[i - 1] != '>') || (g_o.g_l[i - 1] != '<')))
			double_red(i);
		else if (g_o.g_l[i] == '|')
			solo_red(i);
	}
	return (1);
}
