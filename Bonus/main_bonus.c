/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/06/04 23:27:01 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int total, char **args)
{
	t_data	data;

	if (total != 2)
	{
		printf("\033[30m\033[102m Usage \033[0m : ./cub3D [map path]\n");
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	parsing(args[1], &data);
	data.player = malloc(sizeof(t_player));
	if (!data.player)
		exit_game("Failed to allocate memory for player.", &data, -1, 1);
	ft_memset(data.player, 0, sizeof(t_player));
	data.rays = malloc(sizeof(t_ray));
	if (!data.rays)
		exit_game("Failed to allocate memory for rays.", &data, -1, 1);
	find_doors(&data);
	ft_memset(data.rays, 0, sizeof(t_ray));
	data.flag = 1;
	execute(&data);
	free_data(&data);
}
