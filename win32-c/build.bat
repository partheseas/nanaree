@echo off
clang ".\src\main.c" -o ".\target\nanaree.exe" -z "/SUBSYSTEM:WINDOWS" "-Wl,user32.lib,kernel32.lib,shell32.lib"
