#include<stdio.h>
#include<conio.h>
int head,a[20],range,n;
void fcfs()
{
int headm=0,temp,i;
for(i=0;i<n;i++)
{
if(i==0)
{
if(a[i]<head)
headm=headm+(head-a[i]);
else
headm=headm+(a[i]-head);
}
else
{
if(a[i-1]<a[i])
headm=headm+(a[i]-a[i-1]);
else
headm=headm+(a[i-1]-a[i]);
}
printf("%d->",a[i]);
}
printf("\nFCFS-Total head movement=%d\n",headm);
}
void scan()
{
int headm=0,i,dir,temp,cnt=0;
printf("\nEnter the direction, upward/right=1, downward/left=-1:");
scanf("%d",&dir);
if(dir==1)
{
for(i=0;i<n;i++)
{
if(a[i]<head)
{
cnt++;
continue;
}
else if(i==cnt)
headm=headm+(a[i]-head);
else
headm=headm+(a[i]-a[i-1]);
printf("%d->",a[i]);
}
headm=headm+(range-a[i-1]);
printf("%d->",range);
headm+=(range-a[cnt-1]);
printf("%d->",a[cnt-1]);
for(i=cnt-1;i>0;i--)
{
headm+=(a[i]-a[i-1]);
printf("%d->",a[i-1]);
}
}
else
{
for(i=0;i<n;i++)
{
if(a[i]>head)
break;
else
cnt++;
}
headm+=(head-a[cnt-1]);
printf("%d->",a[cnt-1]);
for(i=cnt-1;i>0;i--)
{
headm+=(a[i]-a[i-1]);
printf("%d->",a[i-1]);
}
headm+=(a[0]-0);
printf("0");
headm+=(a[cnt]-0);
for(i=cnt;i<n-1;i++)
{
headm+=(a[i+1]-a[i]);
printf("%d->",a[i]);
}
}
printf("\nSCAN-Total head movement=%d\n",headm);

}
void cscan()
{
int headm=0,i,dir,temp,cnt=0;
printf("\nEnter the direction, upward/right=1, downward/left=-1:");
scanf("%d",&dir);
if(dir==1)
{
for(i=0;i<n;i++)
{
if(a[i]<head)
{
cnt++;
continue;
}
else if(i==cnt)
headm=headm+(a[i]-head);
else
headm=headm+(a[i]-a[i-1]);
printf("%d->",a[i]);
}
headm=headm+(range-a[i-1]);
headm+=(a[0]-0);
printf("%d->",a[0]);
for(i=1;i<cnt;i++)
{
headm+=(a[i]-a[i-1]);
printf("%d->",a[i]);
}

}
else
{
for(i=0;i<n;i++)
{
if(a[i]>head)
break;
else
cnt++;
}
headm+=(head-a[cnt-1]);
printf("%d->",a[cnt-1]);
for(i=cnt-1;i>0;i--)
{
headm+=(a[i]-a[i-1]);
printf("%d->",a[i-1]);
}
headm+=(a[0]-0);
printf("%d->",a[0])
headm=headm+(range-a[i]);
for(i=n-1;i>=cnt;i--)
{
headm+=(a[i]-a[i-1]);
printf("%d->",a[i]);
}


}
printf("\nCSCAN-Total head movement=%d\n",headm);

}
void main()
{
int i,j,temp;
printf("\nEnter the total range of cylinders:");
scanf("%d",&range);
printf("\nEnter the number of cylinders:");
scanf("%d",&n);
printf("\nEnter the cylinder numbers:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\nEnter the header:");
scanf("%d",&head);
fcfs();
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
scan();
cscan();
}

