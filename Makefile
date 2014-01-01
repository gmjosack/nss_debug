CC=gcc
CFLAGS=-Wall -Wstrict-prototypes -Werror -fPIC

LD_SONAME=-Wl,-soname,libnss_debug.so.2
LIBRARY=libnss_debug.so.2.0
LINKS=libnss_debug.so.2 libnss_debug.so

DESTDIR=/
PREFIX=$(DESTDIR)/usr
LIBDIR=$(PREFIX)/lib
BUILD=.libs

default: build
build: nss_debug

nss_debug:
	[ -d $(BUILD) ] || mkdir $(BUILD)
	$(CC) $(CFLAGS) -c nss_debug.c -o $(BUILD)/nss_debug.o
	$(CC) -shared $(LD_SONAME) -o $(BUILD)/$(LIBRARY) $(BUILD)/nss_debug.o

clean:
	rm -rf $(BUILD)

install:
	[ -d $(LIBDIR) ] || install -d $(LIBDIR)
	install $(BUILD)/$(LIBRARY) $(LIBDIR)
	cd $(LIBDIR); for link in $(LINKS); do ln -sf $(LIBRARY) $$link ; done

.PHONY: clean install
