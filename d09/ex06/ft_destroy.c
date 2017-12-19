#include <stdlib.h>
#include "ft_ultimator.h"

void ft_destroy(char ***factory)
{
	free(**factory);
	free(*factory);
	free(factory);
}