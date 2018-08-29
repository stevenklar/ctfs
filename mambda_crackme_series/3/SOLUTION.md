# Crackme 3

As things get a bit more fuzzy I disassambled the routine by hand to really see whats going on.
Basicly Crackme 3 is a combination of Crackme1 and Crackme2 plus some more educational stuff.

## AntiDebug Methods

As I didn't debugged the binary all of the following are just assumptions.

* OutputDebugStringA get's called to check if a debugger is present, if not GetLastError is not 0 which leads to bad path
* GetModuleHandle which doesn't exists, so GetLastError does not return 0
* Receive Process Information and check for ProcessInformationClass.ProcessDebugPort
* Create thread of a function which checks if "IsDebuggerPresent"

## Learnings

There are not only direct ways to check if a debugger is present. The query for the debug port is awesome. ;-)
Anti Debug logic can be hidden a new thread

**As the asm code of the main function is basicly fully translated to pseudo code I recommend look there for further understanding.**

## Solutions?

### Jump
* 1067 je => jmp
* 10a3 jne => jmp
* 0x10fe je => jmp
* 0x1008 je => jmp
* 0x1032 jne => jmp

You could also try to hide the debugger, or leave some jumps when don't even opening the debugger.
