// docnew.cpp : 定义控制台应用程序的入口点。
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
        printf("文件不存在\n");
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
   cout<<"合计："<<space+line<<"行"<<endl;
   cout<<"空行："<<space<<"   数据行:"<<line<<endl;
	return 0;
}

