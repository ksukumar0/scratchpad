#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <QFile.h>
bool copyFile(const char *src, const char *dest, bool failIfExists)
{
   if (QFile::exists(dest))
   {
      if (failIfExists)
      {
         return false;
      }
      else
      {
         QFile::remove(dest);
      }
   }
   QFile::copy(src, dest);
   return true;
}

#define BUF_SIZE 1000
int main(void)
{
   char buf[BUF_SIZE];
   char cwd[BUF_SIZE];
   getcwd(cwd, BUF_SIZE);

   printf("%s\n",cwd);
   //char file1 = "test1";
   //char file2 = "test2";

   //const char *src = strncat(cwd, file1);
   //const char *dest = strncat();
   //bool ret = copyFile(src, dest, TRUE);
}
