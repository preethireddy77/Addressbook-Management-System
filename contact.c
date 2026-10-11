#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
     switch(sortCriteria)
      { 
        case 1: printf("Sorting by name: \n"); 
        for(int i=0;i<addressBook->contactCount-1;i++) 
        { 
            for(int j=0;j<addressBook->contactCount-i-1;j++) { 
                if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0) { //compare both names and sort based on aphabetical order
                     Contact temp = addressBook->contacts[j];
                     addressBook->contacts[j]=addressBook->contacts[j+1]; 
                     addressBook->contacts[j+1]=temp;
                     } } } 
                     printf("Index No Name\t\tPhone\t\tEmail\n"); 
                     for(int i=0;i<addressBook->contactCount;i++) { //printing all the names after sorting
                        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email); } 
                        break;
    
case 2: printf("Sorting by phone: \n"); 
        for(int i=0;i<addressBook->contactCount-1;i++) 
        { 
            for(int j=0;j<addressBook->contactCount-i-1;j++) { 
                if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0) { //compare numbers and sort based on digits in ascending order 
                    Contact temp = addressBook->contacts[j];
                     addressBook->contacts[j]=addressBook->contacts[j+1]; 
                     addressBook->contacts[j+1]=temp;
                     } } } 
                     printf("Index No Name\t\tPhone\t\tEmail\n"); 
                     for(int i=0;i<addressBook->contactCount;i++) { //printf all the phone numbers after sorting
                        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                     } 
                        break;
                     case 3: printf("Sorting by email: \n"); 
        for(int i=0;i<addressBook->contactCount-1;i++) 
        { 
            for(int j=0;j<addressBook->contactCount-i-1;j++) { 
                if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0) { //compare emails and sort based on alphabetical order
                    Contact temp = addressBook->contacts[j];
                     addressBook->contacts[j]=addressBook->contacts[j+1]; 
                     addressBook->contacts[j+1]=temp;
                     } } } 
                     printf("Index No Name\t\tPhone\t\tEmail\n"); 
                     for(int i=0;i<addressBook->contactCount;i++) { // print all emails after sorting
                        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email); 
                    } 
                        break;
                }
            }

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    //Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); {// Save contacts to file
    // exit(EXIT_SUCCESS); // Exit the program
}
}



