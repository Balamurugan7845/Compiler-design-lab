@echo off
setlocal
cd /d "%~dp0"
title YACC Arithmetic Expression Parser
where wsl.exe >nul 2>&1
if errorlevel 1 (
 echo WSL is not installed. Installing WSL and Ubuntu...
 powershell -NoProfile -ExecutionPolicy Bypass -Command "wsl --install -d Ubuntu"
 echo If Windows asks you to restart, restart Windows, open Ubuntu once, finish setup, then run this file again.
 pause
 exit /b
)
echo Installing/checking Flex, Bison and GCC inside Ubuntu...
wsl bash -lc "sudo apt-get update && sudo DEBIAN_FRONTEND=noninteractive apt-get install -y flex bison gcc"
if errorlevel 1 (
 echo Installation failed. Open Ubuntu once and complete first-time setup, then run RUN.bat again.
 pause
 exit /b
)
echo Generating and compiling parser...
for /f "delims=" %%P in ('wsl wslpath -a "%~dp0"') do set "LINUXDIR=%%P"
wsl bash -lc "cd '%LINUXDIR%' && bison -dy parser.y && flex lexer.l && gcc y.tab.c lex.yy.c -o parser"
if errorlevel 1 (
 echo Build failed.
 pause
 exit /b
)
echo Starting parser...
wsl bash -lc "cd '%LINUXDIR%' && ./parser"
pause
