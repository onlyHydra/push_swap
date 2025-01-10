# Makefile for Push_swap project

# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# Directories
SRCDIR = src
INCDIR = header
LIBDIR = import
OBJDIR = obj

# Libraries
LIBFT = $(LIBDIR)/libft
FT_PRINTF = $(LIBDIR)/ft_printf

# Source files and object files
SRCS = $(shell find $(SRCDIR) -name '*.c')
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = push_swap

# Include directories
INCLUDES = -I$(INCDIR) -I$(LIBFT) -I$(FT_PRINTF)/$(INCDIR)

# Library files
LIBS = -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf

# Default target
all: $(TARGET)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build the target executable
$(TARGET): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

# Clean object files and libraries
clean:
	find $(SRCDIR) -name '*.o' -delete
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(FT_PRINTF) clean

# Clean object files, libraries, and executable
fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(FT_PRINTF) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re