using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;
using System.Data.SqlClient;


namespace ABInfo
{
    class WinApp
    {
        [DllImport("kernel32.dll")]
        public static extern IntPtr CreateFileMapping(IntPtr hFile, IntPtr lpFileMappingAttributes, uint flProtect, uint dwMaximumSizeHigh,
            uint dwMaximumSizeLow, string lpName);

        [DllImport("kernel32.dll")]
        public static extern IntPtr MapViewOfFile(IntPtr hFileMappingObject, uint
            dwDesiredAccess, uint dwFileOffsetHigh, uint dwFileOffsetLow, IntPtr dwNumberOfBytesToMap);

        [DllImport("kernel32.dll")]
        public static extern bool UnmapViewOfFile(IntPtr lpBaseAddress);

        [DllImport("kernel32.dll")]
        public static extern bool CloseHandle(IntPtr hObject);

        [DllImport("kernel32.dll")]
        public static extern IntPtr CreateFile(string lpFileName, int dwDesiredAccess, FileShare dwShareMode, IntPtr securityAttrs,
            FileMode dwCreationDisposition, int dwFlagsAndAttributes, IntPtr hTemplateFile);

        [DllImport("kernel32.dll")]
        public static extern uint GetFileSize(IntPtr hFile, IntPtr lpFileSizeHigh);

        public const int GENERIC_READ = -2147483648; //0x80000000
        public const int GENERIC_WRITE = 0x40000000;
        public const int GENERIC_EXECUTE = 0x20000000;
        public const int GENERIC_ALL = 0x10000000;
        public const int FILE_ATTRIBUTE_NORMAL = 0x80;
        public const int FILE_FLAG_SEQUENTIAL_SCAN = 0x8000000;
        public const int INVALID_HANDLE_VALUE = -1;

        public const int PAGE_NOACCESS = 1;
        public const int PAGE_READONLY = 2;
        public const int PAGE_READWRITE = 4;

        public const int FILE_MAP_COPY = 1;
        public const int FILE_MAP_WRITE = 2;
        public const int FILE_MAP_READ = 4;

        public static string MappingFileRead()
        {
            string result = "";
            try
            {
                IntPtr vFileHandle = CreateFile(@"c:/test.txt", GENERIC_READ | GENERIC_WRITE, FileShare.Read | FileShare.Write, IntPtr.Zero, FileMode.Open,
                FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, IntPtr.Zero);
                if (INVALID_HANDLE_VALUE != (int)vFileHandle)
                {
                    IntPtr vMappingHandle = CreateFileMapping(vFileHandle, IntPtr.Zero, PAGE_READWRITE, 0, 0, "~MappingTemp");
                    if (vMappingHandle != IntPtr.Zero)
                    {
                        IntPtr vHead = MapViewOfFile(vMappingHandle, FILE_MAP_COPY | FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, IntPtr.Zero);
                        if (vHead != IntPtr.Zero)
                        {
                            uint vSize = GetFileSize(vFileHandle, IntPtr.Zero);
                            byte[] res = new byte[vSize];
                            Marshal.Copy(vHead, res, 0, (int)vSize);
                            result = ASCIIEncoding.Default.GetString(res);
                            string[] _str = result.Split('|');
                            result = _str[0];
                            /*
                            //***************************************
                            //_IntPtr = Marshal.ReadIntPtr(vHead);                             
                            byte[] contentbyte1 = new byte[vSize];
                            for (int i = 0; i < vSize; i++)
                            {
                                byte vTemp = Marshal.ReadByte((IntPtr)((int)vHead + i));
                                contentbyte1[i] = vTemp;                               
                            }
                            Console.WriteLine(ASCIIEncoding.Default.GetString(contentbyte1));//全部值
                            //***************************************
                            byte[] contentbyte = new byte[vSize];
                            for (int i = 0; i < vSize; i++)
                            {
                                byte vTemp = Marshal.ReadByte((IntPtr)((int)vHead + i));
                                contentbyte[i] = vTemp;
                                if (vTemp == '|')//设定标识结束符合
                                {
                                    break;
                                }
                            }                            
                            Console.WriteLine(ASCIIEncoding.Default.GetString(contentbyte));//要取的值
                            result = ASCIIEncoding.Default.GetString(contentbyte);
                            //***************************************
                            */
                            UnmapViewOfFile(vHead);
                        }
                        CloseHandle(vMappingHandle);
                    }
                    CloseHandle(vFileHandle);
                }

            }
            catch
            { }
            return result;
        }
        public static IntPtr InvalidHandleValue = new IntPtr(-1);
        public static void MappingFileWrite(string val)
        {
            try
            {
                IntPtr vFileHandle = CreateFile(@"c:/test.txt", GENERIC_READ | GENERIC_WRITE, FileShare.Read | FileShare.Write, IntPtr.Zero, FileMode.Open,
                FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, IntPtr.Zero);
                if (INVALID_HANDLE_VALUE != (int)vFileHandle)
                {
                    IntPtr vMappingHandle = CreateFileMapping(vFileHandle, IntPtr.Zero, PAGE_READWRITE, 0, (UInt32)(val.Length + 1), "~MappingTemp");
                    if (vMappingHandle != IntPtr.Zero)
                    {
                        IntPtr vHead = MapViewOfFile(vMappingHandle, FILE_MAP_COPY | FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, IntPtr.Zero);
                        if (vHead != IntPtr.Zero)
                        {
                            byte[] by = ASCIIEncoding.Default.GetBytes(val + "|"); //设定标识结束符合  |   
                            Marshal.Copy(by, 0, vHead, by.Length);
                            UnmapViewOfFile(vHead);
                        }
                        CloseHandle(vMappingHandle);
                    }
                    CloseHandle(vFileHandle);
                }

            }
            catch
            { }
        }

        public static void MappingWrite1(string val)
        {
            try
            {
                IntPtr vMappingHandle = CreateFileMapping(InvalidHandleValue, IntPtr.Zero, PAGE_READWRITE, 0, (UInt32)(val.Length + 1), "~MappingTemp");
                if (vMappingHandle != IntPtr.Zero)
                {
                    IntPtr vHead = MapViewOfFile(vMappingHandle, FILE_MAP_COPY | FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, IntPtr.Zero);
                    if (vHead != IntPtr.Zero)
                    {
                        byte[] by = ASCIIEncoding.Default.GetBytes(val + "|"); //设定标识结束符合  |  
                        Marshal.Copy(by, 0, vHead, by.Length);
                        UnmapViewOfFile(vHead);
                    }
                    //CloseHandle(vMappingHandle);
                }

            }
            catch
            { }
        }
        public static string MappingRead1()
        {
            string result = "";
            try
            {
                IntPtr vMappingHandle = CreateFileMapping(InvalidHandleValue, IntPtr.Zero, PAGE_READWRITE, 0, 7, "~MappingTemp");
                if (vMappingHandle != IntPtr.Zero)
                {
                    IntPtr vHead = MapViewOfFile(vMappingHandle, FILE_MAP_COPY | FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, IntPtr.Zero);
                    if (vHead != IntPtr.Zero)
                    {
                        byte[] bytData = new byte[7];
                        Marshal.Copy(vHead, bytData, 0, 7);
                        result = ASCIIEncoding.Default.GetString(bytData);
                        UnmapViewOfFile(vHead);
                    }
                    CloseHandle(vMappingHandle);
                }
            }
            catch
            {
            }
            return result;
        }
    }
}
