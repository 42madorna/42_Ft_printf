# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 17:46:31 by madorna-          #+#    #+#              #
#    Updated: 2020/10/04 23:28:55 by madorna-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_check_conv.c \
srcs/ft_check_flags.c \
ft_printf.c \
srcs/conv/ft_print_char.c \
srcs/conv/ft_print_nbr.c \
srcs/conv/ft_print_p.c \
srcs/conv/ft_print_string.c \
srcs/conv/ft_repeat.c \
srcs/conv/ft_print_pct.c \
srcs/conv/ft_print_u.c

OBJS	= $(SRCS:.c=.o)				#Transformar los archivos .c a .o y almacenarlos en la variable OBJS

NAME 	= libftprintf.a 		#Nombre de lo que quiero crear

NAME_LIBFT	= libft.a

PATH_LIBFT	= ./libft

LIBFT	= $(PATH_LIBFT)/$(NAME_LIBFT)

CC 		= gcc 			#Que tipo de compilación quiero usar

AR 		= ar 			#ar no es un compilador, es mas bien un empaquetador de archivos .o

CFLAGS 	= -Wall -Werror -Wextra #Flags para el compilador. -g es para el depurador

RM 		= rm -f 		#Variable para meterlo dentro de clean y borrar archivos concretos rm = borrar -f= para que no pida confirmación

#REGLAS (PROGRAMAS, EJECUTABLES, ETIQUETAS)

#Compila los archivos .o y les pone el nombre de cada función
.c.o:		#No tiene dependecias
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			
#-c genera el .o (pero no tiene nombre)
#$< coge el nombre de cada uno (de uno en uno) de los archivos .c (Algo específco de makefile)
#-o es lo que da el nombre del archivo de salida
#<:.c=.o El nombre que me haya dado antes me lo pones en .o

#Esta regla se activa cuando ejecute el nombre que pone en NAME
$(NAME):	$(OBJS) #Necesita que existan todos los .o y por eso le pongo como dependencias OBJS,
		$(AR) -r -c $(NAME) $(OBJS)
		$(AR) -s $(NAME)
#-r remplaza o añade los archivos específicos
#-c me hace NO ver los errores por pantalla
#$(NAME) como se va a guardar el archivo resultante
#$(OBJS) todos los archivos que quiero guardar en el $(NAME)
#La segunda línea solo actualiza el índice de archivos que hay dentro del .a (con el -s)
#Puedo añadir las líneas que quiera y se ejecutan en orden de arriba a abajo

#all es algo que no hace falta por sí misma, es una convención para que todos los makefile se ejecuten igual
all:	$(LIBFT) $(NAME)
		$(AR) -r -c -s $(NAME) $(PATH_LIBFT)/*.o
#lo que hacemos es generar la libft, y cogemos los .o y los incluimos para poder usarlos en la libftprintf
#all me exime conocer el nombre del archivo resultante

main:	CFLAGS += -g3 -fsanitize=address
main:	all
	$(CC) $(CFLAGS) main.c $(NAME) -o exec

debug:	CFLAGS += -g3 -fsanitize=address
debug:	re
	make -C $(PATH_LIBFT) debug
# -C lo que hace es que va a la ruta que le indico y ejecuta ahí la acción pedida

$(LIBFT):
	make -C $(PATH_LIBFT)

#Necesitamos una regla para borrar los OBJS (los .o)
clean:		#No necesita dependencias
		$(RM) $(OBJS) $(OBJS_BONUS)
		make -C $(PATH_LIBFT) clean

#En fclean quiero que además de borrar los .o tambien borre la biblioteca .a
fclean:		clean
		$(RM) $(NAME) exec
		make -C $(PATH_LIBFT) fclean
#En este caso necesito a clean como dependencia para que se ejecute primero
#$(NAME) es para que borre la bliblioteca .a que hemos creado

#Si necesitamos borrar todo y crear una nueva biblioteca pues tengo este comando
re:			fclean all
#En este caso no hace nada nuevo y por eso no tengo instrucciones, solo dependencias

#Evita buscar el nombre de la regla como si fuera un archivo
.PHONY: all clean fclean re debug
#Aquí solo meto las reglas que no generan código. Por si mismo no hacen nada sino que mandan hacer
