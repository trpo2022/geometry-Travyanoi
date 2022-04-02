CFLAGS = -Wall -Werror -I src
СС = gcc 
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
APP_NAME = Geometry
LIB_NAME = LibGeometry

APP_PATH = $(SRC_DIR)/$(APP_NAME)
LIB_PATH = $(SRC_DIR)/$(LIB_NAME)
OBJ_APP_PATH = $(OBJ_DIR)/$(APP_NAME)
OBJ_LIB_PATH = $(OBJ_DIR)/$(LIB_NAME)

all: $(APP_NAME)

$(APP_NAME): $(APP_NAME).o $(LIB_NAME).o 
	$(CC) $(CFLAGS) -o bin/$(APP_NAME) $(OBJ_APP_PATH)/$(APP_NAME).o $(OBJ_LIB_PATH)/$(LIB_NAME).o -lm

$(APP_NAME).o:
	$(CC) -c $(CFLAGS) -o $(OBJ_APP_PATH)/$@ $(APP_PATH)/*.c

$(LIB_NAME).o:
	$(CC) -c $(CFLAGS) -o $(OBJ_LIB_PATH)/$@ $(LIB_PATH)/*.c

run:
	./$(BIN_DIR)/$(APP_NAME)

clean:
	rm $(BIN_DIR)/$(APP_NAME)