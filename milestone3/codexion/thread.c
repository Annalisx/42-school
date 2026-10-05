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

bool	create_threads(t_coders *list, t_info info, int num_coders)
{
	int	i;
	t_coders *curr;

	curr = list;
	i = 0;
	if (num_coders == 1)
	{
		if (pthread_create(&curr->thread_id, NULL, computation, NULL))
			return (false);
	}
	else if (num_coders >= 1)
	{
		if (pthread_create(&list->thread_id, NULL, computation, NULL))
			return (false);
	}
	
}
