#include "utilities.h"

void	ft_print(int fd, int bytes, char *file)
{
	int		sz;
	int		i;
	char	c;

	i = 0;
	sz = read(fd, &c, 1);
	while (sz != 0)
	{
		i++;
		sz = read(fd, &c, 1);
	}
	i -= bytes;
	fd = open(file, O_RDONLY);
	while (i != -1)
	{
		sz = read(fd, &c, 1);
		i--;
	}
	while (bytes != 0)
	{
		write(1, &c, 1);
		sz = read(fd, &c, 1);
		bytes--;
	}
}

int	main (int argc, char *argv[])
{
	int	i;
	int	fd;
	int	bytes;

	i = 2;
	bytes = ft_atoi(argv[2]);
	while (++i < (argc - 1))
	{
		if ((fd = open(argv[i], O_RDONLY)) < 0)
			ft_print_error(argv[0], argv[i]);
		else
		{
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
			ft_print(fd, bytes, argv[i]);
			ft_putstr("\n");
		}
	}
	if ((fd = open(argv[i], O_RDONLY)) < 0)
		ft_print_error(argv[0], argv[i]);
	else
	{
		ft_putstr("==> ");
		ft_putstr(argv[i]);
		ft_putstr(" <==\n");
		ft_print(fd, bytes, argv[i]);
	}
	close (fd);
	return (0);
}
