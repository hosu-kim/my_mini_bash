/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:29:59 by jakand            #+#    #+#             */
/*   Updated: 2025/06/07 16:22:14 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_args(t_command *start)
{
	int	i;

	i = 0;
	if (start->args)
	{
		i = 0;
		while (start->args[i])
		{
			free(start->args[i]);
			i++;
		}
		free(start->args);
	}
	if (start->args_types)
		free(start->args_types);
}

void	free_input_redir(t_redirection *redir)
{
	t_redirection *temp;
	
	while (redir)
	{
		temp = redir->next;
		free(redir->target);
		free(redir);
		redir = temp;
	}
}

void	free_output_redir(t_redirection *redir)
{
	t_redirection *temp;
	
	while (redir)
	{
		temp = redir->next;
		free(redir->target);
		free(redir);
		redir = temp;
	}
}

void    free_command(t_command *start)
{
	t_command       *cmd;
	t_redirection   *redir;

	if (!start)
		return ;
	cmd = start;
	while (start)
	{
		cmd = start->next;
		free_args(start);
		redir = start->input_redir;
		if (redir)
			free_input_redir(redir);
		redir = start->output_redir;
		if (redir)
			free_output_redir(redir);
		free(start);
		start = cmd;
	}
}
