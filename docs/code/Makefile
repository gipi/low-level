# REMEMBER ":=" means early evaluation
# https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_6.html#SEC59

CPPFLAGS += -Wall

SUFFIX :=_

ifeq ($(ARCH),32)
	CPPFLAGS += -m32
	SUFFIX := $(addprefix _x86, $(SUFFIX))
else
	ARCH = 64
	CPPFLAGS += -m64
endif

ifeq ($(DEBUG),1)
CPPFLAGS += -g
endif

ifeq ($(SSP),1)
	CPPFLAGS += -fstack-protector-all -D_FORTIFY_SOURCE=2
	SUFFIX := $(addprefix _ssp, $(SUFFIX))
endif

LDFLAGS  += -Wl,-z,now -Wl,-z,relro,-z,noexecstack


all: $(BIN)

clean:
	rm -f $(BIN)

ptrace_on_segfault: LDFLAGS= -lcapstone


