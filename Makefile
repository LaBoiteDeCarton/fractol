NAME = fractol
S_DIR = srcs
H_DIR = include
SRCS_FILES = main.c \
				parse.c \
				fct.c \
				handle_errors.c \
				hooks.c \
				move.c \
				zoom.c \
				precision.c \
				color.c \
				palette.c \
				panel_color.c \
				utils_grille.c \
				complexe.c
SRCS = $(addprefix ${S_DIR}/, ${SRCS_FILES})
OBJS = ${SRCS:.c=.o}
FLAGS = -I ${H_DIR} #-Wall -Wextra -Werror 
MLX = lib/minilibx_opengl
LFT = lib/libft
LIBFLAGS = -Llib/libft -lft -Llib/minilibx_opengl -lmlx -framework OpenGL -framework AppKit


.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ${LFT}
	make -C ${MLX}
	gcc ${FLAGS} ${LIBFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	make clean -C ${LFT}
	make clean -C ${MLX}
	rm -f ${OBJS}

fclean: clean
	make fclean -C ${LFT}
	rm -f ${NAME}

re: fclean ${NAME}

bonus:
	${NAME}

.PHONY: all, clean, fclean, re, bonus