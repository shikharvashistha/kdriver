#pragma once

#define DebugMessage(x, ...) DbgPrintEx(0, 0, x, __VA_ARGS__)//va_args when we want to replace someting in the message