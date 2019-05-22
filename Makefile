SRC_DIR			= .

INC_DIR			= .

SRC			    = $(SRC_DIR)/Main.cpp			        \
			      $(SRC_DIR)/MyBot.cpp			        \
			      $(SRC_DIR)/Currency.cpp	    	    \
			      $(SRC_DIR)/Setting.cpp	    	    \
			      $(SRC_DIR)/Update.cpp	    		    \
			      $(SRC_DIR)/Action.cpp	    		    \
			      $(SRC_DIR)/Error.cpp    		    	\
			      $(SRC_DIR)/MarketValue.cpp
OBJ				= $(SRC:.cpp=.o)

CXXFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR)

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS		+= -g3
endif

NAME			= trade

all				:	$(OBJ)
					c++ $(OBJ) -o $(NAME) $(CXXFLAGS)

clean			:
					rm -f $(OBJ)

fclean			: clean
					rm -f $(NAME)

re				: fclean all

.PHONY			: all re clean fclean