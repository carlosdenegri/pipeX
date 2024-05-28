/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:30:13 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/21 23:52:30 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_p *p)
{
	// ft_printf(">>>Enter free.\n");
	if (p->arg_cmd)
		ft_free_array(p->arg_cmd);
	if (p->cmd)
		ft_free_array(p->cmd);
	if (p->all_paths)
		ft_free_array(p->all_paths);
	if (p->one_path)
		free(p->one_path);
	if (p->exec)
		free(p->exec);
	// ft_printf(">>>Exit free.\n");
}
void	ft_free_array(char **arr)
{
	int	i;

	// ft_printf(">>>Enter free_array.\n");
	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	// ft_printf(">>>Exit free_array.\n");
}
void	error(int type, t_p *p)
{
	// ft_printf(">>>Enter error.\n");
	if (type == 0)
		ft_putstr_fd("Not enough arguments.\n", 2);
	if (type == 1)
		ft_putstr_fd("Must have arguments.\n", 2);
	if (type == 2)
		ft_putstr_fd("pipe init failed.\n", 2);
	if (type == 3)
		ft_putstr_fd("process id failed.\n", 2);
	if (type == 4)
		ft_putstr_fd("Error on spliting the arguments.\n", 2);
	if (type == 5)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(p->arg_cmd[0], 2);
	}
	ft_free (p);
	// ft_printf(">>>Exit error.\n");
	exit (1);
}

void	init_struct(t_p *p)
{
	// ft_printf(">>>Enter init_struct.\n");
	p->arg_cmd = NULL;
	p->cmd = NULL;
	p->all_paths = NULL;
	p->exec = NULL;
	p->one_path = NULL;
	p->substr = NULL;
	// ft_printf(">>>Exit init_struct.\n");

}

bool	argument(int ac, char **av, t_p *p)
{
	int	i;

	// ft_printf(">>>Enter argument.\n");
	if (ac != 5)
	{
		p->error_type = 0;
		return (0);
	}
	i = 1;
	while (i < 4)
	{
		if (!ft_isprint(av[i][0]))
		{
			p->error_type = 1;
			return (0);
		}
		i++;
	}
	init_struct(p);
	// ft_printf(">>>Exit argument.\n");
	return (1);
}
