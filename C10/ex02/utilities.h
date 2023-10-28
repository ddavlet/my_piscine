#ifndef UTILITIES_H
#define UTILITIES_H

#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

int		ft_atoi(char *str);
void	ft_print_error (char *prog_name, char *file_name);
void	ft_putstr (char *text);

#endif
