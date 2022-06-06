/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:26:13 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/31 20:00:37 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL)
		return (s2);
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

char	*ft_strjoin_mod(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL)
		return (s2);
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	if (n == 1)
	{
		free (s1);
		s1 = NULL;
	}
	free (s2);
	s2 = NULL;
	return (res);
}

char	*ft_sjoin(char *s1, char *s2, int flag, int flag2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	if (flag)
		free(s1);
	if (flag2)
		free(s2);
	return (res);
}
