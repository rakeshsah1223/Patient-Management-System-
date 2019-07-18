#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct doctor
{
	int dr_id;
	char dr_name[50],dr_phno[12];
};

struct patient{
	int p_id,age;
	char pname[50],pproblem[50],psex[6],ppno[12];
	
};


void doc()
{
	struct doctor d1;
	FILE *p1;
	p1=fopen("doc.txt","a");
	if(p1==NULL)
	{
		printf("File does not avalable");
	}
	else
	{
		printf("Enter Doc name : ");
		scanf("%s",d1.dr_name);
		fprintf(p1,"%s\t",d1.dr_name);
		printf("Enter Doc id : ");
		scanf("%d",&d1.dr_id);
		fprintf(p1,"%d\t",d1.dr_id);
		printf("Enter Doc pno : ");
		scanf("%s",d1.dr_phno);
		fprintf(p1,"%s\n",d1.dr_phno);
	}
	fclose(p1);
}

void doc_display()
{
	struct doctor d1;
	FILE *p1;
	p1=fopen("doc.txt","r");
	printf("\nName\tID\tPno\n\n");
	while((fscanf(p1,"%s",d1.dr_name),fscanf(p1,"%d",&d1.dr_id),fscanf(p1,"%s",d1.dr_phno))==1)
	{
		printf("%s\t",d1.dr_name);
		printf("%d\t",d1.dr_id);

		printf("%s\n",d1.dr_phno);
	}
	fclose(p1);
}

void patient()
{
	struct patient p;
	FILE *p2,*p1;
	p1=fopen("patient.txt","a");
	p2=fopen("patientq.txt","a");
	if(p2==NULL)
        printf("file does not found");
    else
    { 
      printf("name :");
      scanf("%s",p.pname);
      printf("p_id :");
      scanf("%d",&p.p_id);
      printf("age :");
      scanf("%d",&p.age);
      printf("sex :");
      scanf("%s",p.psex);
      printf("phone_no :");
      scanf("%s",p.ppno);
      printf("problem :");
      scanf("%s",p.pproblem);


      fprintf(p2,"%s\t",p.pname);
      fprintf(p2,"%d\t",p.p_id);
      fprintf(p2,"%d\t",p.age);
      fprintf(p2,"%s\t",p.psex);
      fprintf(p2,"%s\t",p.ppno);
      fprintf(p2,"%s\n",p.pproblem);
      
      fprintf(p1,"%s\t",p.pname);
      fprintf(p1,"%d\t",p.p_id);
      fprintf(p1,"%d\t",p.age);
      fprintf(p1,"%s\t",p.psex);
      fprintf(p1,"%s\t",p.ppno);
      fprintf(p1,"%s\n",p.pproblem);
    }
    fclose(p2);
    fclose(p1);
	
}

void emer_patient()
{
	struct patient p;
	FILE *p1,*p2,*p3;
	p1=fopen("patientq.txt","r");
	p2=fopen("temp.txt","a");
	p3=fopen("patient.txt","a");
	if(p2==NULL)
        printf("file does not found");
    else
    { 
      printf("name :");
      scanf("%s",p.pname);
      printf("p_id :");
      scanf("%d",&p.p_id);
      printf("age :");
      scanf("%d",&p.age);
      printf("sex :");
      scanf("%s",p.psex);
      printf("phone_no :");
      scanf("%s",p.ppno);
      printf("problem :");
      scanf("%s",p.pproblem);


      fprintf(p2,"%s\t",p.pname);
      fprintf(p2,"%d\t",p.p_id);
      fprintf(p2,"%d\t",p.age);
      fprintf(p2,"%s\t",p.psex);
      fprintf(p2,"%s\t",p.ppno);
      fprintf(p2,"%s\n",p.pproblem);
      
      fprintf(p3,"%s\t",p.pname);
      fprintf(p3,"%d\t",p.p_id);
      fprintf(p3,"%d\t",p.age);
      fprintf(p3,"%s\t",p.psex);
      fprintf(p3,"%s\t",p.ppno);
      fprintf(p3,"%s\n",p.pproblem);
    }
    while((fscanf(p1,"%s",p.pname),fscanf(p1,"%d",&p.p_id),fscanf(p1,"%d",&p.age),fscanf(p1,"%s",p.psex),fscanf(p1,"%s",p.ppno),fscanf(p1,"%s",p.pproblem))==1)
   	{
		fprintf(p2,"%s\t",p.pname);
      	fprintf(p2,"%d\t",p.p_id);
 	     fprintf(p2,"%d\t",p.age);
    	  fprintf(p2,"%s\t",p.psex);
	      fprintf(p2,"%s\t",p.ppno);
    	  fprintf(p2,"%s\n",p.pproblem);  
	}
	fclose(p1);
    fclose(p2);
    fclose(p3);
    remove("patientq.txt");
	rename("temp.txt","patientq.txt");
}

