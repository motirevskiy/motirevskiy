/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:39:06 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/04 17:05:35 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_count_word_mod(char *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			i = split_check_q(i, s, s[i]);
			if (i == 0)
				return (i);
			if (s[i + 1] == ' ' || s[i + 1] == '\0')
				count++;
		}
		else if ((s[i] == '>' && s[i + 1] == '>')
			|| (s[i] == '<' && s[i + 1] == '<'))
		{
			i++;
			count++;
		}
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
	}
	return (count);
}

void	*ft_mem_free_mod(char **str, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(str[i]);
	free(str);
	return (NULL);
}

int	ft_len_word_mod(char const *s, char c)
{
	int	len;
	int	l;

	l = -1;
	len = 0;
	while (s[len] != c && s[len] != '\0')
	{
		if (s[len] == '\'' || s[len] == '"')
			len = split_len_word(len, s);
		if ((s[len] == '>' && s[len + 1] == '>')
			|| (s[len] == '<' && s[len + 1] == '<'))
			return (2);
		len++;
	}
	return (len);
}

char	**ft_fill_word_mod(char const *s, char c, int count, char **str)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < count)
	{
		while (*s == c)
			s++;
		len = ft_len_word_mod(s, c);
		if (!len)
			return (NULL);
		str[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[i])
			return (ft_mem_free_mod(str, count));
		j = -1;
		while (++j < len)
		{
			str[i][j] = *s;
			s++;
		}
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split_mod(char *s, char c)
{
	char	**str;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_word_mod(s, c);
	if (!count)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (ft_mem_free_mod(str, count));
	str = ft_fill_word_mod(s, c, count, str);
	return (str);
}
