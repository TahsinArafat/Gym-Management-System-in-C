#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing the details of the members
struct Member {
    int isSlotEmpty; // 1 = empty, 0 = filled
    char name[50];
    int id;
    char phone[50]; // +880 +91
    char email[50];
    char membership[50];
    int gender; // 0 = male, 1 = female
    int attendance;
};
void addMember(struct Member members[])
{
    int whichID;
    while (1) {
        printf("Enter ID: ");
        scanf("%d", &whichID);
        if (members[whichID].isSlotEmpty == 1) {
            members[whichID].isSlotEmpty = 0; // Slot is filled
            break;
        } else {
            printf("ID already exists. Please enter a different ID.\n");
        }
    }
    getchar();
    printf("Enter Name: ");
    scanf("%[^\n]s", members[whichID].name);
    getchar();
    printf("Male or Female? (0/1): ");
    scanf("%d", &members[whichID].gender);
    printf("Enter Phone: ");
    scanf("%s", members[whichID].phone);
    printf("Enter Email: ");
    scanf("%s", members[whichID].email);
    printf("Enter Membership (Monthly/Yearly/Weekly): ");
    scanf("%s", members[whichID].membership);
    printf("Member added successfully.\n");
    members[whichID].attendance = 0;
    members[whichID].id = whichID;
}
void viewMember(struct Member members[])
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    if (members[id].isSlotEmpty == 1) {
        printf("No member found with this ID.\n");
    } else {
        printf("Name: %s\n", members[id].name);
        printf("ID: %d\n", members[id].id);
        printf("Phone: %s\n", members[id].phone);
        printf("Email: %s\n", members[id].email);
        printf("Membership: %s\n", members[id].membership);
        printf("Gender: %s\n", members[id].gender == 0 ? "Male" : "Female");
        printf("Attendance: %d\n", members[id].attendance);
    }
}
void editMember(struct Member members[])
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    if (members[id].isSlotEmpty == 1) {
        printf("No member found with this ID.\n");
    } else {
        getchar();
        printf("Enter Name: ");
        scanf("%[^\n]s", members[id].name);
        getchar();
        printf("Male or Female? (0/1): ");
        scanf("%d", &members[id].gender);
        printf("Enter Phone: ");
        scanf("%s", members[id].phone);
        printf("Enter Email: ");
        scanf("%s", members[id].email);
        printf("Enter Membership (Monthly/Yearly/Weekly): ");
        scanf("%s", members[id].membership);
        printf("Enter Attendance: ");
        scanf("%d", &members[id].attendance);
        printf("Member edited successfully.\n");
    }
}
void deleteMember(struct Member members[])
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    if (members[id].isSlotEmpty == 1) {
        printf("No member found with this ID.\n");
    } else if (members[id].isSlotEmpty == 0) { // 0 = filled
        members[id].isSlotEmpty = 1; // The slot is now empty
        printf("Member deleted successfully.\n");
    }
}
void viewAllMembers(struct Member members[])
{
    for (int i = 1; i <= 100; i++) {
        if (members[i].isSlotEmpty == 0) {
            printf("Name: %s\n", members[i].name);
            printf("ID: %d\n", members[i].id);
            printf("Phone: %s\n", members[i].phone);
            printf("Email: %s\n", members[i].email);
            printf("Membership: %s\n", members[i].membership);
            printf("Attendance: %d\n", members[i].attendance);
            printf("\n");
        }
    }
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
void Attendance(struct Member members[])
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    if (members[id].isSlotEmpty == 1) {
        printf("No member found with this ID.\n");
    } else {
        members[id].attendance++;
        printf("Attendance recorded successfully.\n");
    }
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
    struct Member members[100 + 1]; // Limit: ID = 1 to 100
    for (int i = 1; i <= 100; i++) {
        members[i].isSlotEmpty = 1; // Initially all slots are empty (There are no members)
    }
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
            addMember(members);
            break;
        case 2:
            // View Member
            viewMember(members);
            break;
        case 3:
            // Edit Member
            editMember(members);
            break;
        case 4:
            // Delete Member
            deleteMember(members);
            break;
        case 5:
            // View All Members
            viewAllMembers(members);
            break;
        case 6:
            // BMI Calculator
            BMICalc();
            break;
        case 7:
            // Record Attendance
            Attendance(members);
            break;
        case 8:
            // View Rules
            viewRules();
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}