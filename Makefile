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

nss_debug_build_dir:
	[ -d $(BUILD) ] || mkdir $(BUILD)

nss_debug-passwd:
	$(CC) $(CFLAGS) -c nss_debug-passwd.c -o $(BUILD)/nss_debug-passwd.o

nss_debug-group:
	$(CC) $(CFLAGS) -c nss_debug-group.c -o $(BUILD)/nss_debug-group.o

nss_debug-shadow:
	$(CC) $(CFLAGS) -c nss_debug-shadow.c -o $(BUILD)/nss_debug-shadow.o

nss_debug-hosts:
	$(CC) $(CFLAGS) -c nss_debug-hosts.c -o $(BUILD)/nss_debug-hosts.o

nss_debug_services: nss_debug-passwd nss_debug-group nss_debug-shadow nss_debug-hosts

nss_debug: nss_debug_build_dir nss_debug_services
	$(CC) -shared $(LD_SONAME) -o $(BUILD)/$(LIBRARY) \
		$(BUILD)/nss_debug-passwd.o \
		$(BUILD)/nss_debug-group.o \
		$(BUILD)/nss_debug-shadow.o \
		$(BUILD)/nss_debug-hosts.o

clean:
	rm -rf $(BUILD)

install:
	[ -d $(LIBDIR) ] || install -d $(LIBDIR)
	install $(BUILD)/$(LIBRARY) $(LIBDIR)
	cd $(LIBDIR); for link in $(LINKS); do ln -sf $(LIBRARY) $$link ; done

.PHONY: clean install nss_debug_build_dir nss_debug
