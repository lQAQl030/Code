#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]) {

    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /*To Do 
    Open the specified directory from command line argument 
    and check if the directory was opened successfully

    const char *directoryPath = ......
    ...
    ...
    if (...) {
        perror("Error opening directory");
        return 1;
    }
    */
    

    struct dirent *entry;
    struct stat statBuffer;
    off_t totalSize = 0;

    // Print the header for the inspection
    printf("Inspecting files in directory: %s\n", directoryPath);

    // Loop through each entry in the directory
    while (/*To Do */) {
    // Loop condition checks if there is another directory entry
        
        char filePath[256];
        snprintf(filePath, sizeof(filePath), "%s/%s", directoryPath, entry->d_name);

        /*To Do
        Obtain information about the entry and check if there was an error.

        hint: The file information should be stored in the statBuffer.
        */
        

        /*To Do 
        Print details for each file and directory 
        (Name, Size (in bytes), Type (Regular File or Directory), Modification time)
        
        printf("Name: %-20s ", entry->d_name);
        ...
        ...
        ...

        hint:You can use the functions mentioned in description to determine if the entry is a regular file or a directory
        */
        
    }


    /* To Do
    Close the directory
    */
    
    return 0;
}
