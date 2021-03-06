/*
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef STRAWBERRY_SYSTEMCONFIG_H
#define STRAWBERRY_SYSTEMCONFIG_H

#include "Define.h"

#ifdef _PRE_WIN
    #include "revision_nr.h"
#else
    #include "revision_nr.h"
    #include "revision.h"
#endif

#define _PACKAGENAME "StrawberryCore "
#define _CODENAME "RAINY_DAY_IN_MAELSTROM"

#if STRAWBERRY_ENDIAN == STRAWBERRY_BIGENDIAN
# define _ENDIAN_STRING "big-endian"
#else
# define _ENDIAN_STRING "little-endian"
#endif

#ifdef _PRE_WIN
    #define _FULLVERSION _PACKAGENAME "\n" "Revision: " REVISION_NR
#endif

#ifndef _PRE_WIN
    #if PLATFORM == PLATFORM_WINDOWS
    # ifdef _WIN64
    #  define _FULLVERSION _PACKAGENAME "Rev: " _REVISION " " _BUILD_DIRECTIVE " Hash: " _HASH " (Win64," _ENDIAN_STRING ")"
    # else
    #  define _FULLVERSION _PACKAGENAME "Rev: " _REVISION " " _BUILD_DIRECTIVE " Hash: " _HASH " (Win32," _ENDIAN_STRING ")"
    # endif
    #else
    #  define _FULLVERSION _PACKAGENAME "Rev: " _REVISION " " _BUILD_DIRECTIVE " Hash: " _HASH " (Linux," _ENDIAN_STRING ")"
    #endif
#endif

#endif

