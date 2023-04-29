#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SDB.h"

int counter=0;
bool SDB_is_ID_exist(int Ident){

students* temp=head;
printf("Student IDs:\n");

while(temp!=NULL){
   if(temp->ID==Ident)
    {
     return 1;
    }
temp=temp->next;
}
return 0;
}

void get_list_ID(void){
students* temp=head;
printf("Student IDs List:\n");

while(temp!=NULL){
printf("%d\n",temp->ID);
temp=temp->next;
}
}
bool SDB_isfull(void){

if(counter==10){

    return 1;
}
else
    return 0;
}

int SDB_getusedsize(void){
return printf("The Number of entries: (%d)\n",counter);
}

void print_entry(){
    int read_ID;
    printf("enter the Student ID: ");
    fflush(stdin);
    scanf("%d",&read_ID);
    students *temp=head;

while(temp!=NULL){

if(temp->ID==read_ID){
printf("student id is %d \n",temp->ID);
printf("student year is %d \n",temp->student_year);
printf("course 1 id is %d \n",temp->course_ID[0]);
printf("course 2 id is %d \n",temp->course_ID[1]);
printf("course 3 id is %d \n",temp->course_ID[2]);
printf("course 1 grade is %d \n",temp-> grades[0]);
printf("course 2 grade is %d \n",temp-> grades[1]);
printf("course 3 grade is %d \n",temp-> grades[2]);

}
temp=temp->next;

}
}

void add_entry(void){
students *node=NULL;
node=(students*)malloc(sizeof(students));

if(counter==10){

    printf(" The list is completed \n");
    return;
}

printf("Enter the student ID: \n");
fflush(stdin);
scanf("%d",&node->ID);
printf("Enter the student year:\n");
fflush(stdin);
scanf("%d",&node->student_year);
printf("Enter the student course(1) ID:\n");
fflush(stdin);
scanf("%d",&node->course_ID[0]);
printf("Enter the student course(1) grade: \n");
fflush(stdin);
scanf("%d",&node->grades[0]);
printf("Enter the student course(2) ID: \n");
fflush(stdin);
scanf("%d",&node->course_ID[1]);
printf("Enter the student course(2) grade: \n");
fflush(stdin);
scanf("%d",&node->grades[1]);
printf("Enter the student course(3) ID:\n");
fflush(stdin);
scanf("%d",&node->course_ID[2]);
printf("Enter the student course(3) grade:\n");
fflush(stdin);
scanf("%d",&node->grades[2]);

node->next=head;
head=node;
counter++;
printf("____________________( The new entry is successfully added )______________________\n");
printf("\n");
}

void deleted_entry(){
	int deleted_ID;
	printf("Enter the ID to delete the Entry: \n");
	fflush(stdin);
	scanf("%d",&deleted_ID);
students * delete_node=NULL;
students * current_ptr=NULL;
students * previos_ptr=NULL;


if (head==NULL){
	printf("the list is empty ");
	return;
}
current_ptr=head;
if (current_ptr->ID==deleted_ID){
	delete_node=head;
	head=current_ptr->next;
	free(delete_node);
	printf("______________________( The entry deleted successfully )_________________________\n");
	counter--;
	return;
}

current_ptr=current_ptr->next;
previos_ptr=head;
while (current_ptr!=NULL){
	if (current_ptr->ID==deleted_ID){
		delete_node=current_ptr;
		previos_ptr->next=current_ptr->next;
		free(delete_node);
		printf("______________________( The entry deleted successfully )_________________________\n");
		counter--;
		return;
	}
	previos_ptr=current_ptr;
	current_ptr=current_ptr->next;
}


}

void main(){

    while (1){
printf("\n");
printf("*********************************************************************************\n");
printf("*************************(Simple Database For Students)**************************\n");
printf("*********************************************************************************\n");
printf("*********************************************************************************\n");
printf("*                        choose (1) to add new student                          *\n");
printf("*                        choose (2) to delete student                           *\n");
printf("*                        choose (3) to view student info                        *\n");
printf("*                        choose (4) to Get List of IDs                          *\n");
printf("*                        choose (5) to Is ID Exists                             *\n");
printf("*********************************************************************************\n");
printf("\n");
int x,y,z,ID;
int your_choice;

x=SDB_isfull();
if(x==1)
    printf("DATABASE IS FULL\n");

fflush(stdin);
printf("Choice: ");
scanf("%d",&your_choice);

switch (your_choice)
{
	case 1:
	add_entry();
	y=SDB_getusedsize();
	break;
	case 2:
	deleted_entry();
	y=SDB_getusedsize();
	break;
	case 3:
	print_entry();
	break;
	case 4:
    get_list_ID();
    break;
    case 5:
        printf("Please enter student ID to check: ");
        fflush(stdin);
        scanf("%d",&ID);
        z=SDB_is_ID_exist(ID);
        if(z==1)
            printf("the ID is Exist\n");
        else if(z==0)
            printf("the ID is Not Exist\n");
    break;
	default:
	printf("( Wrong input please enter a valid choice )\n");
	break;

}
    }
}
