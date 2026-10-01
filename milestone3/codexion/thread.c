#include "codexion.h"

void	*computation()
{
	printf("Computation\n");
	return (NULL);
}

int	main()
{
	pthread_t	thread1;

	pthread_create(&thread1, NULL, computation, NULL);
	pthread_join(thread1, NULL);
}

bool	create_threads(t_coders coder, int num_coders)
{
	int	i;

	i = 0;
	if (num_coders == 1)
	{
		if (pthread_create(&coder->coder_id, NULL, computation, coder[i] != 0))
	}
	else if (num_coders >= 1)
	{
		if (pthread_create(&coder->coder_id, NULL, computation, coder[i] != 0))
	}
	
}
