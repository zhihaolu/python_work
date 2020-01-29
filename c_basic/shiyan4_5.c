
#include<stdio.h> 

int main(){
	char ch;
	int space=0,number=0,character=0,other=0;
	ch=getchar();                      
	while(ch!='\n'){                   
		if(ch==' '){  				  	
			space++;
		}
		else if(ch>='0'&&ch<='9'){     
			number++;
		}
		else if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'){  
			character++; 
		}
		else{
			other++;
		}
		ch=getchar();
	}
	printf("%d %d %d %d",character,number,space,other);
	return 0;
}

