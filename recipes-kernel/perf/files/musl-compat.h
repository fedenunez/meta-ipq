#ifndef __PERF_MUSL_COMPAT_H
#define __PERF_MUSL_COMPAT_H

#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <syscall.h>
#include <sched.h>


/* Change XSI compliant version into GNU extension hackery */
#define strerror_r(err, buf, buflen) \
	(strerror_r(err, buf, buflen) ? NULL : buf)

#define _SC_LEVEL1_DCACHE_LINESIZE -1
#endif
