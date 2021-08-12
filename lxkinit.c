#include <stdint.h>
#include <lua5.4/lua.h>
#include <lua5.4/lauxlib.h>
#include <lua5.4/lualib.h>

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

lua_State* create_state()
{
    return luaL_newstate();
}

void invoke_part(lua_State* L, char* file)
{
    luaL_dofile(L, file);
}
