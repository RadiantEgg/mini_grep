CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

APP_BUILD = build/app
TEST_BUILD = build/test

APP_TARGET = build/mini_grep

TEST_ARGS = build/test_args
TEST_MATCH = build/test_match


# 正式程序源文件
APP_SRC = \
	src/main.c \
	src/args.c \
	src/file.c \
	src/match.c \
	src/config.c \
	src/output.c \
	src/input.c

APP_OBJ = $(APP_SRC)


# 默认目标
all: $(APP_TARGET)


$(APP_TARGET): $(APP_SRC)
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@


# 测试: args
$(TEST_ARGS): test/test_args.c src/args.c src/config.c
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@


# 测试: match
$(TEST_MATCH): test/test_match.c src/match.c src/config.c
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@
	

# 测试总入口
test: $(TEST_ARGS) $(TEST_MATCH)


# 运行
run: $(APP_TARGET)
	./$(APP_TARGET)

run_test_args: $(TEST_ARGS)
	./$(TEST_ARGS)

run_test_match: $(TEST_MATCH)
	./$(TEST_MATCH)


# 清理
clean:
	rm -rf build

.PHONY: all test run run_test_args run_test_match clean
