# Compiler settings
CC = g++
CFLAGS = -Wall -std=c++17

# Executable names
STACK_TEST = stack_test
INFIX_TO_POSTFIX_TEST = infix_to_postfix_test
POSTFIX_EVAL_TEST = postfix_eval_test

# Build targets
all: $(STACK_TEST) $(INFIX_TO_POSTFIX_TEST) $(POSTFIX_EVAL_TEST)

# Stack tests
$(STACK_TEST): stack.hpp stack_test.cpp
	$(CC) $(CFLAGS) stack_test.cpp -o $(STACK_TEST)

# Infix to Postfix conversion tests
$(INFIX_TO_POSTFIX_TEST): stack.hpp infix_to_postfix.hpp infix_to_postfix.cpp infix_to_postfix_tests.cpp
	$(CC) $(CFLAGS) infix_to_postfix.cpp infix_to_postfix_tests.cpp -o $(INFIX_TO_POSTFIX_TEST)

# Postfix evaluation tests
$(POSTFIX_EVAL_TEST): stack.hpp postfix_eval.hpp postfix_eval.cpp postfix_eval_test.cpp
	$(CC) $(CFLAGS) postfix_eval.cpp postfix_eval_test.cpp -o $(POSTFIX_EVAL_TEST)

# Clean up
clean:
	rm -f $(STACK_TEST) $(INFIX_TO_POSTFIX_TEST) $(POSTFIX_EVAL_TEST)

# Run all tests
test: all
	./$(STACK_TEST)
	./$(INFIX_TO_POSTFIX_TEST)
	./$(POSTFIX_EVAL_TEST)
