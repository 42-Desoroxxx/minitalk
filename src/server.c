/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:02:15 by llage             #+#    #+#             */
/*   Updated: 2025/04/07 20:05:00 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static unsigned char	*g_message;

void	add_character_to_message(const unsigned char character)
{
	const unsigned char	character_str[2] = {character, '\0'};
	char				*new_message;

	if (g_message == NULL)
		g_message = s_alloc(sizeof(unsigned char), 1);
	new_message = ft_strjoin((char *) g_message, (char *) character_str);
	s_free((void **) &g_message);
	if (new_message == NULL)
	{
		ft_fprintf(STDERR_FILENO, "FATAL: Could not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	g_message = (unsigned char *) new_message;
}

void	print_message(void)
{
	if (g_message != NULL)
		ft_printf("%s", g_message);
	ft_printf("\n");
	s_free((void **) &g_message);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static unsigned int		bit_count = 0;

	(void) context;
	character |= (signal == SIGUSR2);
	bit_count++;
	if (bit_count < CHARACTER_SIZE)
		character <<= 1;
	else
	{
		if (character == '\0')
			print_message();
		else
			add_character_to_message(character);
		character = 0;
		bit_count = 0;
	}
	kill(info->si_pid, signal);
}

_Noreturn void	handle_murder(const int signal)
{
	ft_fprintf(STDERR_FILENO, "FATAL: Murdered by signal %d\n", signal);
	s_free((void **) &g_message);
	exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	signal_action;

	signal_action.sa_sigaction = &handle_signal;
	signal_action.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_action.sa_mask);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	signal(SIGINT, handle_murder);
	signal(SIGTERM, handle_murder);
	signal(SIGQUIT, handle_murder);
	ft_printf("Server started! PID: %d\n", getpid());
	while (true)
		pause();
}
