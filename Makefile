CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wformat=2 -Wfloat-equal -Wundef -Wcast-align -Wstrict-overflow=5 -Wnull-dereference -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wunreachable-code -Werror -fsanitize=address,undefined -std=c11 -Iinclude -Itests
LDFLAGS = -lm

SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
LIB_DIR = lib

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

TEST_SRCS := $(shell find $(TEST_DIR) -name '*.c')
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/tests/%.o,$(TEST_SRCS))

STATIC_LIB = $(LIB_DIR)/lib.a
TEST_EXE = $(BUILD_DIR)/_test

.PHONY: all clean test lib

all: $(STATIC_LIB) $(TEST_EXE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(OBJS) | $(LIB_DIR)
	ar rcs $@ $(OBJS)
	@echo "Static library $(STATIC_LIB) created."

$(TEST_EXE): $(TEST_OBJS) $(OBJS) $(STATIC_LIB)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(OBJS) $(STATIC_LIB) -o $@ $(LDFLAGS)
	@echo "Test executable $(TEST_EXE) created."

test: $(TEST_EXE)
	@echo "Running tests with args: $(TEST_ARGS)..."
	./$(TEST_EXE) $(TEST_ARGS)

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)
	@echo "Cleaned build and lib directories."
