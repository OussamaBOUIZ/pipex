/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:54:30 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/26 08:36:57 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
