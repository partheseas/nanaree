#pragma once
#define WIN32_LEAN_AND_MEAN
#include <SDKDDKVer.h>

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>

#define IDM_EXIT 100
#define IDM_TEST 200
#define IDM_ABOUT 300

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
