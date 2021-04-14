#include "cub3d.h"

int	check_error(int error)
{
	//free(all);  enlever tous les free et en laisser un seul ici!
	if (error == MALLOC_ERROR)
	{
		write(1, STR_MALLOC_ERROR, ft_strlen(STR_MALLOC_ERROR));
		return (-1);
	}
	else if (error == ARG_ERROR)
	{
		write(1, STR_ARG_ERROR, ft_strlen(STR_ARG_ERROR));
		return (-1);
	}
	else if (error == FD_ERROR)
	{
		write(1, STR_FD_ERROR, ft_strlen(STR_FD_ERROR));
		return (-1);
	}
	else if (error == PARS_ERROR)
	{
		write(1, STR_PARS_ERROR, ft_strlen(STR_PARS_ERROR)); 
		return (-1);
	}
	else if (error == MLX_ERROR)
	{
		write(1, STR_MLX_ERROR, ft_strlen(STR_MLX_ERROR)); 
		return (-1);
	}
	else if (error == FOLDER_ERROR)
	{
		write(1, STR_FOLDER_ERROR, ft_strlen(STR_FOLDER_ERROR)); 
		return (-1);
	}
	else if (error == MAP_ERROR)
	{
		write(1, STR_MAP_ERROR, ft_strlen(STR_MAP_ERROR)); 
		return (-1);
	}
	else if (error == RES_ERROR)
	{
		write(1, STR_RES_ERROR, ft_strlen(STR_RES_ERROR)); 
		return (-1);
	}
	else
		return (0);
}
