CXX 		= g++
CXXFLAGS	= -g -Wall
LDFLAGS 	=
OBJS 		= main.o loggable.o sorter.o \
			  bubble_sorter.o selection_sorter.o insertion_sorter.o merge_sorter.o
TARGET 		= sort_app
DEPS 		=

# $@ -> target name
# $< -> first dependency
# $^ -> all dependencies space separated
# Smart enough to determine which C files are needed based on
# 	the dependencies ( $(OBJS) in this case )
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm $(OBJS) $(TARGET)