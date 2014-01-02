#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <nss.h>
#include <stdio.h>
#include <sys/socket.h>


enum nss_status
_nss_debug_sethostent(int stayopen)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (stayopen: %d)\n", __FUNCTION__, stayopen);
    return NSS_STATUS_SUCCESS;
}


enum nss_status
_nss_debug_endhostent(void)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


enum nss_status
_nss_debug_gethostent_r(struct hostent *host, char *buffer, size_t buflen, int *errnop, int *h_errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


enum nss_status
_nss_debug_gethostbyaddr_r(const void *addr, socklen_t addrlen, int af, struct hostent *host, char *buffer,
                           size_t buflen, int *errnop, int *h_errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (addr: %s)\n", __FUNCTION__,
            inet_ntoa(*(struct in_addr *)addr));
    return NSS_STATUS_NOTFOUND;
}


enum nss_status
_nss_debug_gethostbyname2_r(const char *name, int af, struct hostent *host, char *buffer, size_t buflen,
                            int *errnop, int *h_errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (name: %s)\n", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}


enum nss_status
_nss_debug_gethostbyname4_r(const char *name, struct gaih_addrtuple **pat, char *buffer, size_t buflen,
                            int *errnop, int *herrnop, int32_t *ttlp)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (name: %s)\n", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}


enum nss_status
_nss_debug_gethostbyname_r(const char *name, struct hostent *host, char *buffer, size_t buflen,
                           int *errnop, int *h_errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (name: %s)\n", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}
