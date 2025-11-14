/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:06:27 by bsaldana          #+#    #+#             */
/*   Updated: 2025/11/06 10:06:29 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		file;
	pid_t	pid1;
	pid_t	pid2;

	check_argc(argc);
	if (pipe(fd) == -1)
		error();
	file = get_fd_file(argv[1], 1);
	pid1 = fork();
	if (pid1 == -1)
		error();
	else if (pid1 == 0)
		child(argv, envp, fd, file);
	close(file);
	file = get_fd_file(argv[4], 2);
	pid2 = fork();
	if (pid2 == -1)
		error();
	else if (pid2 == 0)
		child2(argv, envp, fd, file);
	close_fds(file, fd[0], fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