void display_patient(int n)																	//1 - for queqe      else - for all record
{
	struct patient p;
	FILE *p2,*p3;
	p2=fopen("patientq.txt","r");
	p3=fopen("patient.txt","r");
	if(p2==NULL)
        printf("file does not found");
    else
    {
    	if(n==1)
    	while((fscanf(p2,"%s",p.pname),fscanf(p2,"%d",&p.p_id),fscanf(p2,"%d",&p.age),fscanf(p2,"%s",p.psex),fscanf(p2,"%s",p.ppno),fscanf(p2,"%s",p.pproblem))==1)
    	{
				printf("%s\t",p.pname);
				printf("%d\n",p.p_id);
		}
		else
    	while((fscanf(p3,"%s",p.pname),fscanf(p3,"%d",&p.p_id),fscanf(p3,"%d",&p.age),fscanf(p3,"%s",p.psex),fscanf(p3,"%s",p.ppno),fscanf(p3,"%s",p.pproblem))==1)
		{	
				printf("%s\t",p.pname);
				printf("%d\t",p.p_id);
    			printf("%d\t",p.age);
    			printf("%s\t",p.psex);
    			printf("%s\t",p.ppno);
    			printf("%s\n",p.pproblem); 
		}
    }
     fclose(p2);
     fclose(p3);
}

void search_patient()																	
{
	struct patient p;
	int key,found=0;
	FILE *p2;
	p2=fopen("patient.txt","r");
	printf("\n\nEnter patient ID : ");
	scanf("%d",&key);
	if(p2==NULL)
        printf("file does not found");
    else
    {
    	while((fscanf(p2,"%s",p.pname),fscanf(p2,"%d",&p.p_id),fscanf(p2,"%d",&p.age),fscanf(p2,"%s",p.psex),fscanf(p2,"%s",p.ppno),fscanf(p2,"%s",p.pproblem))==1)
    	{
    		if(key==p.p_id)
    		{
    			printf("\n\nName : %s\n",p.pname);
				printf("ID : %d\n",p.p_id);
    			printf("Age : %d\n",p.age);
    			printf("Sex : %s\n",p.psex);
    			printf("Pno : %s\n",p.ppno);
    			printf("Problem : %s\n",p.pproblem);
    			found=1;
    		}
		}
		if(found==0)
		printf("\n\nDAta not found\n\n");
    }
     fclose(p2);
}


void modify()
{
	struct patient p;
	int key,found=0;
	FILE *p1,*p2;
	p1=fopen("temp.txt","a");
	p2=fopen("patientq.txt","r");
	printf("\n\nEnter patient ID for modify : ");
	scanf("%d",&key);
	if(p2==NULL)
        printf("file does not found");
    else
    {
    	while((fscanf(p2,"%s",p.pname),fscanf(p2,"%d",&p.p_id),fscanf(p2,"%d",&p.age),fscanf(p2,"%s",p.psex),fscanf(p2,"%s",p.ppno),fscanf(p2,"%s",p.pproblem))==1)
    	{
    		if(key==p.p_id)
    		{
    			printf("name :");
				scanf("%s",p.pname);
 			     //printf("p_id :");
  			   // scanf("%d",&p.p_id);
  			    printf("age :");
   			   scanf("%d",&p.age);
   			   printf("sex :");
    		  scanf("%s",p.psex);
   			   printf("phone_no :");
    		  scanf("%s",p.ppno);
    		  printf("problem :");
     		 scanf("%s",p.pproblem);


 			fprintf(p1,"%s\t",p.pname);
 		     fprintf(p1,"%d\t",p.p_id);
 		     fprintf(p1,"%d\t",p.age);
  		    fprintf(p1,"%s\t",p.psex);
  		    fprintf(p1,"%s\t",p.ppno);
  		    fprintf(p1,"%s\n",p.pproblem);
    			found=1;
    		}
    		else
    		{
    			fprintf(p1,"%s\t",p.pname);
 		     fprintf(p1,"%d\t",p.p_id);
 		     fprintf(p1,"%d\t",p.age);
  		    fprintf(p1,"%s\t",p.psex);
  		    fprintf(p1,"%s\t",p.ppno);
  		    fprintf(p1,"%s\n",p.pproblem);
    		}
    		
		}
		if(found==0)
		printf("\n\nDAta not found\n\n");
    }
    fclose(p1);
     fclose(p2);
     remove("patientq.txt");
	rename("temp.txt","patientq.txt");
}

