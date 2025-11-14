/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:12:10 by bsaldana          #+#    #+#             */
/*   Updated: 2025/11/13 12:12:10 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**search_in_envp(char *envp[])
{
	char	**split_paths;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	if (envp[i] == NULL)
		error();
	split_paths = ft_split(envp[i] + 5, ':');
	return (split_paths);
}

char	*search_path(char *envp[], char **comm)
{
	char	**split_paths;
	char	*good_path;
	char	*temp;
	int		i;

	split_paths = search_in_envp(envp);
	i = 0;
	while (split_paths[i] != NULL)
	{
		temp = ft_strjoin(split_paths[i], "/");
		good_path = ft_strjoin(temp, comm[0]);
		free(temp);
		if (access(good_path, X_OK) == 0)
		{
			free_split(split_paths);
			return (good_path);
		}
		i++;
		free(good_path);
	}
	free_split(split_paths);
	error_no_path(comm);
	return (NULL);
}

int	get_fd_file(char *file, int child)
{
	int	fd;

	fd = 0;
	if (child == 1)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			error_file(file);
	}
	else if (child == 2)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			error_file(file);
	}
	return (fd);
}

void	check_argc(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("wrong number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}
