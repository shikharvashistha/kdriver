#pragma once

#include<ntifs.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistry);//This is like public static void main

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject);   