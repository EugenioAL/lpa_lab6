#ifndef _myLib
#define _myLib



struct zip_file_hdr {
int signature;
short version;
short flags;
short compression;
short mod_time;
short mod_date;
int crc;
int compressed_size;
int uncompressed_size;
short name_length;
short extra_field_length;
} __attribute__ ((packed));


int lerFile(char *file, struct zip_file_hdr *tmp);



#endif