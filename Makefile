SOURCES_FILES = builtins/builtins.c \
                builtins/cd.c \
                builtins/echo.c \
                builtins/env.c \
                builtins/exit.c \
                builtins/export.c \
                builtins/pwd.c \
                builtins/unset.c \
                core/core.c \
                create/create_cmd.c \
                create/create_data.c \
                create/create_env.c \
                create/create_list.c \
                create/create_proc.c \
                create/fill_cmd.c \
                error/error.c \
                exec/exec.c \
                exec/heredoc.c \
                exec/pipe.c \
                exec/redirections.c \
                free/free_2.c \
                free/free.c \
                parsing/dollars.c \
                parsing/fill_dollar.c \
                parsing/parsing.c \
                parsing/quotes_utils.c \
                parsing/quotes.c \
                print/print_1.c \
                print/print_2.c \
                signal/signal_2.c \
                signal/signal.c \
                split/chars_quotes.c \
                split/chars_utils.c \
                split/split_index.c \
                split/split_utils.c \
                split/split.c \
                split/words_utils.c \
                utils/cmd_utils_two.c \
                utils/cmd_utils.c \
                utils/env_list_utils.c \
                utils/exec_utils.c \
                utils/export_utils.c \
                utils/heredoc_utils.c \
                utils/redirections_utils.c \
                utils/split_echo.c \
                utils/split_env.c \
                utils/split_normal.c \
                utils/str_utils_2.c \
                utils/str_utils_3.c \
                utils/str_utils.c \
                utils/utils.c\
				main.c

NAME 			=	minishell

CFLAGS			=	-Wall -Wextra -Werror
CC 				=	gcc
RM 				=	rm -f
RM_ALL 			=	rm -rf
VAL				=	valgrind --leak-check=full --show-leak-kinds=all

SOURCES_DIR 	=	src/
INCLUDES 		=	includes/
OBJ_DIR 		=	obj/

HEADER			=	$(INCLUDES)/minishell.h

SOURCES 		=	${addprefix ${SOURCES_DIR}, ${SOURCES_FILES}}

OBJS 			=	${addprefix ${OBJ_DIR}, ${SOURCES_FILES:.c=.o}}

all:		${NAME}

${NAME}:	${OBJS} $(HEADER)
			${CC} ${OBJS} -lreadline -o ${NAME}

${OBJ_DIR}%.o:	${SOURCES_DIR}%.c
				mkdir -p $(@D)
				${CC} ${CFLAGS} -c $< -o $@

clean:		
			${RM_ALL} ${OBJ_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

norm:
			norminette $(SOURCES_DIR) $(INCLUDES)

.PHONY:		all bonus clean fclean re run norm