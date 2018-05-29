#include "pl_internal.h"
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <stdio.h>

pl_monitor* pl_monitor_primary_get() 
{
	pl_monitor* m = malloc(sizeof* m);
	m.w = GetSystemMetrices(SM_CXSCREEN);
	m.h = GetSystemMetrices(SM_CYSCREEN);
	return m;
}


typedef struct pl_window 
{
	int   w,h;
	HWND  winhandle;
	HDC   windc;
	HGLRC wincontext;
}pl_window;

wchar_t* class_name = L"pl_window";
boolean is_class_registered=FALSE;

LRESULT CALLBACK WndProc(HWND, 
UINT, WPARAM, LPARAM);

static boolean pl_internal_window_class_register() 
{
	 static WNDCLASSW wnd;
	 wnd.style = 0;
	 wnd.lpfnWndProc = WndProc;
	 wnd.cbClsExtra = 0;
	 wnd.cbWndExtra = 0;
	 wnd.hInstance = NULL;
	 wnd.hIcon = LoadIcon(NULL,IDC_ICON);
	 wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	 wnd.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	 wnd.lpszClassName = class_name;
	 wnd.lpszMenuName = "";
	 
	 if (!RegisterClassW(&wnd)) {
	 	   return PL_FALSE;
	 }
	 
	 return PL_TRUE;
}

static void pl_internal_window_context_create(pl_window* win);

void pl_internal_window_system_init()
{
	 is_class_registered=pl_internal_window_class_register();
}

pl_window* pl_window_create(char* title, int w, int h) 
{
	if(!is_class_registered)return NULL;
	
	pl_window* win = malloc(sizeof* win);
	
	win->w = w;
	win->h = h;
	
	win->winhandle = CreateWindowW(class_name,(wchar_t*)title, WS_VISIBLE|WS_OVERLAPPEDWINDOW, 0,0,w,h,NULL,NULL,NULL,NULL);
	
	if(!win->winhandle) return NULL;
	
	return win;
}

