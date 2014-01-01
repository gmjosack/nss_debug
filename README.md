# nss_debug

## Description

I wrote this small module for the Name Service Switch to get a better idea
of how/and when various functions were being called. This was in prepartion
for a more complex NSS module I intended to write.

## Installation

```
make
sudo make install
```

## Configuration

Once the module is installed on your system you just have to modify the
/etc/nsswitch.conf for the appropriate service you want debug printing
on. The service name is debug and currently supports the passwd, group,
shadow, and hosts databases.

e.g. /etc/nsswitch.conf
```
passwd:         debug compat
group:          debug compat
shadow:         debug compat

hosts:          debug files dns
```
