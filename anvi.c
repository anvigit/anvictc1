#include<stdlib.h>
#include<stdio.h>
#include<unitstd.h>
struct process
{
int pid,bt,wt,tt;
}p[10];

int main()
{
int totwt=0,tottt=0;
float avgtt=0.0,avgwt=0.0;
int n,i;
int t=0,q,done=1;
printf("Enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i].pid=i+1;
printf("enter burst time for %d process",i+1);
scanf("%d",&p[i].bt);
}
int rembt[n];
for(i=0;i<n;i++)
{
rembt[i]=p[i].bt;
}
printf("Enter quantum time:");
scanf("%d",&q);


while(1)
{
done=1;
for(i=0;i<n;i++)
{
if(rembt[i]>0)
{
done=0;
if(rembt[i]>q)
{
t=t+q;
rembt[i]=rembt[i]-t;
}
else
{
t=t+rembt[i];
rembt[i]=0;
p[i].tt=t;
p[i].wt=p[i].tt-p[i].bt;
}
}
}
if(done==1)
{
break;
}
}
i=0;
while(i<n)
{
totwt=totwt+p[i].wt;
tottt=totwt+p[i].tt;
i++;
}
printf("\nprocess\tbt\twt\ttt\n.........................\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\n",i+1,p[i].bt,p[i].wt,p[i].tt);
}
avgwt=totwt/n;
avgtt=tottt/n;
printf("avg waiting time:%f\n",avgwt);
printf("avg turnaround time:%f\n",avgtt);
}
