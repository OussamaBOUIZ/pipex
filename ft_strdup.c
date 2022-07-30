/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:10:55 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/21 17:44:20 by obouizga         ###   ########.fr       */
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
