TARGET_EXEC ?= febasyb

BIN_DIR := ./bin
BUILD_DIR := ./build
SOURCE_DIR := ./src

CC := g++
CPPFLAGS := -std=c++20 -Wall -pedantic -Wextra
LDFLAGS := -lpthread -pthread -L$(SDK_BIN) -L$(SDK_LIB) -L/usr/local/ssl/lib

SRCS := \
	src/main.cpp

TESTSRCS :=

INCLUDEDIRS := $(SDK_INC)
INCLUDEPARAMS := $(INCLUDEDIRS:%=-I%)

LIBS := mailio
LIBPARAMS := $(LIBS:%=-l%)

DEPS := ssl crypto boost_regex
DEPPARAMS := $(DEPS:%=-l%)

OBJS := $(SRCS:src/%.cpp=$(BUILD_DIR)/%.o)

TESTOBJS := $(TESTSRCS:src/%.cpp=$(BUILD_DIR)/%.o)

$(BIN_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(MKDIR_P) $(dir $@)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(DEPPARAMS) $(LIBPARAMS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CPPFLAGS) $(INCLUDEPARAMS) -c $< -o $@

dist: $(BIN_DIR)/$(TARGET_EXEC)
	@cp -v $< $(SDK_BIN)

test: ./bin/test
	@./bin/test

./bin/test: $(TESTOBJS)
		@$(MKDIR_P) $(dir $@)
		$(CC) $(TESTOBJS) -o $@ $(LDFLAGS) -lgtest

clean:
	@$(RM) -r $(BUILD_DIR)/*
	@$(RM) -r $(BIN_DIR)/*

MKDIR_P ?= mkdir -p
