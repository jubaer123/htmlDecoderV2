# compile with gcc, change this to clang if you prefer
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -Wall -Wextra -std=c99

nextTag:  helper.o nextTagTest.o
	$(COMPILER) $(C_FLAGS) -o nextTag nextTagTest.o helper.o
htags: helper.o main.o
	$(COMPILER) $(C_FLAGS) -o htags main.o helper.o

helper.o : helper.c
	$(COMPILER) $(C_FLAGS) -c helper.c
nextTagTest.o: nextTagTest.c
	$(COMPILER) $(C_FLAGS) -c nextTagTest.c

main.o: main.c
	$(COMPILER) $(C_FLAGS) -c main.c
