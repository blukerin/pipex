/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:10:28 by bsaldana          #+#    #+#             */
/*   Updated: 2025/11/13 12:10:29 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child2(char *argv[], char *envp[], int *fd, int outfile)
{
	char	*path;
	char	**comm;

	comm = ft_split(argv[3], ' ');
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	path = search_path(envp, comm);
	if (execve(path, comm, envp) == -1)
	{
		perror("execve");
		free(path);
		free_split(comm);
		exit(1);
	}
}

void	child(char *argv[], char *envp[], int *fd, int file)
{
	char	*path;
	char	**comm;

	comm = ft_split(argv[2], ' ');
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file);
	path = search_path(envp, comm);
	if (execve(path, comm, envp) == -1)
	{
		perror("execve");
		free(path);
		free_split(comm);
		exit(1);
	}
}
