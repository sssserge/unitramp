#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        int fd;
        size_t size;
        char string[] = "Gr. 3.008.2.23";
        if((fd = open("wrfile.txt", O_WRONLY|O_CREAT, 0666)) <0) {
                printf("Oshipka pri otritii faila na zapis\n");
                exit(-1);
        }
        size = write(fd, string, 14);
        if (size !=14) {
                printf("Ne udalos zapisat' 14 bait v fail\n");
                exit(-1);
        }
        else printf ("Stroka zapisana v fil\n");
        if (close(fd) <0) {
                printf("Ne poluchilos' zakrit' fail\n");
                exit(-1);
        }
        char resstring{14];
        if((fd = open("wrtfile.txt", O_RDONLY)) < 0) {
                printf("Oshibka pri otkritii faila na chtenie\n");
                exit(-1);
        }
        size = read(fd, resstring, 14);
        if (size ! = 14) {
                printf("Ne udalos prochitat 14 bait iz faila\n");
                exit(-1);
        }
        else printf("Prochitannaia stroka: %s\n", resstring):
        if (close(fd) < 0) {
                printf("Ne poluchilos zakrit fail\n");
                exit(-1P);
        } 
        return 0;
}
             
