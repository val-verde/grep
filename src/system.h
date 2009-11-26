/* Portability cruft.  Include after config.h and sys/types.h.
   Copyright 1996, 1998, 1999, 2000, 2007, 2009 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#undef PARAMS
#if defined (__STDC__) && __STDC__
# ifndef _PTR_T
# define _PTR_T
  typedef void * ptr_t;
# endif
# define PARAMS(x) x
#else
# ifndef _PTR_T
# define _PTR_T
  typedef char * ptr_t;
# endif
# define PARAMS(x) ()
#endif

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/* Some operating systems treat text and binary files differently.  */
#ifdef __BEOS__
# undef O_BINARY /* BeOS 5 has O_BINARY and O_TEXT, but they have no effect. */
#endif
#ifdef HAVE_DOS_FILE_CONTENTS
# include <io.h>
# ifdef HAVE_SETMODE
#  define SET_BINARY(fd)  setmode (fd, O_BINARY)
# else
#  define SET_BINARY(fd)  _setmode (fd, O_BINARY)
# endif
#endif

#ifdef HAVE_DOS_FILE_NAMES
# define IS_SLASH(c) ((c) == '/' || (c) == '\\')
# define FILESYSTEM_PREFIX_LEN(f) ((f)[0] && (f)[1] == ':' ? 2 : 0)
#endif

#ifndef IS_SLASH
# define IS_SLASH(c) ((c) == '/')
#endif

#ifndef FILESYSTEM_PREFIX_LEN
# define FILESYSTEM_PREFIX_LEN(f) 0
#endif

int isdir PARAMS ((char const *));

#ifdef EISDIR
# define is_EISDIR(e, f) ((e) == EISDIR)
#else
# define is_EISDIR(e, f) 0
#endif

#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

/* The extra casts work around common compiler bugs.  */
#define TYPE_SIGNED(t) (! ((t) 0 < (t) -1))
#define TYPE_MINIMUM(t) ((t) (TYPE_SIGNED (t) \
			      ? ~ (t) 0 << (sizeof (t) * CHAR_BIT - 1) \
			      : (t) 0))
#define TYPE_MAXIMUM(t) ((t) (~ (t) 0 - TYPE_MINIMUM (t)))

#ifndef isgraph
# define isgraph(C) (isprint(C) && !isspace(C))
#endif

#if defined (STDC_HEADERS) || (!defined (isascii) && !defined (HAVE_ISASCII))
# define IN_CTYPE_DOMAIN(c) 1
#else
# define IN_CTYPE_DOMAIN(c) isascii(c)
#endif

#define ISALPHA(C)	(IN_CTYPE_DOMAIN (C) && isalpha (C))
#define ISUPPER(C)	(IN_CTYPE_DOMAIN (C) && isupper (C))
#define ISLOWER(C)	(IN_CTYPE_DOMAIN (C) && islower (C))
#define ISDIGIT(C)	(IN_CTYPE_DOMAIN (C) && isdigit (C))
#define ISXDIGIT(C)	(IN_CTYPE_DOMAIN (C) && isxdigit (C))
#define ISSPACE(C)	(IN_CTYPE_DOMAIN (C) && isspace (C))
#define ISPUNCT(C)	(IN_CTYPE_DOMAIN (C) && ispunct (C))
#define ISALNUM(C)	(IN_CTYPE_DOMAIN (C) && isalnum (C))
#define ISPRINT(C)	(IN_CTYPE_DOMAIN (C) && isprint (C))
#define ISGRAPH(C)	(IN_CTYPE_DOMAIN (C) && isgraph (C))
#define ISCNTRL(C)	(IN_CTYPE_DOMAIN (C) && iscntrl (C))

#define TOLOWER(C) (ISUPPER(C) ? tolower(C) : (C))

#include <gettext.h>
#define N_(String) gettext_noop(String)
#define _(String) gettext(String)

#include <locale.h>

#ifndef initialize_main
#define initialize_main(argcp, argvp)
#endif
