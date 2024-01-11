#include <stdio.h>
#include <stdlib.h>

int main() {

    /* To Do
    Open the source file for reading and destination file for writing, 
    and check if the file was opened successfully
    */
    FILE* sourceFile = fopen("source.txt", "r");
    FILE* destinationFile = fopen("destination.txt", "w");
    if(!sourceFile){
        perror("Unable to open source file for reading");
        return 1;
    }
    if(!destinationFile){
        perror("Unable to open/create destination file for writing");
        return 1;
    }
    
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
    and check if the contents was read successfully
    */
    size_t readSize = fread(buffer, sizeof(char), fileSize, sourceFile);
    if(readSize < fileSize){
        perror("Error reading from source file");
        free(buffer);
        fclose(sourceFile);
        fclose(destinationFile);
        return 1;
    }
    
    
    /*To Do
    Reverse the contents of the buffer
    */
    int start = 0, end = fileSize - 1;
    while(start < end){
        char temp;
        temp = buffer[start];
        buffer[start++] = buffer[end];
        buffer[end--] = temp;
    }
    
    /*To Do
    Write the reversed buffer to the destination file
    and check if the file was wrote successfully
    */
    size_t writeSize = fwrite(buffer, sizeof(char), fileSize, destinationFile);
    if(writeSize < fileSize){
        perror("Error writing to destination file");
        free(buffer);
        fclose(sourceFile);
        fclose(destinationFile);
        return 1;
    }
     
    
    
    /* To Do 
      Clean up and close the files.....
    */
    free(buffer);
    fclose(sourceFile);
    fclose(destinationFile);
    
    
    return 0;
}
