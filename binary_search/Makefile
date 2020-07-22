CXX 		= g++
INCLUDES	= -I./include
CXXFLAGS	= -g -Wall $(INCLUDES)
LDFLAGS 	=
TARGET  	= binary_search

SRC_DIR		= .
OBJ_DIR		= $(SRC_DIR)/objs
FILES 		= binary_search
OBJS		= $(FILES:%=$(OBJ_DIR)/%.o)

# By default Make thinks the TARGET parameter is a file.
# It will only run the command if the TARGET is out of date.
# If you happen to have a file named clean and it is up to date,
#       Make will not run the command
# Tell Make the "clean" TARGET is PHONY so it doesn't associate
#       it with a file. It will always be run now.
.PHONY: all make_dirs clean

all: make_dirs $(TARGET)
make_dirs:
	mkdir -p $(OBJ_DIR)	
clean:
	rm $(OBJS) $(TARGET)
	rmdir $(OBJ_DIR)

# $@ -> target name
# $< -> first dependency
# $^ -> all dependencies space separated
# Smart enough to determine which C files are needed based on
# 	the dependencies ( $(OBJS) in this case )
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# This rule is automatically invoked by the rule above for all
# 	object files that match the TARGET section.
# It compiles .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ $(LDFLAGS)
