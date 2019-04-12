#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void GenerateCipherMatrix (char cipherMatrix[5][5], char key[25]){
	char control[25]={'*'};
	int ct=0,k=0;
	int i,j,ct1=0,ct3=0,p,z;
	char alf[26]="abcdefghiklmnopqrstuvwxyz";

	
	
	
	for(i=0;i<strlen(key);i++){
				for(j=0;j<25;j++){
					if(key[i]==control[j]){
						k++;
						
					}
					
					}
				if(k==0){
					control[ct1]=key[i];
					ct1++;
					k=0;
				}
				else{
					k=0;
				
				}
				
			
		}
		p=ct1;
		for(i=0;i<25;i++){
			for(j=0;j<25;j++){
				if(alf[i]==control[j]){
					ct3++;
				}
			}
			
			if(ct3==0){
				control[p]=alf[i];
				p++;
				ct3=0;
			}
			else{
				ct3=0;
			}
		}
		printf("Cipher Matrix is:\n\n\n");
		z=0;
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				
				cipherMatrix[i][j]=control[z];
				z++;
				
			}
		}
		
		}
	int InSameRow(char cipherMatrix[5][5],char firstLetter,char secondLetter){
	int yer1,yer2,yer3,yer4,i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(cipherMatrix[i][j]==firstLetter){
				yer1=i;
				yer2=j;
			}}}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(cipherMatrix[i][j]==secondLetter){
				yer3=i;
				yer4=j;
			}
		}
	}
	if(yer1==yer3){
		return(1);
	}
	else if(yer1!=yer3){
		return(0);
	}
	   
}
	
	
int InSameColumn(char cipherMatrix[5][5],char firstLetter,char secondLetter){
int yer1,yer2,yer3,yer4,i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(cipherMatrix[i][j]==firstLetter){
				yer1=i;
				yer2=j;}}}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(cipherMatrix[i][j]==secondLetter){
				yer3=i;
			    yer4=j;}}}
	if(yer2==yer4){
		 return(1);
	}
	else if(yer2!=yer4){
	return(0);	
	}
}
void GetColumn_RowIndex(char cipherMatrix[5][5],char letter, int *colIndex, int *rowIndex){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(cipherMatrix[i][j]==letter){
				*colIndex=i;
				*rowIndex=j; }}}}


int main(void){
	
	char key[25],cipherMatrix[5][5];
	int i,j;
	char sentence[100];
	int x=0;
	int o=0,b=0,ct1=0;
	int insamerow,insamecolumn,loc1,loc2,loc3,loc4,decision;
	int k,l;
	
	char a[200]={'\0'};
	
	


	

	
	
	printf("Enter the key phrase:");
	gets(key);
	
	GenerateCipherMatrix(cipherMatrix,key);
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				
				printf("   %c   ",cipherMatrix[i][j]);
			
				
			}
			printf("\n");
		}
			printf("Enter the sentence:");
		gets(sentence);
		
		
				 do{
	 	
		a[o]=sentence[b];
	 	o++;
	    ct1++;
	    if(ct1%2==0)
		if(ct1!=0){
	    	a[o]=' ';
	       o++;
		}
	      
		 
		if(sentence[b]==sentence[b+1])
		if( b%2==0){
	   	a[o]='x';
	   	o++;
	   	ct1++;
	   	
	      if(ct1%2==0)
		  if( ct1!=0){
	    	a[o]=' ';
	       o++;
		}
	    }
	
	   b++;
	   }while(sentence[b]!='\0'); 
	   
	     if(strlen(a)%3!=0){
	   	  b=strlen(a);
			 a[b]='q'; 
	   }
	  o=strlen(a);
	  printf("\nGrouped(digrammed) text is: ");
	  for(i=0;i<o;i++){
	  	printf("%c",a[i]);
	  	}



	
	printf("\n\nEnter 1 to encrypt or 2 to decrypt:");
	  	scanf("%d",&decision);
	  if(decision==1){
	  	for(i=0;i<o;i=i+3){
	  	 k=InSameRow(cipherMatrix,a[i],a[i+1]);
	  	 l=InSameColumn(cipherMatrix,a[i],a[i+1]);
	  	 
	  	 GetColumn_RowIndex(cipherMatrix,a[i],&loc1,&loc2);
	  	 GetColumn_RowIndex(cipherMatrix,a[i+1],&loc3,&loc4);
	  	
	  	 
	  	 if(k==0){
		    
		   if(l==0){
	  	 	a[i]=cipherMatrix[loc1][loc4];
	  	    a[i+1]=cipherMatrix[loc3][loc2];
		   }
		   
		   }
		 if(k==1){
		 	a[i]=cipherMatrix[loc1][(loc2+1)%5];
		 	a[i+1]=cipherMatrix[loc3][(loc4+1)%5];
		 }
		 if(l==1){
		 	a[i]=cipherMatrix[(loc1+1)%5][loc2];
		 	a[i+1]=cipherMatrix[(loc3+1)%5][loc4];
		}
	  	 }
	  	 printf("\nEncrypted text is: ");
	  }
	  if(decision==2){
	  	for(i=0;i<o;i=i+3){
	  	 k=InSameRow(cipherMatrix,a[i],a[i+1]);
	  	 l=InSameColumn(cipherMatrix,a[i],a[i+1]);
	  	 
	  	 GetColumn_RowIndex(cipherMatrix,a[i],&loc2,&loc1);
	  	 GetColumn_RowIndex(cipherMatrix,a[i+1],&loc4,&loc3);
	  	
	  	 
	  	 if(k==0){
		   if(l==0){
	  	 	a[i]=cipherMatrix[loc1][loc4];
	  	 	a[i+1]=cipherMatrix[loc3][loc2];
		   }
		    
		   }
		 if(k==1){
			 a[i]=cipherMatrix[loc1][(loc2-1)%5];
		 	a[i+1]=cipherMatrix[loc3][(loc4-1)%5];
		 }
		 if(l==1){
		 a[i]=cipherMatrix[(loc1-1)%5][loc2];
		 	a[i+1]=cipherMatrix[(loc3-1)%5][loc4];
		}
	  	 }
	  	 printf("\nDecrypted text is: ");
	  	 	
	  }
	    
	  	puts(a);
	   
	return(0);
}

