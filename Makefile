CC=g++
CFLAGS=-c
SOURCES=main.cpp nrainhas.cpp cromossomo.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=nrainhas

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clear:
	rm $(EXEC) $(OBJECTS)