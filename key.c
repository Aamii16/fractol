#include "fractol.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Hello from key! %d\n", keycode);
	return (0);
}

//int	main(void)
//{
//	t_vars	vars;

//	vars.mlx = mlx_init();
//	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//	mlx_key(vars.win, key, &vars);
//	mlx_loop(vars.mlx);
//}