copy "%1lib\raylib-2.5.0-Win32-msvc15\lib\raylib.dll" "%2" /y
mkdir "%2res"
xcopy "%1res" "%2\res" /s /e /y
