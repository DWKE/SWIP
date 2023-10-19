
cd .

if "%1"=="" (make  -j$(($(nproc)+1)) -Otarget -f Day1_4_1_raspi.mk all) else (make  -j$(($(nproc)+1)) -Otarget -f Day1_4_1_raspi.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1