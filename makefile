PROJET = AirWatcher

# Compilateur
CC = g++

# Options de compilation
CFLAGS = -Wall -std=c++11

# Répertoires
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Fichiers source
SOURCES = $(wildcard $(SRCDIR)/**/*.cpp)
# Génération des noms des fichiers objets
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Création des répertoires nécessaires
MKDIR_P = mkdir -p

# Nom de l'exécutable
EXECUTABLE = $(BINDIR)/$(PROJET)

# Règle par défaut
all: directories $(EXECUTABLE)

# Création des répertoires nécessaires
directories:
	$(MKDIR_P) $(OBJDIR)
	$(MKDIR_P) $(BINDIR)
	rm -rf bin/dataset
	cp -r -n dataset bin/dataset

# Règle pour l'exécutable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Règle générique pour la compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(OBJDIR) $(BINDIR)
