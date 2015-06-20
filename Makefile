BIN := ptrace_on_segfault
BIN += getenv
BIN += payload-eater

CPPFLAGS += -Wall -m32

all: $(BIN)

clean:
	rm -f $(BIN)

ptrace_on_segfault: LDFLAGS= -lcapstone


