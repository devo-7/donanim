#include<iostream>
void degistir(int *a,int *b){
	int gecici=*a;
	*a=*b;
	*b=gecici;
}
int main(){
	int pid[]={1,2,3,4};
	int bt[]={6,8,7,3};
	int n=4;
	int wt[4],tat[4];
	
	for(int i=0;i<n-1;i++){
		int min=i;
		for (int j=i+1;j<n;j++)
			if(bt[j]<bt[min])
				min=j;
		degistir(&bt[i],&bt[min]);
		degistir(&pid[i],&pid[min]);
	}
	wt[0]=0;
	
	for(int i=0;i<n;i++)
		wt[i]=wt[i]-1+bt[i-1];
		
	for(int i=0;i<n;i++)
		tat[i]=wt[i]+bt[i];
	printf("PID\tBT\tWT\tTAT\n");
	
	for(int i=0;i<n;i++)
		printf("P%d\t%d\t%d\t%d",pid[i],bt[i],wt[i],tat[i]);
	return 0;
	
}
