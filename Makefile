# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Dossiers
INCLUDE_DIR = include
LIBS_DIR = libs

# Fichiers sources et objets
SRCS = $(wildcard $(LIBS_DIR)/*.c)
OBJS = $(patsubst $(LIBS_DIR)/%.c, $(LIBS_DIR)/%.o, $(SRCS))

# Règle par défaut
all: main script

# Règle pour la cible principale
main: main.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour le fichier main
main.o: main.c
	$(CC) $(CFLAGS) -c $<

# Règle générique pour les fichiers sources
$(LIBS_DIR)/%.o: $(LIBS_DIR)/%.c $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

script: script.o
	gcc -o script script.o

# Nettoyage
clean:
	rm -f main script $(LIBS_DIR)/*.o *.o