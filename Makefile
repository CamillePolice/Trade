TARGET=trade

CC=g++
CFLAGS=-c -Wall -std=c++1y -O2 -static
LDFLAGS=

DEPS=$(wildcard *.hpp)
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean zip

zip:
	zip $(TARGET).zip *.hpp *.cpp 

clean:
	rm -rf $(OBJECTS) $(TARGET) $(TARGET).zip
