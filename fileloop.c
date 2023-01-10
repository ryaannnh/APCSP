#include <stdio.h>
int main() {
        FILE * fp;
        char c;
        char buff[255];  // create a buffer for reading the file
        printf("File Handling\n");
        //open a file
        fp = fopen("demo.txt", "w");   //this is to open the file
        //writing operation
        while ((c = getchar()) != '\t') {
            fputc(c, fp);
        }
        //close fileclear
        fclose(fp);
        printf("Data Entered:\n");
        //reading
        fp = fopen("demo.txt", "r");
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
        }
        fclose(fp);
         printf("\n");
          printf("Adding to the file\n");
        fp = fopen("demo.txt", "a");   //this is to open the file
        //writing operation
        while ((c = getchar()) != '\t') {
            fputc(c, fp);
        }
        //close file
        fclose(fp);
        printf("Data Entered after append:");
        //reading
        fp = fopen("demo.txt", "r");
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
        }
        fclose(fp);
        printf("\n");
        // section to read one line of the file

        int counter = 1;
        fp = fopen("demo.txt","r");
        while (!feof(fp))
        {
            fscanf(fp, "%s", buff);
            printf("%d : %s\n", counter, buff );
            counter++;
        }
        fclose(fp);


        // change the above piece of code so that number all the lines of the file
        // hints you need a counter and a way to stop the while loop
        return 0;
    }