void createContact(AddressBook *addressBook)
{
    char str[50];
	/* Define the logic to create a Contacts */
    for(int i=0;i<3;i++){
        printf("enter the name: \n");
    scanf(" %[^\n]",str);
    if(str[0]>='0' && str[0]<='9' || strlen(str)<=4)// checking whether the entered name is starting with alphabets or not->if no
    {
        printf("Contact should not start with digits and should contain atleast 4characters");//printing contact not found
        if(i==2)
        return;
    }
    else{
        printf("Contact created successfully");// if yes printing contact created
        break;
    }
        }
        char str1[100];
        int i;
    for(i=0;i<3;i++){
         printf("enter the phone no. : \n");
scanf("%s",str1);
if(strlen(str1)!=10 || str1[0]<'6' || str1[0]>'9'){ //checking the number having only 10digits and starting with '6'-'9'
    printf("Phone no. not created");
    if(i==2)
    return;
    continue;
}
int correct=1;
    for(int j=0;str1[j]!='\0';j++){
        if(str1[j]<'0'||str1[j]>'9') // checking whether the number contain only digits or not
        correct=0;
        break;
    }
if(!correct){
    printf("Phone no. not created");
    if(i==2)
    return;
    continue;
    }
    int duplicate=0;
        for(int j=0;j<addressBook->contactCount;j++){
            if(strcmp(str1,addressBook->contacts[j].phone)==0){ //comparing the entered phone no. with all numbers to avoid repeating
                duplicate=1;
               break;
            }
        }
        if(duplicate){
            printf("phone no. already exists");
    }
    else{
        printf("Phone no. created successfully");
    }
            break;
}
char str2[100];
int j;

for(j=0;j<3;j++)
{
    int i,a=0,b=0;
    int a_count=0,b_count=0;
    int correct=1;

    printf("Enter the email: ");
    scanf(" %[^\n]",str2);
    if(str2[0]>='0' && str2[0]<='9') // Email should not start with a digit
        correct = 0;

    for(i=0;str2[i]!='\0';i++) 
    {
        if(str2[i]=='@')//checking @ is only once
        {
            a_count++;
            a=i;
        }

        if(str2[i]=='.' &&str2[i+1]=='c' &&str2[i+2]=='o' &&str2[i+3]=='m' &&str2[i+4]=='\0')//checking .com is only once
        {
            b_count++;
            b = i;
        }
    }

    
    if(a_count!=1 || b_count!=1)//checking @ and .com are occuring only once
        correct=0;

    if(a==0)// '@' should not be the first character
        correct=0;
    if(b<a) // ".com" should come after '@'
        correct=0;
    if(b==a+1)// There should be at least one character between '@' and '.com'
        correct=0;

    if(correct)
    {
        for(i=0;i<a;i++)
        {
            if(!((str2[i]>='a' && str2[i]<='z')))//check username before @
            {
                correct=0;
                break;
            }
        }
    }

    
    if(correct)
    {
        for(i=a+1;i<b;i++)
        {
            if(!((str2[i]>='a' && str2[i]<='z')))//check domain contains alphabets only
            {
                correct=0;
                break;
            }
        }
    }

    if(!correct)
    {
        printf("Invalid email\n");

        if(j==2)
            return;

        continue;
    }

    int found=0;

    for(i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str2,addressBook->contacts[i].email)==0)// checking whether the entered email is already present in the list
        {
            found=1;
            break;
        }
    }

    if(found)
    {
        printf("Email already exists\n");

        if(j==2)
            return;

        continue;
    }

    printf("Email created successfully\n");

    strcpy(addressBook->contacts[addressBook->contactCount].name, str);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, str1);
    strcpy(addressBook->contacts[addressBook->contactCount].email, str2);

    addressBook->contactCount++;

    break;
}
}
 


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    printf("1.Search by name \n");
    printf("2.search by phone no. \n");
    printf("3.Search by email \n");
    printf("4.Exit \n");
    int choice;
    printf("Enter the choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        char str[100];
        for(int i=0;i<3;i++){
        printf("Enter name to search: ");
        scanf(" %[^\n]",str);
        if(str[0]>='0' && str[0]<='9' || strlen(str)<=4) // checking whether the entered name is starting with alphabets or not
    {
        {
            printf("Contact not found"); 
            if(i==2)
            return;
        }
    }
        else{  
            for(int j=0;j<addressBook->contactCount;j++){
            if(strcmp(str,addressBook->contacts[j].name)==0){ //searching whether the entered name is matching with any name in list or not
                printf("%s %s %s",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                return;
                
            }
            }
                printf("Contact not found\n");
        }
    }
    break;
    case 2:
    for(int j=0;j<3;j++){
        printf("Enter phone no. to search: \n");
        scanf(" %[^\n]",str);
        if(strlen(str)!=10 && str[0]<'6' && str[0]>'9'){//checking the number having only 10digits and starting with '6'-'9'
       printf("Phone no. not exists");
       return;
       for(int i=0;str[i]!='\0';i++){
        if(str[i]<'0'||str[i]>'9')// checking whether the number contain only digits or not
       printf("phone no. not exists");
       if(j==2)
       return;
    }
}
    else{
        for(int j=0;j<addressBook->contactCount;j++){
            if(strcmp(str,addressBook->contacts[j].phone)==0){ // checking whether the phone no. is matching with any phone no.s in the list
                printf("%s %s %s",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                return;
                
            }
        }
                printf("Contact not found\n");
        }
    }

    break;
case 3:
   for(int j=0;j<3;j++){
    int a=0,b=0,a_count=0,b_count=0,correct=1;
    printf("Enter the email to search: \n");
    scanf(" %[^\n]",str);
    if(str[0]>='0' && str[0]<='9'){// checking whether the email is starting with digits
        correct=0;
    }
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='@'){// checking whether @ is present in string or not
            a_count++;
            a=i;
        }
        if (str[i] == '.' &&  //checking whether .com is present in string or not
        str[i + 1] == 'c' &&
        str[i + 2] == 'o' &&
        str[i + 3] == 'm' &&
        str[i + 4] == '\0')
    {
        b_count++;
        b = i;
    }
}
if(a_count!=1 || b_count!=1){// checking both @ and .com are present only once
    correct=0;
  
}
if(correct){
for(int i=0;i<a;i++){
    if(!(str[i]>='a' && str[i]<='z')){// checking the email before @ contains only alphabets
        correct=0;
        break;
    }
}
}
if(correct){
    if(b == a + 1)
    {
        correct = 0;
    }
    else
    {
        for(int i = a + 1; i < b; i++)
        {
            if(!((str[i] >= 'a' && str[i] <= 'z'))) //checking domain containing only alphabets
            {
                correct = 0;
                break;
            }
        }
    }
}
if(!correct){
    printf("Contact not found");
    if(j==2)
    return;
    continue;
}
 for(int j=0;j<addressBook->contactCount;j++){
        if(strcmp(str,addressBook->contacts[j].email)==0){// checking whether the the email is matching with any other emails in the list
        printf("%s %s %s",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
        return;
        }
    }
     printf("Contact not found");
    }

    break;
case 4:printf("Exit");
    }
}



