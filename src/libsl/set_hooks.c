/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:30:17 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/28 18:16:17 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

int	sl_hooks(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
		sl_exitm(0, NULL, app);
	if (sl_ismove(keycode))
		sl_move(app, keycode);
	printf("%u\n", app->ply.steps);
	return (0);
}
