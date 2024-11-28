#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FILENAME "users.txt"

typedef struct
{
    int id;
    char name[50];
    int age;
} User;

bool fileExists(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file)
    {
        fclose(file);
        return true;
    }
    return false;
}

void createUser()
{
    FILE *file = fopen(FILENAME, "a");
    if (!file)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    User user;
    printf("Enter ID: ");
    if (scanf("%d", &user.id) != 1)
    {
        printf("Invalid ID input.\n");
        fclose(file);
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", user.name);

    printf("Enter Age: ");
    if (scanf("%d", &user.age) != 1)
    {
        printf("Invalid age input.\n");
        fclose(file);
        return;
    }

    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);

    printf("User added successfully.\n");
}

void readUsers()
{
    if (!fileExists(FILENAME))
    {
        printf("No users found. File does not exist.\n");
        return;
    }

    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("Error: Unable to open file for reading.\n");
        return;
    }

    User user;
    printf("\n--- User Records ---\n");
    bool found = false;

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3)
    {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
        found = true;
    }

    if (!found)
    {
        printf("No records found.\n");
    }

    fclose(file);
}

void updateUser()
{
    if (!fileExists(FILENAME))
    {
        printf("No users found. File does not exist.\n");
        return;
    }

    int idToUpdate;
    printf("Enter the ID of the user to update: ");
    if (scanf("%d", &idToUpdate) != 1)
    {
        printf("Invalid ID input.\n");
        return;
    }

    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile)
    {
        printf("Error: Unable to open file.\n");
        if (file)
            fclose(file);
        if (tempFile)
            fclose(tempFile);
        return;
    }

    User user;
    bool found = false;

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3)
    {
        if (user.id == idToUpdate)
        {
            found = true;
            printf("Enter new Name: ");
            scanf(" %[^\n]s", user.name);
            printf("Enter new Age: ");
            if (scanf("%d", &user.age) != 1)
            {
                printf("Invalid age input. Aborting update.\n");
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return;
            }
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
    {
        printf("User updated successfully.\n");
    }
    else
    {
        printf("User with ID %d not found.\n", idToUpdate);
    }
}

void deleteUser()
{
    if (!fileExists(FILENAME))
    {
        printf("No users found. File does not exist.\n");
        return;
    }

    int idToDelete;
    printf("Enter the ID of the user to delete: ");
    if (scanf("%d", &idToDelete) != 1)
    {
        printf("Invalid ID input.\n");
        return;
    }

    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile)
    {
        printf("Error: Unable to open file.\n");
        if (file)
            fclose(file);
        if (tempFile)
            fclose(tempFile);
        return;
    }

    User user;
    bool found = false;

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3)
    {
        if (user.id == idToDelete)
        {
            found = true;
            continue;
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
    {
        printf("User deleted successfully.\n");
    }
    else
    {
        printf("User with ID %d not found.\n", idToDelete);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CRUD Operations ---\n");
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting program.\n");
            exit(1);
        }

        switch (choice)
        {
        case 1:
            createUser();
            break;
        case 2:
            readUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
