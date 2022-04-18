/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sspina.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:46:35 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 19:01:25 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mnsh_builtin_sspina(t_minishell *mnsh, char **argv)
{
	(void) mnsh;
	(void) argv;
	printf("\033[0;32m\tTHE REAL\033[0m PIZZA \033[0;31mIS ITALIAN\033[0m\n\n");
	printf("                               ,(  `-.\n");
	printf("                             ,': `.   `.\n");
	printf("                           ,` *   `-.   \\\n");
	printf("                         ,'  ` :+  = `.  `.\n");
	printf("                       ,~  (o):  .,   `.  `.\n");
	printf("                     ,'  ; :   ,(__) x;`.  ;\n");
	printf("                   ,'  :'  itz  ;  ; ; _,-'\n");
	printf("                 .'O ; = _' C ; ;'_,_ ;\n");
	printf("               ,;  _;   ` : ;'_,-'   i'\n");
	printf("             ,` `;(_)  0 ; ','       :\n");
	printf("           .';6     ; ' ,-'~\n");
	printf("         ,' Q  ,& ;',-.'\n");
	printf("       ,( :` ; _,-'~  ;\n");
	printf("     ,~.`c _','\n");
	printf("   .';^_,-' ~\n");
	printf(" ,'_;-''\n");
	printf(",,~\n");
	return (0);
}
