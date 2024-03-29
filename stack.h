//
// Created by maxim on 24.09.19.
//

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

#define DEBUG 1

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef int stackElement_t;

struct Stack_t {
    stackElement_t *data;
    size_t size;
    size_t current_max_size;
#ifdef DEBUG
    const char *name;
#endif
};

void StackDump (Stack_t *stack, const char* file, int line, FILE *stream = stdout);
bool StackOk (Stack_t *stack);
bool StackLogging (Stack_t *stack, const char* file, int line, FILE *stream, bool silent=true);
Stack_t StackConstruct (size_t size=1);
bool ReallocateStack (Stack_t *stack, float size_multiplier);
bool StackPush (Stack_t *stack, stackElement_t value);
bool StackPop (Stack_t *stack, stackElement_t *value);
bool StackPeek (Stack_t *stack, stackElement_t *value);
bool StackDestruct (Stack_t *stack);