#include<stdio.h>
#include <errno.h>
#include <string.h>
int freadtobuffer(const char* path, unsigned char buffer[]){
    FILE *ptr_myfile;
    ptr_myfile=fopen(path,"rb");
    if (!ptr_myfile)
    {
        printf("Unable to open file: %s", strerror(errno));
        return 1;
    }
    fseek(ptr_myfile, 0, SEEK_END);
    size_t size = ftell(ptr_myfile);         /*calc the size needed*/
    fseek(ptr_myfile, 0, SEEK_SET);
    buffer = (unsigned char *) malloc(size);
    fread(buffer, 1, size, ptr_myfile);
    return 0;
}

int main()
{
    unsigned char* buffer;
    freadtobuffer("C:\\Desert.jpg", buffer);
//    FILE *out;
//    out = fopen("test.bin","wb");
//    printf("%i",sizeof(buffer));
//    fwrite(&buffer, sizeof(char), sizeof(&buffer), out);
    return 0;
}
