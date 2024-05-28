/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:56:34 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/21 23:17:13 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_pipe
{
	int			error_type;
	char		**arg_cmd;
	char		**cmd;
	char		**all_paths;
	char		*exec;
	char		*one_path;
	char		*substr;
}	t_p;

//free_error_arg.c
bool	argument(int ac, char **av, t_p *p);
void	init_struct(t_p *p);
void	error(int type, t_p *p);
void	ft_free_array(char **arr);
void	ft_free(t_p *p);

//exec_gpath_genv.c
void	execute(char *cmd, char **env, t_p *p);
void	get_path(char *cmd, char **env, t_p *p);
char	*get_env(char *name, char **env);

//child_parent.c
void	child(char **av, int *fd, char **env, t_p *p);
void	parent(char **av, int *fd, char **env, t_p *p);


#endif
