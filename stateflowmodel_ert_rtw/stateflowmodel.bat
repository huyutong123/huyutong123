set MATLAB=E:\software\MATLAB\R2017a

cd .

if "%1"=="" ("E:\software\MATLAB\R2017a\bin\win64\gmake"  -f stateflowmodel.mk all) else ("E:\software\MATLAB\R2017a\bin\win64\gmake"  -f stateflowmodel.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
