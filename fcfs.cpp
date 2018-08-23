#include<iostream> //first come first serve
using namespace std;
 
int main()
{
    int n,at[20], bt[20],wt[20],ct[20],tat[20],avgwt=0,avgtat=0,i;
    cout<<"Enter total number of processes:";
    cin>>n;
 
  
    for(i=0;i<n;i++)
    {
	cout<<"\nEnter Arrival Time of process\n";
     cin>>at[i];
         cout<<"\nEnter Process Burst Time\n";
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
 ct[0]=bt[0];
     
    for(i=0;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];//completion time
    }
     
           
    for(i=0;i<n;i++)
    tat[i]=ct[i]-at[i];//turn around time
    
    
    for(i=0;i<n;i++)
    wt[i]=tat[i]-bt[i];//waiting time
    
    cout<<"\nProcess\t\t Burst Time\t Waiting Time\t Turnaround Time";
 
    
    for(i=0;i<n;i++)
    {

        avgwt= avgwt + wt[i];
        avgtat= avgtat + tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
 
    avgwt= avgwt/i;
    avgtat= avgtat/i;
    cout<<"\n\nAverage Waiting Time:"<<avgwt;
    cout<<"\nAverage Turnaround Time:"<<avgtat;
 
    return 0;
}


