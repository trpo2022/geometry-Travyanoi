CFLAGS = -Wall -Werror -I src
СС = gcc 
SRC_DIR = src
APP_NAME = Geometry
LIB_NAME = LibGeometry

APP_PATH = $(SRC_DIR)/$(APP_NAME)
LIB_PATH = $(SRC_DIR)/$(LIB_NAME)

all: Geometry

Geometry:
	$(CC) $(CFLAGS) -o $(APP_NAME) $(APP_PATH)/*.c $(LIB_PATH)/*.c -lm

run:
	./$(APP_NAME)

clean:
	rm $(APP_NAME)