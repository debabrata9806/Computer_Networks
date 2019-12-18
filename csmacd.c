#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void delay(int );
int bk(int );

void main()
{
	int i,n1,n2,t,e1=0,e2=0;
	int m1=-1,m2=-1,n; //acknowledgement identifier
	char a1[20],a2[20],b1[20],b2[20];
	for(i=0;i<20;i++)
	{
		a2[i]='\0';
		b2[i]='\0';		
		
	}
	int k1=0,k11=0,k2=0,k22=0,c,l=0;
	clock_t start,stop;
	printf("\n----CSMA--CD---");
	printf("\n----USING 2 WORK STATIONS----");
	
	printf("\nENTER THE DATA TO BE SEND BY FIRST SENDER::");
	scanf("%s",a1);
	
	printf("\nENTER THE DATA TO BE SEND BY SECOND SENDER::");
	scanf("%s",b1);
	
	printf("\nENTER THE FRAME SIZE::");
	scanf("%d",&n);
	char cc[n];
	
	



	while((a1[k1] != '\0') || (b1[k2] != '\0') )
	{
		
		c=rand()%2;
		if(c==0 )
		{
			if(a1[k1]=='\0')
			{

				goto label1;
			}
			
			if(m1==0)
			{
				if(t>0.1)
					{
						printf("\n\nACKNOWLEDGEMENT NOT RECEIVED..! (A)");
						printf("\n\nSENDING JAM SIGNAL...........!");
						printf("\n\nTRANSMISSION SUSPENDED FOR UNDEFINED PERIOD....!");
						delay(10000); //JAMMING DELAY
						printf("\n---RESTORING NETWORK----");
						printf("\nINCREMENT IN BACK OFF TIME....! (A)");
						delay(8000); //transmission delay to avoid collission
						delay(bk(e1)); //increment in backoff time
						e1++; //INCREMENT IN BACKOFF TIME
					}
				else
					printf("\n\nAcknowledgement Received...(Sender A)");
			}
			
			printf("\n\n--STARTING TRANSMISSION FROM A--");
			start=clock();
			m1=1; //receiver variable
			
			n2=0;
			while(n2<n) //sending frame
			{
				if(a1[k1]=='\0')
				{

					goto label3;
				}
					cc[n2]=a1[k1]; //partial array for creating frame
					k1++;
					n2++;
					
			}
			label3 :
			printf("\nWaiting For Acknowledgement...(A)");
			delay(1000);
			printf("\n--TRANSMISSION FROM B  ABORTED--");
			
			goto label1;
		}
		
		if(c==1)
		{
			if(b1[k2]=='\0')
			{

				goto label1;
			}
			if(m2==0)
			{
				if(t>0.1)
					{
						printf("\n\nACKNOWLEDGEMENT NOT RECEIVED..! (B)");
						printf("\n\nSENDING JAM SIGNAL...........!");
						printf("\n\nTRANSMISSION SUSPENDED FOR UNDEFINED PERIOD....!");
						delay(10000); //JAMMING DELAY
						printf("\n---RESTORING NETWORK----");
						printf("\nINCREMENT IN BACK OFF TIME....!(B)");
						delay(8000); //transmission delay to avoid collission
						delay(bk(e2)); //increment in backoff time
						e2++; //INCREMENT IN BACKOFF TIME
					}
				else
					printf("\n\nAcknowledgement Received...(Sender B)");
			}
			printf("\n\n--STARTING TRANSMISSION FROM B--");
			start=clock();
			m2=1; //receiver variable
			
			n2=0;
			while(n2<n) //sending frame
			{
				if(b1[k2]=='\0')
				{

					goto label2;
				}
					cc[n2]=b1[k2]; //partial array for creating frame
					k2++;
					n2++;
					
			}
			
			label2 :
			printf("\nWaiting For Acknowledgement...(B)");

			
			delay(1000);
			printf("\n--TRANSMISSION FROM A IS ABORTED--");
		
			goto label1;
		}

		


	label1 :
		 l=l+1;
		 if(m1==1) //receiver side of A
		 {
			 n1=0; //frame length var
			
			 while(n2>0)
			 {
				 a2[k11]=cc[n1];
				 k11++;
				 n1++;
				 n2--;
			 }
			
			 
			 printf("\nData received...sending acknowledgement...(receiver A)");
			  stop=clock();
			 t=((double)(stop - start))/CLOCKS_PER_SEC;

			 m1=0;
		 }

		 if(m2==1) //receiver side of A
		 {
			 n1=0; //frame length var
			
			 while(n2>0)
			 {
				 b2[k22]=cc[n1];
				 k22++;
				 n1++;
				 n2--;
			 }
			
			 
			 printf("\nData received...sending acknowledgement...(receiver B)");
			
			 stop=clock();
			 t=((double)(stop - start))/CLOCKS_PER_SEC; //calculation of backoff time

			 m2=0;
		 }
			 
	}

	if(m1==0)
	{

		printf("\n\nAcknowledgement Received...(Sender A)");
		printf("\n\n***TRANSMISSION FROM A COMPLETED***");
					
	}
	 if(m2==0)
	{
		
		printf("\n\nAcknowledgement Received...(Sender B)");
		printf("\n\n***TRANSMISSION FROM B COMPLETED***");
					
	}
	
		
	printf("\n\n--TANSMISSION COMPLETED--");
	printf("\nDATA RECEIVED BY 1ST RECEIVER::%s",a2);

	
	printf("\nDATA RECEIVED BY 2nd RECEIVER::%s",b2);


	

}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int bk(int n1) //calculation for backoff time
{
	int a=1;
	
	while(n1>0)
	{
		a=a*2;
		n1--;
	}
	a=a-1;
	return a;
}