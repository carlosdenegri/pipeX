/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_gpath_genv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:37:45 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/21 23:52:04 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char *name, char **env)
{
	int	i;

	// ft_printf(">>>Enter get_env.\n");
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], name, 5) == env[i])
			return (env[i] + 5);
		i++;
	}
	// ft_printf(">>>Exit get_env.\n");
	return (NULL);
}

void	get_path(char *cmd, char **env, t_p *p)
{
	int	i;

	// ft_printf(">>>Enter get_path.\n");
	i = 0;
	if ((p->all_paths = ft_split(get_env("PATH=", env), ':')) == 0)
		error (4, p);
	if (!(p->cmd = ft_split(cmd, ' ')))
		error(4, p);
	while (p->all_paths[i])
	{
		p->one_path = ft_strjoin(p->all_paths[i], "/");
		p->exec = ft_strjoin(p->one_path, p->cmd[0]);
		free (p->one_path);
		if (access(p->exec, F_OK | X_OK) == 0)
		{
			ft_free_array(p->cmd);
			ft_free_array(p->all_paths);
			return ;
		}
		free(p->exec);
		i++;
	}
	ft_free_array(p->cmd);
	ft_free_array(p->all_paths);
	// ft_printf(">>>Exit get_path.\n");

}

void	execute(char *cmd, char **env, t_p *p)
{
	// ft_printf(">>>Enter execute.\n");
	if (!(p->arg_cmd = ft_split(cmd, ' ')))
		error(4, p);
	get_path(p->arg_cmd[0], env, p);
	if (execve(p->exec, p->arg_cmd, env) == -1)
		error(5, p);
	// ft_printf(">>>Exit execute.\n");
}

