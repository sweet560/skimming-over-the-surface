#include <stdio.h>
#include <io.h>
int main(void)
{
    //�ļ��洢��Ϣ�ṹ��
    struct _finddata_t fileinfo;
    //�����ļ����
    long fHandle;
    //�ļ�����¼��
    int i = 0;
    chdir("..");
    chdir("diary/admin/2022-08");
    if ((fHandle = _findfirst("*.txt", &fileinfo)) == -1L)
    {
        printf("��ǰĿ¼��û��txt�ļ�\n");
        return 0;
    }
    else
    {
        do
        {
            i++;
            printf("�ҵ��ļ�:%s,�ļ���С��%d\n", fileinfo.name, fileinfo.size);
        } while (_findnext(fHandle, &fileinfo) == 0);
    }
    //�ر��ļ�
    _findclose(fHandle);

    printf("�ļ�������%d\n", i);

    return 0;
}