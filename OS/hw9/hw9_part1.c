#include <stdio.h>
#include <stdlib.h>

int main() {

    /* To Do
    Open the source file for reading and destination file for writing, 
    and check if the file was opened successfully

    FILE* sourceFile = ......
    ...
    ...

    if (...) {
        perror("Unable to open source file for reading");
        return 1;
    }  ....

    */
    
    // Determine the size of the source file
    fseek(sourceFile, 0, SEEK_END); // Seek to the end of the file
    long fileSize = ftell(sourceFile); // Get the current position (file size)
    fseek(sourceFile, 0, SEEK_SET); // Seek back to the beginning of the file
    
    // Allocate a buffer to hold the file contents
    char* buffer = (char*)malloc(fileSize);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(sourceFile);
        fclose(destinationFile);
        return 1;
    }
    
    /* To Do
    Read the contents of the source file into the buffer 
    ...
    ...
    ...

    and check if the contents was read successfully
    if (...) {
        perror("Error reading from source file");
        free(buffer);
        fclose(sourceFile);
        fclose(destinationFile);
        return 1;
    }
    */
    
    
    /*To Do
    Reverse the contents of the buffer
    */
    
    /*To Do
    Write the reversed buffer to the destination file
    ...
    ...
    ...

    and check if the file was wrote successfully
    if (...) {
        perror("Error writing to destination file");
        free(buffer);
        fclose(sourceFile);
        fclose(destinationFile);
        return 1;
    }
    */
     
    
    
    /* To Do 
      Clean up and close the files.....
    
    */
    
    
    return 0;
}
