#include<iostream>
using namespace std; 
int main()
{
    int burst_time[20],process[20],waiting_time[20],tat[20],i,j,n,total=0,pos,temp;
    float wait_avg,TAT_avg;
  cout<<"Enter number of process: ";
    cin>>n;
   cout<<"Enter Burst time: ";
for(i=0;i<n;i++)
    {
       cout<<"Process["<<i+1<<"]: ";
       cin>>burst_time[i];
        process[i]=i+1;          
    }
   for(i=0;i<n;i++)
    {
        pos=i;
for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
         temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
        temp=process[i];
process[i]=process[pos];
        process[pos]=temp;
      }
     waiting_time[0]=0;           
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
      total+=waiting_time[i];
    }
      wait_avg=(float)total/n;
      total=0;
  cout<<"\nProcess\t    \nBurst Time\t    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+waiting_time[i];  
        total+=tat[i];
cout<<"\n"<<process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<tat[i];
    }
   TAT_avg=(float)total/n;    
   cout<<"\n\nAverage Waiting Time is : "<<wait_avg;
    cout<<"\nAverage Turnaround Time is: "<<TAT_avg;
}

