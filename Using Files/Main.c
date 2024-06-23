#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing the details of the members
struct Member {
    int isSlotEmpty; // 1 = empty, 0 = filled
    char name[50];
    int id;
    char phone[50];
    char email[50];
    char membership[50];
    int gender; // 0 = male, 1 = female
    int attendance;
};

void addMember()
{
    struct Member member;
    FILE* file = fopen("members.txt", "a");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &member.id);
    getchar();
    printf("Enter Name: ");
    scanf("%[^\n]s", member.name);
    getchar();
    printf("Male or Female? (0/1): ");
    scanf("%d", &member.gender);
    printf("Enter Phone: ");
    scanf("%s", member.phone);
    printf("Enter Email: ");
    scanf("%s", member.email);
    printf("Enter Membership (Monthly/Yearly/Weekly): ");
    scanf("%s", member.membership);
    printf("Member added successfully.\n");
    member.attendance = 0;
    member.isSlotEmpty = 0;

    fprintf(file, "%d,%s,%d,%s,%s,%s,%d,%d\n", member.isSlotEmpty, member.name, member.id, member.phone, member.email, member.membership, member.gender, member.attendance);
    fclose(file);
}

void viewMember()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    FILE* file = fopen("members.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    struct Member member;
    int found = 0;
    while (fscanf(file, "%d,%[^,],%d,%[^,],%[^,],%[^,],%d,%d\n", &member.isSlotEmpty, member.name, &member.id, member.phone, member.email, member.membership, &member.gender, &member.attendance) != EOF) {
        if (member.id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Name: %s\n", member.name);
        printf("ID: %d\n", member.id);
        printf("Phone: %s\n", member.phone);
        printf("Email: %s\n", member.email);
        printf("Membership: %s\n", member.membership);
        printf("Gender: %s\n", member.gender == 0 ? "Male" : "Female");
        printf("Attendance: %d\n", member.attendance);
    } else {
        printf("No member found with this ID.\n");
    }

    fclose(file);
}

void editMember()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    FILE* file = fopen("members.txt", "r+");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    struct Member member;
    int found = 0;
    long int pos;
    while (fscanf(file, "%d,%[^,],%d,%[^,],%[^,],%[^,],%d,%d\n", &member.isSlotEmpty, member.name, &member.id, member.phone, member.email, member.membership, &member.gender, &member.attendance) != EOF) {
        if (member.id == id) {
            found = 1;
            break;
        }
        pos = ftell(file);
    }

    if (found) {
        getchar();
        printf("Enter Name: ");
        scanf("%[^\n]s", member.name);
        getchar();
        printf("Male or Female? (0/1): ");
        scanf("%d", &member.gender);
        printf("Enter Phone: ");
        scanf("%s", member.phone);
        printf("Enter Email: ");
        scanf("%s", member.email);
        printf("Enter Membership (Monthly/Yearly/Weekly): ");
        scanf("%s", member.membership);
        printf("Member edited successfully.\n");

        fseek(file, pos, SEEK_SET);
        fprintf(file, "%d,%s,%d,%s,%s,%s,%d,%d\n", member.isSlotEmpty, member.name, member.id, member.phone, member.email, member.membership, member.gender, member.attendance);
    } else {
        printf("No member found with this ID.\n");
    }

    fclose(file);
}

void deleteMember()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    FILE* file = fopen("members.txt", "r+");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    struct Member member;
    int found = 0;
    long int pos;
    while (fscanf(file, "%d,%[^,],%d,%[^,],%[^,],%[^,],%d,%d\n", &member.isSlotEmpty, member.name, &member.id, member.phone, member.email, member.membership, &member.gender, &member.attendance) != EOF) {
        if (member.id == id) {
            found = 1;
            break;
        }
        pos = ftell(file);
    }

    if (found) {
        member.isSlotEmpty = 1;
        fseek(file, pos, SEEK_SET);
        fprintf(file, "%d,%s,%d,%s,%s,%s,%d,%d\n", member.isSlotEmpty, member.name, member.id, member.phone, member.email, member.membership, member.gender, member.attendance);
        printf("Member deleted successfully.\n");
    } else {
        printf("No member found with this ID.\n");
    }

    fclose(file);
}

void viewAllMembers()
{
    FILE* file = fopen("members.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    struct Member member;
    while (fscanf(file, "%d,%[^,],%d,%[^,],%[^,],%[^,],%d,%d\n", &member.isSlotEmpty, member.name, &member.id, member.phone, member.email, member.membership, &member.gender, &member.attendance) != EOF) {
        if (member.isSlotEmpty == 0) {
            printf("Name: %s\n", member.name);
            printf("ID: %d\n", member.id);
            printf("Phone: %s\n", member.phone);
            printf("Email: %s\n", member.email);
            printf("Membership: %s\n", member.membership);
            printf("Attendance: %d\n", member.attendance);
            printf("\n");
        }
    }

    fclose(file);
}

void BMICalc()
{
    double weight, height, bmi;
    printf("Enter your weight in kg: ");
    scanf("%lf", &weight);
    printf("Enter your height in meters: ");
    scanf("%lf", &height);
    bmi = weight / pow(height, 2);
    printf("Your BMI is: %.2lf\n", bmi);
}

void Attendance()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    FILE* file = fopen("members.txt", "r+");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    struct Member member;
    int found = 0;
    long int pos;
    while (fscanf(file, "%d,%[^,],%d,%[^,],%[^,],%[^,],%d,%d\n", &member.isSlotEmpty, member.name, &member.id, member.phone, member.email, member.membership, &member.gender, &member.attendance) != EOF) {
        if (member.id == id) {
            found = 1;
            break;
        }
        pos = ftell(file);
    }

    if (found) {
        member.attendance++;
        fseek(file, pos, SEEK_SET);
        fprintf(file, "%d,%s,%d,%s,%s,%s,%d,%d\n", member.isSlotEmpty, member.name, member.id, member.phone, member.email, member.membership, member.gender, member.attendance);
        printf("Attendance recorded successfully.\n");
    } else {
        printf("No member found with this ID.\n");
    }

    fclose(file);
}

void viewRules()
{
    FILE* file;
    file = fopen("rules.txt", "r");

    if (file == NULL) {
        printf("File does not exist.\n");
    } else {
        char c;
        while ((c = getc(file)) != EOF)
            printf("%c", c);
        fclose(file);
    }
}

int main()
{
    while (1) {
        // Options
        printf("1. Add Member\n");
        printf("2. View Member\n");
        printf("3. Edit Member\n");
        printf("4. Delete Member\n");
        printf("5. View All Members\n");
        printf("6. BMI Calculator\n");
        printf("7. Record Attendance\n");
        printf("8. View Rules\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        int id;
        switch (choice) {
        case 1:
            // Add Member
            addMember();
            break;
        case 2:
            // View Member
            viewMember();
            break;
        case 3:
            // Edit Member
            editMember();
            break;
        case 4:
            // Delete Member
            deleteMember();
            break;
        case 5:
            // View All Members
            viewAllMembers();
            break;
        case 6:
            // BMI Calculator
            BMICalc();
            break;
        case 7:
            // Record Attendance
            Attendance();
            break;
        case 8:
            // View Rules
            viewRules();
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
}