#include <stddef.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)

int scalanative_unwind_get_context(void *context) {
    return 0;//unw_getcontext((unw_context_t*) context);
}

int scalanative_unwind_init_local(void *cursor, void *context) {
    return 0;//unw_init_local((unw_cursor_t*) cursor, (unw_context_t*) context);
}

int scalanative_unwind_step(void *cursor) {
    return 0;//unw_step((unw_cursor_t*) cursor);
}

int scalanative_unwind_get_proc_name(void *cursor, char *buffer,
       size_t length, void *offset) {
    return 0;/*unw_get_proc_name((unw_cursor_t*) cursor, buffer, length,
            (unw_word_t*) offset);*/
}

#else

#include <libunwind.h>

int scalanative_unwind_get_context(void *context) {
    return unw_getcontext((unw_context_t*) context);
}

int scalanative_unwind_init_local(void *cursor, void *context) {
    return unw_init_local((unw_cursor_t*) cursor, (unw_context_t*) context);
}

int scalanative_unwind_step(void *cursor) {
    return unw_step((unw_cursor_t*) cursor);
}

int scalanative_unwind_get_proc_name(void *cursor, char *buffer,
       size_t length, void *offset) {
    return unw_get_proc_name((unw_cursor_t*) cursor, buffer, length,
            (unw_word_t*) offset);
}

#endif