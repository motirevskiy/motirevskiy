/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:09:23 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/04 18:53:11 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/libft.h"

typedef struct s_lst
{
	char			*str;
	int				pipe_flag;
	int				meta_flag;
	int				red_flag;
	int				fd_in;
	int				fd_out;
	char			**execve;
	struct s_lst	*next;
}	t_lst;

typedef struct s_start
{
	char	**execve;
	char	*history_log;
	char	*to_copy;
	char	*env_res;
	int		fd_in;
	int		fd_out;
	int		i;
	int		error_f;
	int		j;
	int		n;
	int		count_ex;
	int		pipe[2];
	char	**env;
	int		count_env;
	char	*g_l;
	char	**splited;
	t_lst	*args;
	t_lst	*final;
}	t_start;
t_start	g_o;

char	*ft_strdup(const char *s1);
void	ft_loop(void);
void	ft_init_struct(int flag);
char	**ft_split_mod(char *s, char c);
t_lst	*ft_lstnew(void *content);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
int		check_spaces(void);
int		ft_preparsing(void);
void	ft_free_all(void);
void	ft_check_list(void);
char	*ft_strdup_mod(char *s1, int n);
void	ft_free_mass(char **str);
char	*ft_strjoin_mod(char *s1, char *s2, int n);
void	*parse_dollar(char *str);
void	*ft_parse_redirect(t_lst *tmp);
void	*ft_open_file(t_lst *tmp, int i);
void	ft_parse_execve(void);
void	ft_put_final_args(void);
t_lst	*ft_put_lst_new(void);
void	ft_free_struct(t_lst *s);
t_lst	*ft_check_q(t_lst *tmp);
void	ft_init_env(char **env);
void	ft_heredoc(t_lst *o);
int		ft_strcmp(char *s1, char *s2);
char	*ft_sjoin(char *s1, char *s2, int flag, int flag2);
void	ft_signals(void);
void	ft_shlvl(void);
void	*ft_check_pipe(t_lst *tmp);
int		split_check_q(int i, char *s, char c);
int		split_len_word(int len, char const *s);
void	ft_check_syntax(void);
int		ft_lstsize(t_lst *lst);

#endif