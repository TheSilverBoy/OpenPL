#ifndef PL_H
#define PL_H

#include "pl_config.h"

#define main gel_main

#define PL_FALSE 0
#define PL_TRUE  1
typedef boolean unsigned char

typedef struct{
	int w, h;
}pl_monitor;

PL_API pl_monitor* pl_monitor_primary_get();

typedef struct pl_window pl_window;
typedef struct pl_events pl_events;

PL_API pl_window* pl_window_create(char* title, int w, int h);
PL_API pl_window* pl_window_create_m(char* title, pl_monitor* m);
PL_API void pl_window_destroy(pl_window* win);
PL_API int pl_window_width_get(pl_window* win);
PL_API int pl_window_height_get(pl_window*win);
PL_API boolean pl_window_events_poll(pl_window* win, pl_events* events);

#endif //PL_H