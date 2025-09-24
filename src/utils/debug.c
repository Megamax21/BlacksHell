/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwerth <jwerth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:07:16 by jwerth            #+#    #+#             */
/*   Updated: 2025/09/24 10:06:51 by jwerth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp->next != token)
	{
		printf("Type : %d, [%s]\n", tmp->type, tmp->str);
		tmp = tmp->next;
	}
	printf("Type : %d, [%s]\n",  tmp->type, tmp->str);
}

void	print_tab(char **tab)
{
	int	i;

	if (!(tab))
	{
		printf("NULL");
		return ;
	}
	i = 0;
	printf("[");
	while (tab[i])
	{
		printf("%s", tab[i]);
		if (tab[i + 1])
			printf(", ");
		i++;
	}
	printf("]");
}

void	print_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp->next != cmd)
	{
		printf("Skip -> %d, infile -> %d, outfile -> %d, cmd : ",
		tmp->skip_cmd, tmp->infile, tmp->outfile);
		print_tab(tmp->cmd_param);
		printf("\n");
		tmp = tmp->next;
	}
	printf("Skip -> %d, infile -> %d, outfile -> %d, cmd : ", tmp->skip_cmd,
		 tmp->infile, tmp->outfile);
	print_tab(tmp->cmd_param);
	printf("\n");
}
