_main(processInformation)
    KERNEL32.OutputDebugStringA(0x40214c, processInformation)
    lastError_1 = KERNEL32.GetLastError()

    if (lastError == 0)
        hNtdll = KERNEL32.GetModuleHandleA("ntdll.dll")
        KERNEL32.GetModuleHandleA("AIDJDIAJIADA.adsaudas")
        lastError_2 = KERNEL32.GetLastError()

        if (lastError_2 != 0)
            eax_5 = KERNEL32.GetProcAddress(var_24, "NtQueryInformationProcess")
            procAddress_NtQueryInformationProcess = eax_5

            eax_6 = KERNEL32.GetProcAddress(var_2c, "NtSetInformationThread")
            procAddress_NtSetInformationThread = eax_6

            processInformation = null
            // https://docs.microsoft.com/en-us/windows/desktop/api/winternl/nf-winternl-ntqueryinformationprocess
            NtQueryInformationProcess(hProcessHandle=0xffffffff, ProcessInformationClass.ProcessDebugPort, &processInformation, ProcessInformationLength=4, ReturnLength=0)
            // The function returns an NTSTATUS success or error code.

            if (processInformation == 0)
                thread = KERNEL32.CreateThread(0, 0, _antiDebug, 0, 4, 0)
                NtSetInformationThread(thread, 0x11, 0, 0)
                KERNEL32.ResumeThread(thread)
                getchar() // so the application doesn't close immediately
                // ...unset vars...
                return 0;
            else
                stdio.puts("You know what, i actually don't really like that")
                getchar() // so the application doesn't close immediately
                // ...unset vars...
                return 0;


        else
            stdio.puts("It was a good try")
            getchar() // so the application doesn't close immediately
            // ...unset vars...
            return 0;


    else
        stdio.puts("Hey, I only like running under debuggers!")
        // ...unset vars...
        return 0;


_antiDebug()
    isDebuggerPresent = KERNEL32.IsDebuggerPresent()
        if (isDebuggerPresent == 0)
            // https://en.wikipedia.org/wiki/Process_Environment_Block<Paste>
            PEB = [fsbase + 0x30].d // PEB.BeingDebugged

            if (PEB.BeingDebugged != 0)
                stdio.puts("Yo fam, you got me!")
                getchar() // so the application doesn't close immediately
            else
                while(true) {} // endless fucking loop
        else
            stdio.puts("Hey man, you're getting close.")

