// docnew.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <vector>
#include <Windows.h>
typedef vector<string> VecDev;

#define MutexLock(Mutex)		WaitForSingleObject(Mutex, INFINITE)
#define MutexLockTO(Mutex, TO)	WaitForSingleObject(Mutex, TO)
#define MutexUnLock(Mutex)		ReleaseMutex(Mutex)
HANDLE m_Mutex = CreateMutex(NULL, FALSE, NULL);


int main(int argc, _TCHAR* argv[])
{
    ifstream fpSrcFile("1.txt");
    string strSrc;
   
    static int space=0;
    static int line=0;
    VecDev VecSrc;
    while(getline(fpSrcFile,strSrc))
    {
        if (strSrc.empty())
        {
            space++;
            continue;
        }
        VecSrc.push_back(strSrc);
        line++;
        strSrc+="\n";
        cout<<strSrc;
    }
    cout<<"�ϼƣ�"<<space+line<<"��"<<endl;
    cout<<"���У�"<<space<<"   ������:"<<line<<endl;
   
    ifstream fpDestFile("3.txt");
    string strDest;
    VecDev vecDest;
    while (getline(fpDestFile,strDest))
    {
        if (strDest.empty())
        {
            continue;
        }
        vecDest.push_back(strDest);
    }
    cout<<"���Ƚ��ļ�����:"<<vecDest.size()<<endl;     
    vector<string>::iterator itDest;
    for (int i=0;i<VecSrc.size();i++)
    {
        for (itDest=vecDest.begin();itDest!=vecDest.end();)
        {
            if (VecSrc[i]==(*itDest))
            {
               itDest = vecDest.erase(itDest);
               continue;
            }
            else
            {
               itDest++;
            }
        }
    }
    cout<<"Ψһ����:"<<vecDest.size()<<endl;
    char bufer[1024]={0};
    FILE*fp= fopen("2.txt","w");
    for (int i=0;i<vecDest.size();i++)
    {
        cout<<vecDest[i]<<endl;
        fwrite(vecDest[i].c_str(),1,vecDest[i].length(),fp);
    }
    return 0;
}
