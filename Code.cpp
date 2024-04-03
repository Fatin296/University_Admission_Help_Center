#include<bits/stdc++.h>
using namespace std;

int n,i;
FILE *nfile;
struct info{
    char name[80];
    float gpa[3];
    int fee;
    int seat;
};


void check(info vsty[],info user){
    int flag=0;
    for(i=0;i<n;i++){
        if(strcasecmp(user.name, vsty[i].name) == 0){
            if( (user.gpa[0] >= vsty[i].gpa[0]) && (user.gpa[1] >= vsty[i].gpa[1]) && (user.gpa[2] >= vsty[i].gpa[2]) ){
                printf("\n\t\t\t\t\t\t\t\t\t<<<<<<<< You are Eligible >>>>>>>>\n\n");
                printf("Varsity Name: %-95s\t ",vsty[i].name);
                printf("SSC(min): %.2f;\t HSC(min): %.2f;\t Minimum Total GPA: %.2f\n",vsty[i].gpa[0],vsty[i].gpa[1],vsty[i].gpa[2]);
            }

            else{
                printf("\n\t\t\t\t\t\t\t\t\t<<<<<<<< You are Not Eligible >>>>>>>>\n\n");
                printf("Varsity Name: %-95s\t ",vsty[i].name);
                printf("SSC(min): %.2f;\t HSC(min): %.2f;\t Minimum Total GPA: %.2f\n",vsty[i].gpa[0],vsty[i].gpa[1],vsty[i].gpa[2]);
            }

            flag=1;
        }
        if(flag==1) break;
    }

    if(flag==0) printf("This Varsity is not in Database\n");
}



void eligible(info vsty[],info user){
    int flag=0;
    printf("\n\t\t\t\t\t\t\t\tList of Eligible Varsity\n\n");
    for(i=0;i<n;i++){
        if( (user.gpa[0] >= vsty[i].gpa[0]) && (user.gpa[1] >= vsty[i].gpa[1]) && (user.gpa[2] >= vsty[i].gpa[2]) ){
                printf("Varsity Name: %-80s\t ",vsty[i].name);
                printf("SSC(min): %.2f;\t HSC(min): %.2f;\t Minimum Total GPA: %.2f\n",vsty[i].gpa[0],vsty[i].gpa[1],vsty[i].gpa[2]);
                flag=1;
        }
    }
    if(flag==0) printf("\nSorry! You are not Eligible\n");
}



void sort_gpa(info vsty[]){
    int k;
    info temp;
    printf("\t\t\t\t\t\tMinimum Total GPA Requirement\n\n");
    for(i=1;i<n;i++){
        temp=vsty[i];
        k=i-1;
        while(k>=0 && vsty[k].gpa[2]>temp.gpa[2]){
            vsty[k+1]=vsty[k];
            k=k-1;
        }
        vsty[k+1]=temp;
    }

    for(i=0;i<n;i++){
        printf("%02d. Varsity Name: %-80s    ",i+1,vsty[i].name);
        printf("Minimum Total GPA: %0.2f\n",vsty[i].gpa[2]);
    }
}



void sort_fee(info vsty[]){
    int k;
    info temp;
    printf("\t\t\t\t\t\tList of Varsity Admission Form Fee\n\n");
    for(i=1;i<n;i++){
        temp=vsty[i];
        k=i-1;
        while(k>=0 && vsty[k].fee>temp.fee){
            vsty[k+1]=vsty[k];
            k=k-1;
        }
        vsty[k+1]=temp;
    }

    for(i=0;i<n;i++){
        printf("%02d. Varsity Name: %-80s    ",i+1,vsty[i].name);
        printf("Admission Form Fee: %d\n",vsty[i].fee);
    }
}



void sort_seat(info vsty[]){
    int k;
    info temp;
    printf("\t\t\t\t\t\tNumber of Seats of All Varsities\n\n");
    for(i=1;i<n;i++){
        temp=vsty[i];
        k=i-1;
        while(k>=0 && vsty[k].seat>temp.seat){
            vsty[k+1]=vsty[k];
            k=k-1;
        }
        vsty[k+1]=temp;
    }

    for(i=0;i<n;i++){
        printf("%02d. Varsity Name: %-80s    ",i+1,vsty[i].name);
        printf("Total Seats: %d\n",vsty[i].seat);
    }
}



void display(){
    info vsty;
    int t=1;
    printf("\t\t\t\t\t\t\t\t\t<<<<<<<< Science Group >>>>>>>>\n\n");
    nfile=fopen("Database1.txt","r");
    while(!feof(nfile)){
            fscanf(nfile," %[^\n]%f%f%f%d%d",&vsty.name,&vsty.gpa[0],&vsty.gpa[1],&vsty.gpa[2],&vsty.fee,&vsty.seat);
            printf("%02d. Varsity Name: %-75s\t SSC(min): %.2f\t HSC(min): %.2f\t ",t++,vsty.name,vsty.gpa[0],vsty.gpa[1]);
            printf("Total Min GPA: %.2f\t Form Fee: %d\t Total Seats: %d\n",vsty.gpa[2],vsty.fee,vsty.seat);
        }
         fclose(nfile);
         t=1;
    printf("\n\n\t\t\t\t\t\t\t\t\t<<<<<<< Commerce Group >>>>>>>\n\n");
    nfile=fopen("Database2.txt","r");
    while(!feof(nfile)){
            fscanf(nfile," %[^\n]%f%f%f%d%d",&vsty.name,&vsty.gpa[0],&vsty.gpa[1],&vsty.gpa[2],&vsty.fee,&vsty.seat);
            printf("%02d. Varsity Name: %-75s\t SSC(min): %.2f\t HSC(min): %.2f\t ",t++,vsty.name,vsty.gpa[0],vsty.gpa[1]);
            printf("Total Min GPA: %.2f\t Form Fee: %d\t Total Seats: %d\n",vsty.gpa[2],vsty.fee,vsty.seat);
        }
         fclose(nfile);
}



