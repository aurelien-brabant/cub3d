/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:33:30 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 18:12:32 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "cub3d_types.h"

void		cub3d_init(t_cub3d *c3d);
void		cub3d_destroy(t_cub3d *c3d);
void		cub3d_shift_state(t_cub3d *c3d, bool (*checker)(t_cub3d *));
const char	*cub3d_state_to_str(t_state state);

#endif /* CUB3D_H */
