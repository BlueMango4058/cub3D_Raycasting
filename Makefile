NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g


LIBFT_DIR = src/utils/libft
LIBFT_A = $(LIBFT_DIR)/libft.a


SRC_DIR = src


INIT_DIR = $(SRC_DIR)/init
INIT_FILES = init_resources.c
INIT_SRCS = $(addprefix $(INIT_DIR)/, $(INIT_FILES))


SETUP_DIR = $(SRC_DIR)/setup
SETUP_FILES = setup_resources.c
SETUP_SRCS = $(addprefix $(SETUP_DIR)/, $(SETUP_FILES))


SETUP_MLX_DIR = $(SETUP_DIR)/mlx
SETUP_MLX_FILES = setup_mlx.c \
				  setup_texture.c
SETUP_MLX_SRCS = $(addprefix $(SETUP_MLX_DIR)/, $(SETUP_MLX_FILES))


SETUP_DATA_DIR = $(SETUP_DIR)/data
SETUP_DATA_FILES = setup_data.c \
			  parse_data.c \
			  dispatch_line.c \
			  is_all_flags_set.c \
			  setup_map_data.c \
			  setup_config_data.c \
			  setup_config_color.c \
			  setup_config_texture.c \
			  final_validate.c \
			  static_validate.c \
			  padding_map_utils.c \
			  padding_map.c \
			  map_closure_validate.c \
			  validate_single_map.c \
			  setup_player_dir.c
SETUP_DATA_SRCS = $(addprefix $(SETUP_DATA_DIR)/, $(SETUP_DATA_FILES))


RENDER_DIR = $(SRC_DIR)/render
RENDER_FIELS = render_image.c \
			   dda.c \
			   projection.c \
			   put_pixel.c
RENDER_SRCS = $(addprefix $(RENDER_DIR)/, $(RENDER_FIELS))

DDA_UTILS_DIR = $(RENDER_DIR)/dda_utils
DDA_UTILS_FILES = dda_process.c \
				  set_delta_time.c \
				  set_step_and_side_time.c \
				  set_wall_depth.c \
				  set_raydir.c
DDA_UTILS_SRCS = $(addprefix $(DDA_UTILS_DIR)/, $(DDA_UTILS_FILES))

HOOK_DIR = $(SRC_DIR)/hook
HOOK_FILES = event.c \
			 step.c \
			 rotate.c \
			 movement.c
HOOK_SRCS = $(addprefix $(HOOK_DIR)/, $(HOOK_FILES))



UTILS_DIR = $(SRC_DIR)/utils
UTILS_FILES = av_validate.c \
			  error_print.c \
			  free.c \
			  ft_split_charset.c \
			  get_token_size.c \
			  print_data.c \
			  free_mlx.c \
			  is_player.c \
			  print_error_spot.c \
			  map_copy.c \
			  rgb_to_int.c
UTILS_SRCS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))

QUEUE_DIR = $(UTILS_DIR)/queue
QUEUE_FILES = queue.c
QUEUE_SRCS = $(addprefix $(QUEUE_DIR)/, $(QUEUE_FILES))


GNL_DIR = $(UTILS_DIR)/get_next_line
GNL_FILES = get_next_line_utils.c \
			get_next_line.c
GNL_SRCS = $(addprefix $(GNL_DIR)/, $(GNL_FILES))



MINILIBX_DIR = minilibx-linux
MLX_LIB = $(MINILIBX_DIR)/libmlx.a
MLX_LINK = -L$(MINILIBX_DIR) -lmlx -lXext -lX11
MATH_LINK = -lm



INCLUDES =  -I. \
			-I$(INIT_DIR) \
			-I$(SETUP_DIR) \
			-I$(SETUP_DATA_DIR) \
			-I$(SETUP_MLX_DIR) \
			-I$(UTILS_DIR) \
			-I$(GNL_DIR) \
			-I$(QUEUE_DIR) \
			-I$(RENDER_DIR) \
			-I$(DDA_UTILS_DIR) \
			-I$(HOOK_DIR)

SRCS = main.c \
	   $(INIT_SRCS) \
	   $(SETUP_SRCS) \
	   $(SETUP_DATA_SRCS) \
	   $(SETUP_MLX_SRCS) \
	   $(UTILS_SRCS) \
	   $(QUEUE_SRCS) \
	   $(GNL_SRCS) \
	   $(RENDER_SRCS) \
	   $(DDA_UTILS_SRCS) \
	   $(HOOK_SRCS)

OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A) $(MLX_LINK) $(MATH_LINK)

$(MLX_LIB):
	$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
