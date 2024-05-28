/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:39:40 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/21 23:53:07 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **av, int *fd, char **env, t_p *p)
{
	int	file_d;

	// ft_printf(">>>Enter child.\n");
	file_d = open(av[1], O_RDONLY, 0777);
	if (file_d == -1)
		error (3, p);
	dup2(file_d, 0);//0 get it from here
	dup2(fd[1], 1);//1 send it here
	close(fd[0]);
	execute(av[2], env, p);
	// ft_printf(">>>Exit child.\n");
}

void	parent(char **av, int *fd, char **env, t_p *p)
{
	int	file_d;

	// ft_printf(">>>Enter parent.\n");
	file_d = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_d == -1)
		error (3, p);
	dup2(file_d, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	execute(av[3], env, p);
	// printf(">>>Exit parent.\n");
}

