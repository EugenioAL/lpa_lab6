#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"


int main(int argc, char* argv[]){
    FILE *zip_file = fopen(argv[1], "rb");
    struct zip_file_hdr *file_hdr;
    lerFile(argv[1],file_hdr);    
}