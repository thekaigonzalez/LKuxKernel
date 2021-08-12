#include <lua5.4/lua.h>
#include <lua5.4/lauxlib.h>
#include <lua5.4/lualib.h>


// std headers
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* luaopen_lkuxFS */


#if defined(__STDC__)

# define PREDEF_STANDARD_C_1989

# if defined(__STDC_VERSION__)

#  define PREDEF_STANDARD_C_1990

#  if (__STDC_VERSION__ >= 199409L)
#   define PREDEF_STANDARD_C_1994
#  endif

#  if (__STDC_VERSION__ >= 199901L)
#   define PREDEF_STANDARD_C_1999
#  endif

#  if (__STDC_VERSION__ >= 201710L)
#   define PREDEF_STANDARD_C_2018
#  endif

# endif

#endif


#if _MSC_VER && !__INTEL_COMPILER
#error "error: glibc not found"
#endif

int hazaccess(lua_State* L)
{
    lua_pushboolean(L, access(luaL_checkstring(L, 1), F_OK));
    return 1;
}

int greadline(lua_State* L)
{
    char* b=readline(luaL_checkstring(L, 1));

    lua_pushstring(L, b);

    add_history(b);

    return 1;
}

int luaopen_lkuxFS(lua_State* L)
 {
    lua_register(L, "has_access", hazaccess);
    lua_register(L, "readline", greadline);
    return 1;
 }