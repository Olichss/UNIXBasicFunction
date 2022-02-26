#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>

static int ReadingSize = 512;

bool Copy(int AppFileFlag, const std::string& fileName){
    ssize_t bytesRead;
    std::ofstream File;

    File.open(fileName, std::fstream::out | (AppFileFlag ? std::fstream::app : std::fstream::trunc) );

    if(!File.is_open())
        return false;

    char* buff = new char[ReadingSize];

    ssize_t ReadBytes = 0;  

    while ((ReadBytes = read(0, buff, ReadingSize)) > 0)
        File.write(buff, ReadBytes);

    delete[] buff;

    File.close();
    if(!File)   
        return false;

    return true;
}

int main(int argc, char** argv)
{
  if (argc <= 1) {
      printf("usage: %s [-a] [file...]\n", argv[0]);
      return 0;
  }

  bool IsApp = false;
  int opt = -1;

  std::string FileName;

  while ((opt = getopt(argc, argv, "a:")) != -1) {
      if(opt == 'a') {
        IsApp = true;
        FileName = optarg;
        puts("add");
      }
  } 
  if(!IsApp)
    FileName = argv[1];
    
  Copy(IsApp, FileName);

  return 0;
}