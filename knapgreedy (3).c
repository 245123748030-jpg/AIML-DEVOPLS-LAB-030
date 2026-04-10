#include<stdio.h>
void knapsack(int n,float weight[],float profit[],int capacity)
{
	float x[20],tp=0;
	int i,j;
	float u;
	u=capacity;
	for(i=0;i<n;i++)
		x[i]=0.0;
	for(i=0;i<n;i++)
	{
		if(weight[i]>u)
			break;
		else
		{
			x[i]=1.0;
			tp=tp+profit[i];
			u=u-weight[i];
		}
	}
	if(i<n)
	{
		x[i]=(u/weight[i]);
		tp=tp+(x[i]*profit[i]);
	}
	printf("\nthe result vector is \n");
	for(i=0;i<n;i++)
		printf("%f\t",x[i]);
	printf("\nmaximum profit is : %f",tp);
}
int main()
{
	float weight[20],profit[20],capacity;
	int num,i,j;
	float ratio[20],temp;
	printf("\nenter the no.of objects: ");
	scanf("%d",&num);
	printf("\nenter the weights of %d objects: ",num);
	for(i=0;i<num;i++)
		scanf("%f",&weight[i]);
	printf("\nenter profits of %d objects: ",num);
	for(i=0;i<num;i++)
		scanf("%f",&profit[i]);
	printf("\nenter capacity of knapsack");
	scanf("%f",&capacity);
	for(i=0;i<num;i++)
		ratio[i]=profit[i]/weight[i];
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(ratio[j]<ratio[j+1])
			{
				temp=ratio[j];
				ratio[j]=ratio[j+1];
				ratio[j+1]=temp;

				temp=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=temp;
				
				temp=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;
			}
		}
	}
	knapsack(num,weight,profit,capacity);
	printf("\n");
	return 0;
}


