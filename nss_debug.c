#include <nss.h>
#include <stdio.h>
#include <pwd.h>
#include <shadow.h>
#include <grp.h>


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


/*************************************
 * Functions for the group database. *
 *************************************/

// Called to open the group file
enum nss_status
_nss_debug_setgrent(int stayopen)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (stayopen: %d)\n", __FUNCTION__, stayopen);
    // Must be marked as success otherwise getpwent_r won't be called.
    return NSS_STATUS_SUCCESS;
}

// Called to close the group file
enum nss_status
_nss_debug_endgrent(void)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}

// Called to look up next entry in group file
enum nss_status
_nss_debug_getgrent_r(struct group *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}

// Find a group by gid
enum nss_status
_nss_debug_getgrgid_r(gid_t gid, struct group *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (gid: %d)\n", __FUNCTION__, gid);
    return NSS_STATUS_NOTFOUND;
}

// Find a group by name
enum nss_status
_nss_debug_getgrnam_r(const char *name, struct group *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (name: %s)\n", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}


/*************************************
 * Functions for the shadow database. *
 *************************************/

// Called to open the shadow file
enum nss_status
_nss_debug_setspent(int stayopen)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (stayopen: %d)\n", __FUNCTION__, stayopen);
    // Must be marked as success otherwise getpwent_r won't be called.
    return NSS_STATUS_SUCCESS;
}


// Called to close the shadow file
enum nss_status
_nss_debug_endspent(void)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


// Called to look up next entry in the shadow file
enum nss_status
_nss_debug_getspent_r(struct spwd *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s\n", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


// Find a shadow entry by name
enum nss_status
_nss_debug_getspnam_r(const char *name, struct spwd *result, char *buffer, size_t buflen, int *errnop)
{
    fprintf(stderr, "NSS DEBUG: Called %s with args (name: %s)\n", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}
