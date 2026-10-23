#include <stdio.h>
#include <string.h>
struct details{
    int roll;
    char name[50];
    int m1;
    int m2;
    int m3;
    int result;
};

struct details student[30];
int n=0;

void AddStudent(void){
    int i,num;
    printf("\nNumber of Students: ");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("\nStudent %d\n\n",i+1);
        printf("Roll: ");
        scanf("%d",&student[n].roll);
        printf("Name: ");
        scanf("%49s",student[n].name);
        printf("Marks\n");
        printf("Paper 1: ");
        scanf("%d",&student[n].m1);
        printf("Paper 2: ");
        scanf("%d",&student[n].m2);
        printf("Paper 3: ");
        scanf("%d",&student[n].m3);
        n++;
    }
    printf("\nRecord Save..!\n\n");
    }

void ShowStudent(void){
    int i;
    char remark[7];
    printf("\nRoll\tName\tPaper1\tPaper2\tPaper3\tResult\tRemark\n");
    for(i=0;i<n;i++){
            student[i].result = student[i].m1+student[i].m2+student[i].m3;
            if(student[i].result>100&& student[i].m1>40 && student[i].m2>40 && student[i].m3>40){
                strcpy(remark,"pass");
            }else{
                strcpy(remark,"fail");
            }
                printf("%d\t%s\t%d\t%d\t%d\t%d\t%s\n",student[i].roll,student[i].name,student[i].m1,student[i].m2,student[i].m3,student[i].result,remark);

    }
    printf("\nAll Record Shown..!\n\n");
}

void DeleteStudent(void){
    int i,roll,a;
    char response;
    printf("\nDelete Record:\n");
    printf("Enter Student Roll: ");
    scanf("%d",&roll);
    for(i=0;i<n;i++){
        if(student[i].roll==roll){
            printf("\nRoll: %d",student[i].roll);
            printf("\nName: %s\n",student[i].name);
            a=i;
            break;
        }
    }
    printf("\nDo You really want to delete this record?(y/n)\nChoice: ");
    scanf(" %c",&response);
    if(response=='y'||response=='Y'){
        for(i=a;i<n;i++){
            student[i].roll=student[i+1].roll;
            strcpy(student[i].name,student[i+1].name);
            student[i].m1=student[i+1].m1;
            student[i].m2=student[i+1].m2;
            student[i].m3=student[i+1].m3;
            student[i].result=student[i+1].result;
        }
        n--;

        printf("\n...OK RECORD DELETED\n\n");
        ShowStudent();
    }else if(response=='n'||response=='N'){
    printf("\n...OK NO RECORD DELETED\n\n");
        }else{
           printf("\nINVALID RESPONSE\n\n");
        }
}

void UpdateRecord(void){
    int i,len,temp,a,choice;
    char response;
    char name[50];
        printf("\nUpdate Record:\n");
        printf("Enter Student Roll: ");
        scanf("%d",&temp);
        for(i=0;i<n;i++){
        if(student[i].roll==temp){
            printf("\nUpadte\n");
            printf("1. Name\n");
            printf("2. Paper1\n");
            printf("3. Paper2\n");
            printf("4. Paper3\n");
            a=i;
        }
    }
    printf("\nChoice: ");
    scanf("%d",&choice);
    printf("\nRoll no %d Current name is %s\n",student[a].roll,student[a].name);
    switch(choice){
    case 1:
        printf("Enter new Name: ");
        scanf("%49s",name);
        printf("Do you really want to change %s to %s?(y/n)\nChoice:",student[a].name,name);
        scanf(" %c",&response);
        if(response=='y'||response=='Y'){
            len=strlen(name);
        for(i=0;i<len;i++){
            student[a].name[i]=name[i];
        }

        printf("\n...OK NAME UPDATED\n");
        ShowStudent();
        }else if(response=='n'||response=='N'){
        printf("\n...OK NO RECORD DELETED\n");
        }else{
           printf("\nINVALID RESPONSE\n");
        }
        break;

    case 2:
        printf("Enter new marks for paper1: ");
        scanf("%d",&temp);
        printf("Do you really want to change %d to %d?(y/n)\nChoice:",student[a].m1,temp);
        scanf(" %c",&response);
        if(response=='y'||response=='Y'){
            student[a].m1=temp;

        printf("...OK NAME UPDATED\n");
        ShowStudent();
        }else if(response=='n'||response=='N'){
        printf("\n...OK NO RECORD DELETED\n");
        }else{
           printf("\nINVALID RESPONSE\n");
        }
        break;

    case 3:
        printf("Enter new marks for paper2: ");
        scanf("%d",&temp);
        printf("Do you really want to change %d to %d?(y/n)\nChoice:",student[a].m2,temp);
        scanf(" %c",&response);
        if(response=='y'||response=='Y'){
            student[a].m2=temp;

        printf("\n...OK NAME UPDATED\n");
        ShowStudent();
        }else if(response=='n'||response=='N'){
        printf("\n...OK NO RECORD DELETED\n");
        }else{
           printf("\nINVALID RESPONSE\n");
        }
        break;

    case 4:
        printf("Enter new marks for paper3: ");
        scanf("%d",&temp);
        printf("Do you really want to change %d to %d?(y/n)\nChoice:",student[a].m3,temp);
        scanf(" %c",&response);
        if(response=='y'||response=='Y'){
            student[a].m3=temp;

        printf("\n...OK NAME UPDATED\n\n");
            ShowStudent();
        }else if(response=='n'||response=='N'){
            printf("\n...OK NO RECORD DELETED\n\n");
        }else{
           printf("\nINVALID RESPONSE\n\n");
        }
        break;

    }
}

void SearchStudent(void){
    int i,choice,comp,a;
    char name[50],remark[7];
        printf("\nSearch:\n");
        printf("1. Search By Name\n");
        printf("2. Search By Roll\n");
        printf("\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter Name: ");
            scanf("%49s",name);
            for(i=0;i<n;i++){
                comp=strcmp(name,student[i].name);
                if(comp==0){
                    a=i;
                    break;
                }

            }
            if(comp==0){
              printf("Roll\tName\tPaper1\tPaper2\tPaper3\tResult\tRemark\n");
              student[a].result = student[a].m1+student[a].m2+student[a].m3;
            if(student[a].result>100&& student[a].m1>40 && student[a].m2>40 && student[a].m3>40){
                strcpy(remark,"pass");
            }else{
                strcpy(remark,"fail");
            }
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%s\n",student[a].roll,student[a].name,student[a].m1,student[a].m2,student[a].m3,student[a].result,remark);
            }
        }
        printf("\nSearch Done...\n\n");
}

int main(){
    int choice;
    char exit;
    printf("Welcome Student Management System\n\n");
    do{
        printf("1. Add Student\n");
        printf("2. Show Student\n");
        printf("3. Delete Student\n");
        printf("4. Update Student\n");
        printf("5. Search Student\n");
        printf("0. Exit\n\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            AddStudent();
            break;
        case 2:
            ShowStudent();
            break;
        case 3:
            DeleteStudent();
            break;
        case 4:
            UpdateRecord();
            break;
        case 5:
            SearchStudent();
            break;
        case 0:
        printf("NOTE: AFTER EXITING SYSTEM ALL RECORD IS DELETED AUTOMATICALLY.... \n");
        printf("\nDo you want to exit?(y/n)\nChoice: ");
        scanf(" %c",&exit);
        printf("\nT H A N K  Y O U !\nFOR USING SYSTEM\n");
        }


    }while(choice!=0);


    return 0;
}
