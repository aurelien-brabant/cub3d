/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:02:03 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 00:58:32 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "cub3d_types.h"

void	install_event_handlers(t_cub3d *c3d);
int		handle_keypress(int keysym, t_cub3d *c3d);
int		handle_keyrelease(int keysym, t_cub3d *c3d);

#endif /* EVENTS_H */
