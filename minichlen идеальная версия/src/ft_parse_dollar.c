/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:29:52 by cgretche          #+#    #+#             */
/*   Updated: 2022/05/31 20:03:11 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	*ft_find(char *find)
{
	g_o.j = 0;
	g_o.env_res = NULL;
	g_o.i = -1;
	g_o.n = 0;
	while (g_o.env[++g_o.i] && g_o.j == 0)
	{
		if ((ft_strncmp(g_o.env[g_o.i], find, ft_strlen(find)) == 0)
			&& find[0] != '_')
		{
			g_o.env_res = malloc(sizeof(char *) * (ft_strlen(g_o.env[g_o.i])
						- ft_strlen(find)) - 1);
			while (g_o.env[g_o.i][g_o.n])
				if (g_o.env[g_o.i][g_o.n] != '=')
					g_o.n++;
			else
				while (g_o.env[g_o.i][++g_o.n])
						g_o.env_res[g_o.j++] = g_o.env[g_o.i][g_o.n];
			g_o.env_res[g_o.j] = '\0';
		}
	}
	if (!g_o.env_res || find[0] == '\0')
		return (ft_strjoin_mod("$", find, 2));
	free(find);
	return (g_o.env_res);
}

void	*parse_dollar(char *str)
{
	char	*to_find;

	g_o.i = 0;
	g_o.to_copy = NULL;
	g_o.n = 0;
	to_find = malloc(sizeof(char *) * ft_strlen(str) - 1);
	while (str[g_o.i] != '$')
		g_o.i++;
	if (str[0] != '$')
		g_o.to_copy = malloc(sizeof(char *) * g_o.i + 1);
	g_o.i = -1;
	while (str[++g_o.i])
	{
		if (str[g_o.i] == '$')
		{
			while (str[++g_o.i])
				to_find[g_o.n++] = str[g_o.i];
			to_find[g_o.n] = '\0';
			break ;
		}
		else
			g_o.to_copy[g_o.i] = str[g_o.i];
	}
	free (str);
	return (ft_strjoin_mod(g_o.to_copy, ft_find(to_find), 1));
}
