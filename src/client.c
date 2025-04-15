/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:02:15 by llage             #+#    #+#             */
/*   Updated: 2025/04/07 20:03:34 by llage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static volatile sig_atomic_t	g_ack_received;

void	send_bit(const __pid_t server_pid, const int bit)
{
	g_ack_received = 0;
	if (bit == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	while (!g_ack_received)
		;
}

void	send_character(const __pid_t server_pid, const char character)
{
	int	i;

	i = CHARACTER_SIZE;
	while (i-- > 0)
		send_bit(server_pid, (character >> i) % 2);
}

void	send_message(const __pid_t server_pid, const char *message)
{
	while (*message)
		send_character(server_pid,*message++);
	send_character(server_pid, '\0');
}

void	handle_acknowledge(const int signal)
{
	(void)signal;
	g_ack_received = 1;
}

int	main(int argc, char *argv[])
{
	const char	*message;
	__pid_t		server_pid;

	if (argc != 3)
	{
		ft_fprintf(STDERR_FILENO, "FATAL: Usage: %s <server_pid> <message>\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid == -1 || server_pid == 0 || (kill(server_pid, 0) == -1))
	{
		ft_fprintf(STDERR_FILENO, "FATAL: Invalid PID provided: %d\n",
			server_pid);
		exit(EXIT_FAILURE);
	}
	message = argv[2];
	signal(SIGUSR1, handle_acknowledge);
	signal(SIGUSR2, handle_acknowledge);
	send_message(server_pid, message);
	ft_printf("Message sent! Server PID: %d, Message: %s\n", server_pid,
		message);
	exit(EXIT_SUCCESS);
}
