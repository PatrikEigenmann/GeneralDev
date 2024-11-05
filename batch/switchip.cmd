@echo off
:: ------------------------------------------------------------------------------------------
:: switchip.cmd - batch script to switch the ip address on the ethernet adapter 10, so I
:: don't have to go into settings->network settings->ethernet->change ethernet adaptapter->
:: IP v4 and switch manually the ip. typing into a terminal with administrator rights
:: "switchip.cmd" is way quicker then the visual way.
:: ------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: ------------------------------------------------------------------------------------------
:: Change Log:
:: Monday 2024-11-04 File created.                                              Version 00.01
:: ------------------------------------------------------------------------------------------
setlocal

:menu
echo Select an option:
echo 1. Set IP to 192.168.1.100 / 255.252.0.0
echo 2. Set IP to 10.248.0.100 / 255.252.0.0
echo 3. Exit
set /p choice="Enter choice (1/2/3): "

if %choice%==1 goto set_ip_1
if %choice%==2 goto set_ip_2
if %choice%==4 goto end

:set_ip_1
echo Setting IP to 192.168.1.100 / 255.252.0.0
netsh interface ip set address name="Ethernet 10" static 192.168.1.100 255.252.0.0
goto end

:set_ip_2
echo Setting IP to 10.248.0.100 / 255.252.0.0
netsh interface ip set address name="Ethernet 10" static 10.248.0.100 255.252.0.0
goto end

:end
echo Done.
endlocal
exit /b