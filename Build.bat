@echo off

call resources\premake\premake5.exe vs2019

IF %ERRORLEVEL% NEQ 0 (
  PAUSE
)