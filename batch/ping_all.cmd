@echo off
setlocal

set "subnet=192.168.1"

for /L %%i in (1,1,254) do (
    echo Pinging %subnet%.%%i...
    for /f "tokens=3 delims=: " %%j in ('ping -n 1 %subnet%.%%i ^| findstr /i "packets:"') do (
        if %%j EQU 1 (
            echo %subnet%.%%i is reachable
        ) else (
            echo %subnet%.%%i is not reachable
        )
    )
)

endlocal
