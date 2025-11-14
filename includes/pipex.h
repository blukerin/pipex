/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:06:52 by bsaldana          #+#    #+#             */
/*   Updated: 2025/11/06 10:07:05 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

void	error(void);
void	error_no_path(char **comm);
void	free_split(char **split);
void	check_argc(int argc);
void	child(char *argv[], char *envp[], int *fd, int file);
void	child2(char *argv[], char *envp[], int *fd, int outfile);
char	*search_path(char *envp[], char **comm);
void	error_file(char *file);
int		get_fd_file(char *file, int child);
void	close_fds(int file, int fd_0, int fd_1);

#endif