/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:09:34 by bsaldana          #+#    #+#             */
/*   Updated: 2025/11/13 12:09:35 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	error_no_path(char **comm)
{
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(comm[0], 2);
	ft_putstr_fd("\n", 2);
	free_split(comm);
	exit(127);
}

void	error_file(char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	if (errno == ENOENT)
		exit (127);
	else if (errno == EACCES)
		exit (126);
	else
		exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free (split[i]);
		i++;
	}
	free (split);
}
