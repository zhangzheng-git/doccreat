// docnew.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
int main(int argc, _TCHAR* argv[])
{/*
    FILE *fp=fopen("1.txt","rb");
    if (fp==NULL)
    {
        printf("�ļ�������\n");
        return -1;
    }*/
   
   string filename;

   ifstream infile("1.txt");

   string temp;
   char bufer[1024]={0};

   FILE*fp= fopen("2.txt","w");
 static int space=0;
 static int line=0;
   while(getline(infile,temp))
   {
     
     if (temp.empty())
     {
         space++;
         continue;
     }
     
     line++;
     temp+="\n";
     cout<<temp;
     fwrite(temp.c_str(),1,temp.length(),fp);
     //fputs(temp.c_str(),fp);

   }
   cout<<"�ϼƣ�"<<space+line<<"��"<<endl;
   cout<<"���У�"<<space<<"   ������:"<<line<<endl;
	return 0;
}

