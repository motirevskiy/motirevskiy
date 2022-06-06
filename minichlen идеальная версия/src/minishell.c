/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:09:22 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/04 19:31:26 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_loop(void)
{
	while (1)
	{
		ft_signals();
		g_o.g_l = readline("$ ");
		if (!g_o.g_l)
		{
			printf("exit\n");
			break ;
		}
		if (!g_o.g_l[0])
		{
			free(g_o.g_l);
			continue ;
		}
		add_history(g_o.g_l);
		g_o.error_f = ft_preparsing();
		ft_free_all();
		if (g_o.error_f < 0)
		{
			printf("!ERROR\nCODE IS: %d\n", g_o.error_f);
			free(g_o.g_l);
		}
		ft_init_struct(0);
	}
}

void	ft_init_struct(int flag)
{
	if (flag)
	{
		g_o.env = NULL;
		g_o.count_env = 0;
	}
	g_o.count_ex = 0;
	g_o.fd_in = -2;
	g_o.fd_out = -2;
	g_o.g_l = NULL;
	g_o.args = NULL;
	g_o.pipe[0] = -2;
	g_o.pipe[1] = -2;
	g_o.error_f = 1;
}

void	ft_init_env(char **env)
{
	int	i;

	i = -1;
	g_o.count_env = 0;
	while (env[g_o.count_env])
		g_o.count_env++;
	if (g_o.count_env)
	{
		g_o.env = malloc(sizeof(char *) * g_o.count_env + 1);
		while (++i < g_o.count_env)
			g_o.env[i] = ft_strdup(env[i]);
		g_o.env[i] = NULL;
	}
	else
	{
		write(1, "ENV Error!\n", 13);
		free(g_o.env);
		return ;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	ft_init_struct(1);
	ft_init_env(env);
	ft_shlvl();
	ft_loop();
	ft_free_mass(g_o.env);
	ft_free_all();
	return (0);
}
