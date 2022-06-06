/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:40:50 by kferterb          #+#    #+#             */
/*   Updated: 2022/05/30 20:50:04 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = s1[j];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup_mod(char *s1, int n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = s1[j];
	str[j] = '\0';
	if (n == 1)
	{
		free (s1);
		s1 = NULL;
	}
	return (str);
}
