#include<stdio.h>


int main()
{
    int number;
    scanf("%d",&number);
    if (number<0){
        printf("Please enter an upper bound: %d\n",number);
        printf("Upper bound can not be negative.");
    }
    else if (number>=0 && number<=100){
        
        printf("Please enter an upper bound: %d\n",number);
        printf("There are 0 ultra magic numbers up to %d. ",number);
    }
    else{
        printf("Please enter an upper bound: %d\n",number);
        int m=100;
        int value=0;
        while(m<number) {
	
            int count=-1;
            int j;
    	    int sayac=0;
            int buffer,buffer1,buffer2;
      
           buffer=m;
           buffer1=m;
           buffer2=m;

           while(buffer>0){
    	
              buffer=buffer/10;
              count=count+1;
            }
     
          int arr[count];
          int arr2[count];
     
         while(buffer1>0){
    	    buffer2=buffer1%10;
    	    arr[sayac]=buffer2;
    	    sayac=sayac+1;
           buffer1=buffer1/10;
         }
        for(j=0;j<=count;j++){
            arr2[j]=arr[count-j];
    }
    
        int A=0;
        int B;
		 
        for(B=0;B<=count;B++){
            if( arr2[B]==arr[B]){
	 	A=A+1;
	     }
	}
		 
       if( A==(count+1) && arr[0] != arr[1]) {
	    printf("%d ",m);
	    value=value+1;
	    if(value%9==0){
	    printf("\n");
	    }
        }		 						
	m++;

}
    printf("\n");
    printf("There are %d ultra magic numbers up to %d.",value,number);
}
}