void del()
{
	struct patient p;
	FILE *p1,*p2;
	p1=fopen("temp.txt","a");
	p2=fopen("patientq.txt","r");
	
	if(p2==NULL)
        printf("file does not found");
    else
    {
		fscanf(p2,"%s",p.pname);
		fscanf(p2,"%d",&p.p_id);
		fscanf(p2,"%d",&p.age);
		fscanf(p2,"%s",p.psex);
		fscanf(p2,"%s",p.ppno);
		fscanf(p2,"%s",p.pproblem);
		
		printf("\n\nNext patient for check up\n\nName :%s \nPID:  %d\n\n",p.pname,p.p_id);
		
    	while((fscanf(p2,"%s",p.pname),fscanf(p2,"%d",&p.p_id),fscanf(p2,"%d",&p.age),fscanf(p2,"%s",p.psex),fscanf(p2,"%s",p.ppno),fscanf(p2,"%s",p.pproblem))==1)
    	{
    			fprintf(p1,"%s\t",p.pname);
 		     fprintf(p1,"%d\t",p.p_id);
 		     fprintf(p1,"%d\t",p.age);
  		    fprintf(p1,"%s\t",p.psex);
  		    fprintf(p1,"%s\t",p.ppno);
  		    fprintf(p1,"%s\n",p.pproblem);    		
		}
    }
    fclose(p1);
     fclose(p2);
     remove("patientq.txt");
	rename("temp.txt","patientq.txt");
}

int password(char a[25])																//password function
{
	char pwd[25], ch;
	int i=0;
	printf("Enter password : ");
	while (1) 
	{
		ch = getch();
		
		if (ch == 13)  																	//13 is ASCII value of ENTER
		{
			pwd[i]='\0';
			break;
		}
		
		if (ch == 8) 																	//8 is ASCII value of BACKSPACE
		{
			if(i==0)																	//when i=0 it will not accept BACKSPACE
			{
        		continue;
			}
			else
			{
				printf("\b \b");
        		i--;
        		continue;
			}			
    	}
    	pwd[i++] = ch;
    	printf("*");
   }
	if(strcmp(a,pwd)==0)
	return(1);
	else
	return(0);
}
 
int main()																				//main functon
{
	int n=1,ch;
	char pwd[10]={"rakesh"};
//	if(1)
      if(password(pwd))
	{
		while(n!=9)
		{
			system("cls");
			printf("****************************************************************************************************\n");
			//printf("*\n*\n*\n*\n*");
			printf("\t\t\t\tPATIENT MANAGEMENT\n");
			printf("****************************************************************************************************\n\n\n");
			printf("1: Add doctor profle\n");
			printf("2: New patient\n");
			printf("3: display patient in queue\n");
			printf("4: Patient record\n");
			printf("5: Search patient \n");
			printf("6: Modify patient details\n");
			printf("7: Display Doc details\n");
			printf("8: Next Patient\n");
			printf("9: Exit\n");
			printf("Enter choice : ");
			scanf("%d",&n);
			printf("\n\n");
			switch(n)
			{
				case 1 : 
					doc();
					break;
				case 2 : 
					printf("\n1: Emercency case \n2: Normal case\nEnter your choice : ");
					scanf("%d",&ch);
					if(ch==1)
					emer_patient();
					else
					patient();
					break;
				case 3 : 
					printf("\n\nName\tPatient ID\n\n");
					display_patient(1);
					break;
				case 4 : 
					printf("\n\nName\tID\tage\tsex\tpno\tProblem\n\n");
					display_patient(2);
					break;
				case 5 : 
					search_patient();
					break;
				case 6 : 
					modify();
					break;
				case 7 : 
					doc_display();
					break;
				case 8 : 
					del();
					break;
				case 9 : 
					printf("\nBye have a nice day\n");
					break;
				default:
					printf("\nInvalid\n");
			}
			getch();
		}
	}
	else
	printf("\nIncorrect Password ");
	getch();
	return 0 ;
}
