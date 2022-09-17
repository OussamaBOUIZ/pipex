/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:42:06 by obouizga          #+#    #+#             */
/*   Updated: 2022/09/17 15:44:29 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*copy;
	char	*s;

	a = 0;
	s = (char *)s1;
	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (0);
	while (s[a])
	{
		copy[a] = s[a];
		a++;
	}
	copy[a] = '\0';
	return (copy);
}


size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*ss;

	s = (unsigned char *)s1;
	ss = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s[i] && (s[i] == ss[i]) && i < n - 1)
		i++;
	return (s[i] - ss[i]);
}

char	*ft_strjoin_s(char *s1, char *s2)
{
	char	*nw_str;
	size_t	total_l;
	int		i;
	int		j;

	total_l = ft_strlen(s1) + ft_strlen(s2) + 1;
	nw_str = malloc(sizeof(char) * (total_l + 1));
	if (!nw_str)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			nw_str[i] = s1[i];
	nw_str[i] = '/';
	j = ft_strlen(s1) + 1;
	i = 0;
	if (s2)
		while (s2[i])
			nw_str[j++] = s2[i++];
	nw_str[j] = 0;
	return (nw_str);
}
