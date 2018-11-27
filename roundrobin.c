//3. Priority Scheduling Algorithm Program
//PROGRAM FOR PRIORITY CPU SCHEDULING ALGORITHM" WITH NO-PRE_EMPTION & ARRIVAL TIMES
#include<stdio.h>
#include<string.h>
int main(void)
{
    //VARIABLE DECLARATION
    char pn[20][20], c[20][20]; //PN-PROGRAM NAMES C-A TEMPORARY ARRAY
    int n,i,j,at[20], bt[20], pt[20], wt[20],ct[20],tat[20];
    //bt-BURST TIME ;pt-PRIORITY;wt-WAITING TIME; tat-TURN AROUND TIME
    int temp1, temp2, temp3, count=0,twt=0;//,tat=0;
    printf("Enter number of processes:");
    scanf("%d", &n);
    printf("Enter <ProcessName> <ArrivalTime> <BurstTime> <Priority> :\n");
    //TAKING INPUT VALUES i.e., PROCESS-NAMES, ARRIVAL-TIMES AND BURST-
    TIMES

    for(i=0; i<n; i++)
        scanf("%s%d%d%d",&pn[i],&at[i],&bt[i],&pt[i]);
    //SCHEDULING THE PROCESSES ACCORDING TO SJF
    for(i=0 ; i<n; i++)
    {
        for(j=i+1; j<n; j++)

                //IF THERE IS NO PROCESS IN MAIN MEMORY,
                //SORT PROCESSES ACCORDING TO ARRIVAL TIMES &
                //IF WE GOT PROCESSES WITH SAME ARRIVAL TIME SORT THEM BY PRIORITY

            if ( ((i==0||count<1)&&(at[i]>at[j]||(at[i]==at[j]&&pt[i]>pt[j])) )
                    //IF WE GOT ONLY ONE PROCESS IN MAIN MEMORY AFTER COMPLETION OF THE CURRENT PROCESS
                || (count == 1 && ct[i-1]>=at[j])
            
                    //IF WE GOT MORE THAN ONE PROCESS IN MAIN MEMORY, SORT THEM BY PRIORITY
                || ((ct[i-1]>=at[j]&&pt[i]>pt[j]))// || (ct[i-1]<at[i]&&ct[i-1]>=at[j]))
                )
            //SWAPPING PROCESSES
            {
                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
                temp2 = at[i];
                at[i] = at[j];
                at[j] = temp2;
                temp3 = pt[i];
                pt[i] = pt[j];
                pt[j] = temp3;
                strcpy(c[i],pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],c[i]);
            }

        if(i==0 || count<1)
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
        wt[i] = ct[i] - (at[i] + bt[i]);
        tat[i] = ct[i] - at[i];
        count = 0 ;
        for(j=i+1; j<n; j++)
            if(ct[i]>=at[j])
                count++;
    }

    //PRINTING THE VALUES AFTER ALL PREOCESSES COMPLETED
    printf("S.N.\tPN\tAT\tBT\tPri\tCT\tWT\tTAT\n");
    for(i=0; i<n; i++)
    printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),pn[i],at[i],bt[i],pt[i],ct[i],wt[i],tat[i
    ]);
} //END OF MAIN