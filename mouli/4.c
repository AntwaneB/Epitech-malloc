#include <stdlib.h>

int	main(void)
{
  char	*var = malloc(5);

  free(var);
  free(var);

  return (0);
}
