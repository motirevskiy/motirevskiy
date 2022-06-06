/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:24:46 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/04 17:08:45 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	split_check_q(int i, char *s, char c)
{
	i++;
	while (s[i] != c && s[i])
		i++;
	if (s[i] != c)
		return (0);
	return (i);
}

int	split_len_word(int len, char const *s)
{
	int	l;

	l = 0;
	if (s[len] == '"')
	{
		while (s[++len] != '"')
			l++;
		if (s[len] != '"')
			return (0);
		if (s[len + 1] != ' ' && s[len + 1] != '\0')
			while (s[len] != ' ' && s[len] != '\0')
				len++;
		return (len);
	}
	else
	{
		while (s[++len] != '\'')
			l++;
		if (s[len] != '\'')
			return (0);
		if (s[len + 1] != ' ' && s[len + 1] != '\0')
			while (s[len] != ' ' && s[len] != '\0')
				len++;
		return (len);
	}
}
