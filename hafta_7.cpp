#include<iostream>
#define PAGE_SIZE 1024
#define PAGE_COUNT 4
int main(void){
	 int page_table[PAGE_COUNT]={3,1,-1,2};
	 int addresses[]={1500,2500,3500,5000};
	 int count=sizeof(addresses)/sizeof(addresses[0]);
	 
	 for (int i=0;i<count;i++){
	 	int address=addresses[i];
	 	printf("Sanal adres:%d\n",address);
	 	
	 	if(address<0 || address >=PAGE_COUNT * PAGE_SIZE){
	 		printf("Gecersiz sanal adres.\n\n");
	 		continue;
		 }
		 int page=address/PAGE_SIZE;
		 int offset=address%PAGE_SIZE;
		 int frame=page_table[page];
		 printf("Sayfa:%d,Ofset:%d\n",page,offset);
		 
		 if(frame==-1){
		 	printf("Page fault:sayfa RAM'de yok.\n\n");
		 	continue;
		 }
		 int physical=frame*PAGE_SIZE+offset;
		 printf("Cerceve:%d,Fiziksel adres:%d\n\n",frame,physical);
	 }
	 return 0;
}
