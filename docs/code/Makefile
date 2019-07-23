# REMEMBER ":=" means early evaluation
# https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_6.html#SEC59
BINS := getenv
BINS += payload-eater
BINS += i_crash
BINS += exe
BINS += execve
BINS += bruteforce
BINS += fork

CPPFLAGS += -Wall


ifeq ($(ARCH),32)
	BINS += ptrace_on_segfault
	CPPFLAGS += -m32
	SUFFIX := _x86
else
	ARCH = 64
	CPPFLAGS += -m64
	SUFFIX := _amd64
endif

ptrace_on_segfault: LDLIBS += -lcapstone

ifeq ($(DEBUG),1)
	CPPFLAGS += -g
	SUFFIX := $(addsuffix _debug,$(SUFFIX))
endif

ifeq ($(SSP),1)
	CPPFLAGS += -fstack-protector-all -D_FORTIFY_SOURCE=2
	SUFFIX := $(addprefix _ssp, $(SUFFIX))
endif

ifeq ($(STATIC),1)
	SUFFIX := $(addprefix _static, $(SUFFIX))
	LDFLAGS += -static
endif

LDFLAGS  += -Wl,-z,now -Wl,-z,relro,-z,noexecstack



REAL_BINS := $(foreach bin, $(BINS), $(addsuffix $(SUFFIX), $(bin)))

all: $(BINS) $(REAL_BINS)

help:
	@echo CPPFLAGS = $(CPPFLAGS)
	@echo suffix = $(SUFFIX)
	@echo $(REAL_BINS)

clean:
	rm -f $(BINS) $(REAL_BINS)

bruteforce: CPPFLAGS += -std=c99

%$(SUFFIX):%
	make $<
	mv $< $@

total:
	make ARCH=32 SSP=1 all
	make ARCH=64 SSP=1 all
