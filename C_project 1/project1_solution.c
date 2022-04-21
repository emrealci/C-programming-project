#include<stdio.h>

int askFirstQuestion()
{
   printf("1) Please enter your birthday between 1 and 7(example Mon=1, Tue=2..):\n");
   int num1;
   while(1)
   {
       scanf("%d",&num1);
       if(num1>=1 && num1<=7){
           printf("%d\n",num1);
           return num1;
   }
       else {
           printf("%d\n",num1);
           printf("Please enter an appropriate day!\n");
    }
    }
}

int askSecondQuestion()
{
     printf("Enter initial letter of your name, (capital english letters only)\n");
     char ch;
     int buffer1;
     while(1){
    	 scanf("%c",&ch);
    	 if(ch>='A' && ch<='Z'){
    	     buffer1=ch-64;
    	     buffer1=(buffer1)%4;
             printf("%c --> ",ch);
             printf("%d\n",buffer1);
             return buffer1;	
		}
	}
}
int askThirdQuestion(int result1,int result2)
{
	
	
    printf("2) What is the %dth power of %d?\n",result1,result2);
    int i,j,k;
    int x;
    int buffer2=1;
    int count=1; // 2 yi kabul etik burada , ve ileride 3 ten baþlýacaðýz
    for (i=0;i<result1;i++){
	
        buffer2=buffer2*result2;
}
    int sonucne;
	
    while(1){
        scanf("%d",&sonucne);
        if(sonucne==buffer2){
            printf("%d\n",buffer2);
	    break;
         }
         else{
	    printf("%d\n",sonucne);
	    printf("It is not correct!\n");
          }
          }

    printf("3) How many prime numbers can you count until %d?\n",buffer2);
    int flag=0;
	
    if(buffer2==0 || buffer2==1){
        count=0;
      }
    else{
        for(j=3;j<=buffer2;j++){
    	    for(k=2;k<j;k++){
    	        if (j%k==0){
    		   flag=0;
    		   break;
		}
		else{
		    flag=1;
		 }
	     }
	     if(flag==1){
	         count=count+1;
	     }
    	}
}

    while(1){
        scanf("%d",&x);
        if(x!=count){
            printf("%d\n",x);
            printf("It is not correct!\n");
            continue;
        }
        else if(x==count) {	
	    printf("%d\n",count);
	    break;
        }
        }
        return count;
}

int askFourthQuestion(int result3)
{   // 9 oldugunu düsün  0 1 1 2 3 5 8 13 21 34   ve 34 döndürecek
	
    int m;
    int first_Number=0;
    int second_Number=1;
    int buffer3;
    if(result3!=0){
        for(m=0;m<=result3-2;m++){
	     buffer3=first_Number;
	     first_Number=second_Number;
	     second_Number=buffer3+second_Number;
	
         }
    }
    else{
        second_Number=0;
    }
    printf("4) Enter %dth element of the Fibonacci series:\n",result3);
    int prime;
    while(1){
        scanf("%d",&prime);
        if(prime!=second_Number){
            printf("%d\n",prime);
	    printf("It is not correct!\n");
	 	 		
     }
         else {
	    printf("%d\n",second_Number);
	    return second_Number;
     }
}
	 
}
int askFifthQuestion(int result4){
    printf("Enter your age(between 1-100):\n");
    int age;
    scanf("%d",&age);
    printf("%d\n",age);
    printf("5) What is the result of %d * %d?\n",result4,age);
    while(1){
        int whatis;
        scanf("%d",&whatis);
        if(whatis!=result4*age){
	    printf("%d\n",whatis);
            printf("It is not correct!\n");
     }
         else{
             printf("%d\n",result4*age);
             printf("Congratulations! You found the code! The code is %d\n",result4*age);
	     break;
	    }
	    }
         return 1;
}

int main()
{
	int result1;
	int result2;
	int result3;
	int result4;
	
	
       result1=askFirstQuestion();  //result1 == num1
       result2=askSecondQuestion(); //result2== buffer1
       result3=askThirdQuestion(result1,result2);
       result4=askFourthQuestion(result3);
       askFifthQuestion(result4);
}
