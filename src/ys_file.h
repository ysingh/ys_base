#ifndef YS_FILE_H
#define YS_FILE_H
#include <stdio.h>
#include "ys_types.h"

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define PLATFORM 0
    #include <windows.h>
    #include <tchar.h>
    #include <strsafe.h>
    #include <fileapi.h>
    u64 BYTES_TRANSFERRED = 0;
#elif defined(__linux__) || defined(__unix) || defined(__FreeBSD__)
#define PLATFORM 1
#elif defined(__ANDROID__)
#define PLATFORM 2
#elif defined(__APPLE__)
#define PLATFORM 3
#else
#define PLATFORM 4
#endif

void read_file(b8* filePath, u64 bufLen, u8* buf);

#ifdef YS_FILE_IMPLEMENTATION

#if PLATFORM == 0
void DisplayError(LPTSTR lpszFunction) 
// Routine Description:
// Retrieve and output the system error message for the last-error code
{ 
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, 
        NULL );

    lpDisplayBuf = 
        (LPVOID)LocalAlloc( LMEM_ZEROINIT, 
                            ( lstrlen((LPCTSTR)lpMsgBuf)
                              + lstrlen((LPCTSTR)lpszFunction)
                              + 40) // account for format string
                            * sizeof(TCHAR) );
    
    if (FAILED( StringCchPrintf((LPTSTR)lpDisplayBuf, 
                     LocalSize(lpDisplayBuf) / sizeof(TCHAR),
                     TEXT("%s failed with error code %d as follows:\n%s"), 
                     lpszFunction, 
                     dw, 
                     lpMsgBuf)))
    {
        fprintf(stderr, "FATAL ERROR: Unable to output error code.\n");
    }
    
    _tprintf(TEXT("ERROR: %s\n"), (LPCTSTR)lpDisplayBuf);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

VOID CALLBACK FileIOCompletionRoutine(DWORD dwErrorCode,
    DWORD numberOfBytesTransferred,
    LPOVERLAPPED overlapped) {
        //_tprintf(TEXT("Error code:\t%x\n"), dwErrorCode);
        //_tprintf(TEXT("Number of bytes:\t%x\n"), numberOfBytesTransferred);
        BYTES_TRANSFERRED = numberOfBytesTransferred;
}

u64 read_file_windows(b8* filePath, u64 bufLen, u8* buf) {
    HANDLE fileHandle;
    DWORD bytesRead = 0;
    OVERLAPPED overlapped = {0};

    fileHandle = CreateFile(filePath,
            GENERIC_READ,
            FILE_SHARE_READ,
            0,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED,
            0);

    if (fileHandle == INVALID_HANDLE_VALUE) {
        DisplayError(TEXT("CreateFile"));
        _tprintf(TEXT("Terminal failure: unable to open file \"%s\" for read.\n"), filePath);
        fprintf(stderr, "Error opening file\n");
        return 0;
    }

    if (FALSE == ReadFileEx(fileHandle, buf, bufLen, &overlapped, FileIOCompletionRoutine)) {
        fprintf(stderr, "Error reading file\n");
        DisplayError(TEXT("CreateFile"));
        _tprintf(TEXT("Terminal failure: unable to open file \"%s\" for read.\n"), filePath);
        return 0;
    }
    SleepEx(5000, TRUE);

    bytesRead = BYTES_TRANSFERRED;
    //fprintf(stdout, "Number of bytes read: %d\n", bytesRead);
    return bytesRead;
}
#endif

void read_file(b8* filePath, u64 bufLen, u8* buf) {
    #if PLATFORM == 0
    read_file_windows(filePath, buflen,  buf);
    #endif
}
#endif

#endif
