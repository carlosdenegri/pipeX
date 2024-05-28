/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:00:29 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/21 23:53:22 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	process_id;
	t_p		p;

	// ft_printf(">>>Enter main.\n");
	if (!argument(ac, av, &p))
		error(p.error_type, &p);
	if (pipe(fd) == -1)
		error(2, &p);
	process_id = fork();
	if (process_id == -1)
		error(3, &p);
	if (!process_id)
		child(av, fd, env, &p);
	parent (av, fd, env, &p);
	// ft_printf(">>>Exit main.\n");
	return (EXIT_SUCCESS);
}

