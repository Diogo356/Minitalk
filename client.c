/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 08:18:15 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/26 13:18:25 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_error(char *message)
{
    ft_putstr(message);
    exit(EXIT_FAILURE);
}

void validate_inputs(int argc, char **argv)
{
    int aux;

    if(argc != 3)
        print_error("Usage: ./client <PID> <Message>\n");
    aux = ft_strlen(argv[1]);
    if(aux > 7)
        print_error("PID Invalid!\n");
    
}

//void message_transmit(pid_t pid, char *message)
//{
    
//}

int main(int argc, char **argv)
{
   // pid_t pid;
    //char *message;

    validate_inputs(argc, argv);
    //pid = ft_atoi(argv[1]);
    //message = argv[2];
    //message_transmit(pid, message);
    return (0);
}