void admin(int x){
    int num,pass,j=1;
    info temp;
    while (j!=0){

	printf("\nInput the password[4 Digits]: ");
	scanf("%d",&pass);
	if (pass==1234){
		printf("Correct password");
		j=0;
    }
    else{
       printf("Wrong password, try another");
	}
	printf("\n\n\n");
   }

    printf("Enter How Many Varsities You Want to Add[%d]: ",n);
    scanf("%d",&num);
    if(x==1){
    nfile=fopen("Database1.txt","a");
    }
    else if(x==2){
    nfile=fopen("Database2.txt","a");
    }

    for(i=0;i<num;i++){
        printf("Enter Varsity Name: ");
        scanf(" %[^\n]s",temp.name);
        printf("SSC(min) GPA: ");
        scanf("%f",&temp.gpa[0]);
        printf("HSC(min) GPA: ");
        scanf("%f",&temp.gpa[1]);
        printf("Total Minimum GPA: ");
        scanf("%f",&temp.gpa[2]);
        printf("Admission Form Fee: ");
        scanf("%d",&temp.fee);
        printf("Number of Seats: ");
        scanf("%d",&temp.seat);

        fprintf(nfile,"\n%s\n%.2f %.2f %.2f\n%d\n%d",temp.name,temp.gpa[0],temp.gpa[1],temp.gpa[2],temp.fee,temp.seat);
        printf("\n");
        n++;
    }
    fclose(nfile);
    printf("Current Varsities in the Database: %d\n",n);
}


int main()
{
    int x,option;
    while(x!=1 && x!=2){
    printf("Choose Your Group:\n");
    printf("\t\t     Press 1 for science\n");
    printf("\t\t     Press 2 for commerce\n");
    printf("Enter your choice:");
    scanf("%d",&x);
    if(x!=1 && x!=2) printf("\nWrong Entry!!Please re-entered correct option\n\n");
    }

    if(x==1){
    nfile=fopen("Database1.txt","r");
    }
    else if(x==2){
    nfile=fopen("Database2.txt","r");
    }
    char ch;
    int count=0;
    while(!feof(nfile)){
        ch=fgetc(nfile);
        if(ch=='\n'){
            count++;
        }
    }
    fclose(nfile);
    n=(count+1)/4;


    info vsty[n],user;

if(x==1){
    nfile=fopen("Database1.txt","r");
    }
else if(x==2){
    nfile=fopen("Database2.txt","r");
    }
for(i=0;i<n;i++){
    fscanf(nfile," %[^\n]%f%f%f%d%d",&vsty[i].name,&vsty[i].gpa[0],&vsty[i].gpa[1],&vsty[i].gpa[2],&vsty[i].fee,&vsty[i].seat);
    }
    fclose(nfile);


    printf("\nEnter Your GPA of SSC: ");
    scanf("%f",&user.gpa[0]);
    printf("Enter Your GPA of HSC: ");
    scanf("%f",&user.gpa[1]);
    user.gpa[2]=user.gpa[0] + user.gpa[1];

    while(1){

    printf("\n\n\n");
    printf("\t\t\t\t<<<<<<<<<- MENU ->>>>>>>>>>\n\n");
    printf("\t\tEnter 1 to Check Specific Varsity Eligibility\n");
    printf("\t\tEnter 2 to Find All Eligible Varsity List\n");
    printf("\t\tEnter 3 to See the List of Total GPA Requirement\n");
    printf("\t\tEnter 4 to See the List of Admission Form Fee\n");
    printf("\t\tEnter 5 to See the Number of Seats of the Varsities\n");
    printf("\t\tEnter 6 to Display the List of All Varsities [Science & Commerce]\n");
    printf("\t\tEnter 7 to Go to the Admin Panel\n");
    printf("\t\tEnter 8 to Exit the menu\n");
    printf("\t\tEnter 0 to Exit Program\n");
    printf("\n\t\tEnter your choice:");
    scanf("%d",&option);

   switch(option){

       case 1:{
            printf("\nEnter A Varsity Name: ");
            scanf(" %[^\n]s",user.name);
            check(vsty,user);
            break;
       }
        case 2: eligible(vsty,user); break;

        case 3: sort_gpa(vsty); break;

        case 4: sort_fee(vsty); break;

        case 5: sort_seat(vsty); break;

        case 6: display(); break;

        case 7: admin(x); break;

        case 8: return main(); break;

        case 0: return 0; break;

        default: printf("\aWrong Entry!!Please re-entered correct option\n\n");

        }
    }

}
