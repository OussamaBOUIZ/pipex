/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:50:17 by obouizga          #+#    #+#             */
/*   Updated: 2022/04/20 10:05:58 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_main_process(int *pids_arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		if (pids_arr[i++])
			return (1);
	return (0);
}
