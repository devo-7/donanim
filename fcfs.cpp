#include<iostream>
int main(){
	//FCFS tam kodu
	int n=4;
	int pid[]={1,2,3};
	int at[]={0,1,2,3};
	int bt[]={5,3,8,6};
	
	int wt[4],tat[4],ct[4];
	int zaman=0;
	
	for (int i=0;i<n;i++){
		if(zaman<at[i])
			zaman=at[i];
			
		wt[i]=zaman-at[i];
		zaman+=bt[i];
			
		ct[i]=zaman;
		tat[i]=ct[i]-at[i];	
	}
	printf("PID\tAT\tBT\tWT\tCT\tTAT\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],wt[i],ct[i],tat[i]);
		return 0;
	}
}
