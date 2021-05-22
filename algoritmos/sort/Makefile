CC=gcc
NAME=sorting
CFLAGS= -Wall
SOURCE= .
SOURCESFILES = $(wildcard ${SOURCE}/*.c)
BINFOLDER = binaries
OBJFOLDER = objects
INCLUDES = ./
OBJS = $(patsubst %.c, $(OBJFOLDER)/%.o, $(notdir $(SOURCESFILES)))

all: createBin createObj main

main: $(OBJS)
	@ echo "Creating executable"
	$(CC) $(CFLAGS) $(OBJS) -o $(BINFOLDER)/$(NAME)

createBin:
	@ echo "Creating folder for binaries files"
	mkdir -p $(BINFOLDER)

createObj:
	@ echo "Creating folder for obj files"
	mkdir -p $(OBJFOLDER)

$(SOURCE)/$(OBJFOLDER)/%.o : $(SOURCE)/%.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -o $@
