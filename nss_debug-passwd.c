#include <nss.h>
#include <pwd.h>
#include <stdio.h>


/**************************************
 * Functions for the passwd database. *
 **************************************/


// Called to open the passwd file
enum nss_status
_nss_debug_setpwent(int stayopen)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (stayopen: %d)\n", __FUNCTION__, stayopen);
    // Must be marked as success otherwise getpwent_r won't be called.
    return NSS_STATUS_SUCCESS;
}

// Called to close the passwd file
enum nss_status
_nss_debug_endpwent(void)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}

// Called to look up next entry in passwd file
enum nss_status
_nss_debug_getpwent_r(struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}

// Find a user account by uid
enum nss_status
_nss_debug_getpwuid_r(uid_t uid, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (uid: %d)\n", __FUNCTION__, uid);
    return NSS_STATUS_NOTFOUND;
}

// Find a user account by name
enum nss_status
_nss_debug_getpwnam_r(const char *name, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (name: %s)\n", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}
