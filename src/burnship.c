/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:02:37 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/25 14:57:28 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


/*
c[R] = (pixel[X] - windowWidth) / (zoom * windowWidth);
c[I] = (pixel[Y] - windowHeight) / (zoom * windowHeight);
z[R] = c[R];
z[I] = c[I];
i = 0;
while (z[R] * z[R] + z[I] * z[I] < 4 && ++i < maxIterations)
{
  tmp = z[I];
  z[I] = fabs((double)(z[R] * z[I] + z[R] * z[I] + c[I]));
  z[R] = fabs((double)(z[R] * z[R] - tmp * tmp + c[R]));
}
if (i < maxIterations)
{
  // get pixel color
  // call to draw function
}
*/
