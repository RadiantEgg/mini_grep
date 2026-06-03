CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

APP_BUILD = build/app
TEST_BUILD = build/test

APP_TARGET = build/mini_grep
TEST_TARGET = build/test_args

# 正式程序源文件
APP_SRC = \
	src/main.c \
	src/args.c \
	src/file.c \
	src/match.c \
	src/config.c \
	src/output.c 

# 测试程序自己的源文件
TEST_SRC = \
	test/test_args.c 

# 测试程序需要链接的公共模块
COMMON_SRC = \
	src/config.c \
	src/args.c

APP_OBJ = $(APP_SRC:src/%.c=$(APP_BUILD)/%.o)

COMMON_OBJ = $(COMMON_SRC:src/%.c=$(TEST_BUILD)/%.o)

TEST_OBJ = $(TEST_SRC:test/%.c=$(TEST_BUILD)/%.o)

all: $(APP_TARGET)

# 正式程序

$(APP_TARGET): $(APP_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(APP_BUILD)/%.o: src/%.c
	@mkdir -p $(APP_BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# 测试程序

test: $(TEST_TARGET)

$(TEST_TARGET): $(COMMON_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_BUILD)/%.o: src/%.c
	@mkdir -p $(TEST_BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BUILD)/%.o: test/%.c
	@mkdir -p $(TEST_BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# 运行

run: $(APP_TARGET)
	./$(APP_TARGET)

run_test: $(TEST_TARGET)
	./$(TEST_TARGET)

# 清理

clean: 
	rm -rf build

.PHONY: all test run run_test clean