void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char name[100];
    int arr[100];
    int n=0,choice,i,count=0;
    searchContact(addressBook);
    printf("Enter name again: \n");
    scanf(" %[^\n]",name);
    for (int i = 0; i < addressBook->contactCount; i++)
{
    if (strcmp(addressBook->contacts[i].name,name) == 0) // comparing whether the entered name is matching with the names in the list
    {
        arr[count] = i;  // store all the matched indexes in an array
        printf("%d %s %s %s\n",     // and printing those name,phone,email with sl.no
               count+1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
        count++;
    }
}
    if(count==0){
        printf("contact not found");
        return;
    }
    printf("Enter the serial number to edit: \n");
    scanf("%d",&n);
     if(n<1 || n>count){   //checking whether the serial number entered is in range or not
        printf("Invalid serial no.");
        return;
    }
    printf("1.Edit name \n");
    printf("2.Edit phone \n");
    printf("3.Edit email \n");
    printf("4.Exit\n");

    printf("Enter the choice: \n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
    for(int i=0;i<3;i++){
        printf("Enter new name: ");
        scanf(" %[^\n]",name);
        if(name[0]>='0' && name[0]<='9' || strlen(name))// checking whether the entered name is starting with alphabets or not
    {
        {
            printf("Invalid name and name should contain atleast 4 characters");
            if(i==2)
            return;
        }
    }
        else{
            for(i=0;i<count;i++){
                strcpy(addressBook->contacts[arr[n-1]].name,name); //updating new name to old name
                printf("Name updated successfully");
                return;
            }
        }
        
    }
break;
    case 2:
    char phone[100];
    int j;
    for(i=0;i<3;i++)
    {
        printf("enter new phone no.: \n");
        scanf(" %[^\n]",phone);
        if(strlen(phone)!=10 && phone[0]<'6' && phone[0]>'9')//checking the number having only 10digits and starting with '6'-'9'
        printf("Invalid phone");
        for(j=0;phone[j]!='\0';j++){
            if(phone[j]<'0'||phone[j]>'9')// checking whether the number contain only digits or not
            {
                printf("Invalid phone");
                if(i==2)
                return;
            }
        }
        for(i=0;i<count;i++){
                strcpy(addressBook->contacts[arr[n-1]].phone,phone); // replacing old number with new number
                printf("phone no. updated successfully");
                return;
        }
    }
    break;
case 3:
char email[100];

for(int i=0;i<3;i++)
{
    int a=0,b =0;
    int a_count=0,b_count=0;
    int correct=1;

    printf("Enter new email: ");
    scanf(" %[^\n]", email);

    
    if(email[0]>='0' && email[0]<='9')// checking email should not start with a digit
        correct=0;

    for(int j=0; email[j]!='\0';j++)
    {
        if(email[j]=='@')
        {
            a_count++;
            a = j;
        }

        if(email[j]=='.' &&email[j+1]=='c' &&email[j+2]=='o' &&email[j+3]=='m' &&email[j+4]=='\0')
        {
            b_count++;
            b=j;
        }
    }

    if(a_count!=1 || b_count!=1)// Check both  @ and .com are only once
        correct=0;

    if(correct)
    {
        for(int k=0;k<a;k++)
        {
            if(!(email[k]>='a' && email[k]<='z'))//checking name before @ having only aplhabets
            {
                correct=0;
                break;
            }
        }
    }

    // Check domain between @ and .com
    if(correct)
    {
        if(b==a+1)   
        {
            correct=0;
        }
        else
        {
            for(int k=a+1;k<b;k++)
            {
                if(!(email[k]>='a' && email[k]<='z'))//checking domain contains only alphabets
                {
                    correct = 0;
                    break;
                }
            }
        }
    }

    if(!correct)
    {
        printf("Invalid email");
        if(i==2)
            return;

        continue;
    }

    int duplicate=0; 
    for(int k=0;k<addressBook->contactCount;k++)
    {
        if(k==arr[n-1])
            continue;

        if(strcmp(email,addressBook->contacts[k].email)==0)//checking whether the email is already present in the list
        {
            duplicate=1;
            break;
        }
    }

    if(duplicate)
    {
        if(i==2)
            return;

        continue;
    }

    strcpy(addressBook->contacts[arr[n-1]].email, email);
    printf("Email updated successfully\n");
    return;
}
case 4:printf("Exit");
                }
    }


void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char str[100];
    int arr[100];
    int i,count=0,n;
    int contactCount=addressBook->contactCount;
    searchContact(addressBook);
    printf("Enter the name: \n");
    scanf(" %[^\n]",str);
    for(i=0;i<contactCount;i++){
        if(strcmp(addressBook->contacts[i].name,str)==0) //checking whether the enetered name is present in list or not
        {
            arr[count]=i;
            printf("%d %s %s %s\n",
               count+1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
        count++;
        }
    }
    if(count==0){
        printf("contact not found");
        return;
    }

    printf("Enter the serial no. to delete: \n");
    scanf("%d",&n);
    if(n<1 || n>count){   //checking whether the serial number entered is in range or not
        printf("Invalid serial no.");
        return;
    }
    i=arr[n-1];
    for(int j=i;j<addressBook->contactCount-1;j++){
        addressBook->contacts[j]=addressBook->contacts[j+1];   // after deleting that one contact moving  next contact to that place
    }
    addressBook->contactCount--; //decrementing contactCount
    printf("Contact deleted successfully");

   
}
