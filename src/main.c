//Kernel Drivers are written against the windows native api but not the 32-bit subsystem api 
//They are executed in kernel mode 
//When there is error with drivers the whole system fails (BSOD) so it requires to install a VM
//KMDF in visual studio don't use non ascii charachters in path it will replace the special
//charachters with ascii char and if drive don't exists the driver won't appear on the path specified
//Inf2cat enable use local time 
//it is a cmd line tool that decides wheather the driver package can be digitally signed for a specific
//windows version this is bascially a bug
//when we compile the driver many times the in file state is set to future date in that case it won't compile
//command line type /INTEGRITYCHECK it tells the signature of the binary image of driver 
#pragma warning (disable : 4100)

#include"main.h"
#include"messages.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistry){
    //define unload function here
    pDriverObject->DriverUnload = UnloadDriver;
    DbgPrintEx(0, 0, "Hello");
    DebugMessage("World !");
    return STATUS_SUCESS;
}

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject){
    DebugMessage("Good Bye !");
    return STATUS_SUCESS;    
}
//pDriverObject and pRegistry are unreferenced formal parameter remove this warning 4100
//How to start driver up (command prompt admin)
//copy the path sc create firstDriver type = kernel binpath="path"//the sys file(main.sys)
//To load an unsigned driver bcdedit /set testsigning on (sometimes we need to turn off secure boot here)
//reboot the machine now (windows test signing mode)
//go to DebugView as admin capture/capture kernel 
//cmd line as admin type sc start firstDriver and see output in DebugView to stop it type sc stop firstDriver