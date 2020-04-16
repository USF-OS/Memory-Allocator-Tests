#ifndef _VIRTUALHOST_H_
#define _VIRTUALHOST_H_

#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char *getlogin(void);
int getlogin_r(char *buf, size_t bufsize);
int gethostname(char *name, size_t namelen);

char *(*orig_getlogin)(void) = NULL;
int (*orig_gethostname)(char *, size_t) = NULL;

char fake_user[25];
char fake_hn[25];

void rand_str(char *str, size_t sz)
{
    for (int i = 0; i < sz - 1; ++i){
        str[i] = 'a' + rand() % 26;
    }
    str[sz - 1] = '\0';
}

char *getlogin(void)
{
    return fake_user;
}

int getlogin_r(char *buf, size_t bufsize)
{
    strncpy(buf, fake_hn, bufsize);
    return 0;
}

int gethostname(char *name, size_t namelen)
{
    strncpy(name, fake_hn, namelen);
    return 0;
}

void vhost_init(void)
{
    srand(time(NULL));
    char temp_str[5];
    rand_str(temp_str, 5);
    strcpy(fake_user, "user-");
    strcat(fake_user, temp_str);

    rand_str(temp_str, 5);
    strcpy(fake_hn, "host-");
    strcat(fake_hn, temp_str);

    orig_getlogin
        = (char *(*)(void)) dlsym(RTLD_NEXT, "getlogin");
    orig_gethostname
        = (int (*)(char *, size_t)) dlsym(RTLD_NEXT, "gethostname");
}

#endif
