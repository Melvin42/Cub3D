#include "cub3d.h"

void	sort_sprites(t_all *all)
{
	int			i;
	int			j;
	t_sprite	swap;

	i = 0;
	while (i < all->numsprites)
	{
		j = i + 1;
		while (j < all->numsprites)
		{
			if (all->sprite[i].dist < all->sprite[j].dist)
			{
				swap = all->sprite[i];
				all->sprite[i] = all->sprite[j];
				all->sprite[j] = swap;
			}
			j++;
		}
		i++;
	}
}
