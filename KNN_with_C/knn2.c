/*K NEAREST NEIGHBOUR ALGORITHM EXAMPLE*/

#include<stdio.h>
#include<conio.h>
#define n 90
#include<math.h>
#define k 90
#define w 35

struct boolean1
{
	int no;
	int n1;
	int n2;
	char c[20];
};

struct boolean2
{
	int no;
	float dis;
};

/*Find Euclidean Distance between trainning data set and testing data set*/
float dist(int p1,int p2,int t1,int t2)
{
	
	float r;
	int i;
	r=sqrt(pow((t1-p1),2)+pow((t2-p2),2));
	return (r);
}


/*A function that sorts a list of array*/	
void bubblesort(float a[],int no)
{
	int c,d;
	float t;
	for (c=1;c<=no;c++)
	{
		for(d=1;d<=no-c;d++)
		{
			if(a[d]>a[d+1])
			{
				t=a[d];
				a[d]=a[d+1];
				a[d+1]=t;
			}
		}
	}

}
	


int main()
{
	FILE *fp,*fp1,*fp2;
	int i,j,r,min,l,count_f=0,count_p=0,count_v=0;
	float distance[100];
	struct boolean1 a[100],t[50];
	struct boolean2 s[100];
	fp=fopen("inputfruit.txt","r");
	if(fp==NULL)
	{
		printf("\nError,Cannot open file.");
		//exit(1);
	}
	printf("\n");
	for (i=1;i<=n;i++)
	{
		fscanf(fp,"%d %d %d %s[^\n]",&a[i].no,&a[i].n1,&a[i].n2,a[i].c);
		//printf("%d %d %d %s \n",a[i].no,a[i].n1,a[i].n2,a[i].c);
	}
	
	
fclose(fp);

fp1=fopen("test_fruit.txt","r");
if(fp1==NULL)
{
	printf("\nError, Can't read file.");
}
else
{
	printf("\t\t\t\t\t   K NEAREST NEIGHBOUR ALGORITHM EXAMPLE \t\t\t\t\t");
	printf("\t\t\t\t\t\t   ------------------------------------- \t\t\t\t\t");
	printf("\n\n\nEnter the testing data point which class is to be calculated:\n");
	for(i=1;i<=w;i++)
	{
		fscanf(fp1,"%d %d[^n]",&t[i].n1,&t[i].n2);
		//scanf("%d %d",&t1.n1,&t1.n2);
		//printf("\n %d %d\n",t[i].n1,t[i].n2);	
	}
	
}
fclose(fp1);
fp2=fopen("Output_fruit.txt","w");
for(r=1;r<=w;r++)
{
	count_f=0;
	count_v=0;
	count_p=0;	
	for(i=1;i<=n;i++)
	{
		distance[i]=(dist(a[i].n1,a[i].n2,t[r].n1,t[r].n2));
		
		s[i].dis=distance[i];
		s[i].no=i;
	}
	/*for(i=1;i<=n;i++)
		printf("\n %.4g",distance[i]);*/
	//printf(" %.2g",distance[i]);
	bubblesort(distance,n);
	/*for(i=1;i<=k;i++)
		printf("\n %.2g",(float)distance[i]);*/
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
	 	{
			//printf(" %.2g",(float)s[j].dis);
			if(distance[i]==s[j].dis)
			{
				l=s[j].no;
				//printf("\n%d",s[j].no);			
				if(strcmp(a[l].c,"fruit")==0)
				{
					count_f=count_f+1;
				}
				if(strcmp(a[l].c,"protein")==0)
					count_p=count_p+1;
				if(strcmp(a[l].c,"vegetable")==0)
					count_v=count_v+1;
				
			}
				
		}
	
	}

		//printf("\nThe no of fruit counted %d",count_f);
		//printf("\nThe no of protein counted %d",count_p);
		//printf("\nThe no of veg counted %d",count_v);
		//fp2=fopen("Output_fruit.txt","w");
		if(count_f>count_p&&count_f>count_v)
		{
			printf("\nX(P1=%d,P2=%d) belongs to class = %s",t[r].n1,t[r].n2,"fruit");
			printf("\n");
			fprintf(fp2,"%d\t%d\t",t[r].n1,t[r].n2);
			fprintf(fp2,"Fruit");
			fprintf(fp2,"\n");
			
		}
		
		else if(count_p>count_v&&count_p>count_f)
		{
			printf("\nX(P1=%d,P2=%d) belongs to class = %s",t[r].n1,t[r].n2,"protein");
			printf("\n");
			fprintf(fp2,"%d\t%d\t",t[r].n1,t[r].n2);
			fprintf(fp2,"Protein");
			fprintf(fp2,"\n");
		
		}
		else
		{
			printf("\nX(P1=%d,P2=%d) belongs to class = %s",t[r].n1,t[r].n2,"vegetable");
			printf("\n");
			fprintf(fp2,"%d\t%d\t",t[r].n1,t[r].n2);
			fprintf(fp2,"Vegetable");
			fprintf(fp2,"\n");
		}	
		
		
}
fclose(fp2);

getch();
return 0;
}
