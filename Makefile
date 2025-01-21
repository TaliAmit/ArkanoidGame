CXX= g++
CC = $(CXX)
CXXFLAGS = -pedantic -Wall -Werror
CXXFLAGS += -g3
CXXFLAGS += -std=c++17
CPPFLAGS = -DDEBUG
CPPFLAGS = -I$(INCLUDES_DIR) -I$(MU_TEST_DIR)
INCLUDES_DIR = ../../../inc/arkanoid
SOURCES_DIR = ../../../src/arkanoid
MU_TEST_DIR = ../../../inc/
OBJECTS = $(SOURCES_DIR)/inputWindow.o $(SOURCES_DIR)/explodeBrick.o $(SOURCES_DIR)/strongBrick.o $(SOURCES_DIR)/absBrick.o $(SOURCES_DIR)/simpleBrick.o $(SOURCES_DIR)/resourceManager.o $(SOURCES_DIR)/button.o $(SOURCES_DIR)/ball.o $(SOURCES_DIR)/brick.o $(SOURCES_DIR)/simulationT.o $(SOURCES_DIR)/player.o $(SOURCES_DIR)/vaus.o $(SOURCES_DIR)/box.o $(SOURCES_DIR)/collision.o $(SOURCES_DIR)/designRes.o $(SOURCES_DIR)/game.o $(SOURCES_DIR)/musicPlayer.o $(SOURCES_DIR)/topScores.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET = utest
$(TARGET) : $(OBJECTS)
all: $(TARGET)
check : $(TARGET)
	@./$(TARGET) -v

clean:
	@$(RM) ./$(TARGET) $(SOURCES_DIR)/arkanoid.o $(SOURCES_DIR)/inputWindow.o $(SOURCES_DIR)/explodeBrick.o $(SOURCES_DIR)/strongBrick.o $(SOURCES_DIR)/absBrick.o $(SOURCES_DIR)/simpleBrick.o $(SOURCES_DIR)/resourceManager.o $(SOURCES_DIR)/button.o $(SOURCES_DIR)/ball.o $(SOURCES_DIR)/brick.o $(SOURCES_DIR)/vaus.o $(SOURCES_DIR)/simulationT.o $(SOURCES_DIR)/player.o $(SOURCES_DIR)/box.o $(SOURCES_DIR)/collision.o $(SOURCES_DIR)/designRes.o $(SOURCES_DIR)/game.o $(SOURCES_DIR)/topScores.o

.PHONY : all clean check