//1. Shortest Job First With Preemption Program
//PROGRAM FOR SHORTEST-JOB-FIRST(SJF) "CPU SCHEDULING ALGORITHM"
//WITH PRE_EMPTION

#include<stdio.h>
#include<conio.h>
int main()
{
    int n,at[10], bt[10], ct[10], wt[10], tn =0, c, ta[10],tat[10];
    //at-ArritvalTime::br-BurstTime::ct-CompletionTime::ta-TemporaryArray
    //wt-WaitingTime::tat-TurnAroundTime::tn-CurrentTime(TimeNow)
    // int i, j, k, tot, pc=0, pointer = 0, lp=-1;//lp-Last-executedProcess
    int i, k, tot, pc=0, pointer = 0, lp=-1;//lp-Last-executedProcess
    char pn[10][10];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter <ProcessName> <ArrivalTime> <BurstTime>\n");
    
    for(i=0;i<n;i++)
        scanf("%s%d%d",&pn[i],&at[i],&bt[i]);

    for(i=0; i<n; i++)
    {
        ct[i] = -1;
        ta[i] = bt[i];
    }
    while(pc!=n)
    {
        k=0;
        c = 0;
        for(i=0; i<n; i++)
        {
            if(ct[i]<0 && at[i]<=tn)
                c++;
        }
        if(c==0)
            tn++;
        else
        {
            pointer = 0;
            while(at[pointer]>tn || ct[pointer]>0)
            pointer++;
            for(k=pointer+1; k<n; k++)
                if( (at[k]<=tn && ct[k]<0) &&
                    ( (bt[pointer]==bt[k] && k==lp) || bt[pointer]>bt[k] ) )
                
                    pointer = k;

            if(ct[pointer]<0)
            {
                bt[pointer]--;
                tn++;
                if(bt[pointer]==0)
                {
                    ct[pointer] = tn;
                    wt[pointer] = ct[pointer] - ( at[pointer]+ ta[pointer] );
                    tat[pointer] = ct[pointer] - at[pointer];
                    pc++;
                }
            }
            lp = pointer;
        }
    }
    printf("\nPN\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",pn[i],at[i],ta[i],ct[i],wt[i],tat[i]);
    return 0;
}


output refer pic 1

//2. Round Robin Scheduling Algorithm Program
//PROGRAM FOR ROUND ROBIN "CPU SCHEDULING ALGORITHM" WITH ARRIVAL TIMES
#include<stdio.h>
#include<string.h>
int main(void)
{
    //VARIABLE DECLARATION
    char pn[20][20], c[20][20]; //PN-PROGRAM NAMES
    int n,i,j,k,l, tq, at[20], bt[20], rbt[20], wt[20],tt[20],ct[20]; 
    //bt-BURST TIME ; wt-WAITING TIME; tat-TURN AROUND TIME
    int temp1, temp2, temp3, count=0,twt=0, tn;//,tat=0;
    printf("Enter <Number_of_Processes & Time_Quantum:\n");
    scanf("%d%d", &n, &tq);
    printf("Enter PN, AT, BT:\n");
    //TAKING INPUT VALUES i.e., PROCESS-NAMES, ARRIVAL-TIMES, BURST-TIMES
    for(i=0; i<n; i++)
        scanf("%s%d%d",&pn[i],&at[i],&bt[i]);
    for(i=0; i<n; i++)
        rbt[i]=bt[i];
    //SCHEDULING THE PROCESSES ACCORDING TO SJF
    for(i=0;i<n;i++)
    {
        for(j=i+1; j<n;j++)
        {
            //SORTING BASED ON ARRIVAL TIMES
            if(at[i]>at[j])
            {
                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
                temp2 = at[i];
                at[i] = at[j];
                at[j] = temp2;
                temp3 = rbt[i];
                rbt[i] = rbt[j];
                rbt[j] = temp3;
                strcpy(c[i],pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],c[i]);
            }
        }//END OF J FOR-LOOP
    }//END OF I FOR-LOOP

    tn = at[0];
    label:
    for(i=0; i<n; i++)
    {
        if(at[i]>tn) i--;
            if(rbt[i]>0)
            {
                if(rbt[i]>tq)
                {
                    tn += tq;
                    rbt[i] -= tq;
                }
                else
                {
                    tn += rbt[i];
                    rbt[i] = 0;
                    ct[i] = tn;
                    count++;
                }
            }
    }
    if(count<n) goto label;
    //CALCULATING WAITING TIME & TAT

    for(i=0;i<n;i++)
    {
        wt[i] = ct[i]-at[i]-bt[i];
        twt += wt[i];
    }
    //PRINTING THE VALUES AFTER ALL PREOCESSES COMPLETED
    printf("S.N.\tPN\tAT\tBT\tCT\tWT\n");
    for(i=0; i<n; i++)
    printf("%d\t%s\t%d\t%d\t%d\t%d\n",(i+1),pn[i],at[i],bt[i],ct[i],wt[i]);
    printf("Total waiting time:%d", twt);
} //END OF MAIN

output refer pic 2


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

//4. Least Recently Used Program
#include <stdio.h>
#include <conio.h>
int main()
{
    int n, rss, fa[20], rsa[50], ta[20]; //n-No_of_Frames
    //rss->Reference_String_Size::fa->Frame_Array
    //rsa->Reference_String_Array::ta->Temporary_Array
    int i,j,k,pfc=0,npf, cp;
    //cp->Current_Position ::pfc->Page_Fault_Count
    //npf:NO_Page_Faults [0-False, 1-True]
    printf("Enter number of frames: ");
    scanf("%d", &n);
    printf("Enter number of pages in reference string: ");
    scanf("%d", &rss);
    printf("Enter Reference string:\n");
    for(i=0; i<rss; i++)
        scanf("%d",&rsa[i]);
    for(i=0;i<n;i++)
        fa[i]=-1;
    for(i=0;i<n;i++)
        ta[i]=n-(i+1);
    printf("\nCURRENT_PAGE\t\tPAGES_IN_FRAME\t\tPAGE_FAULT_OCCURED?\n");
    for(i=0; i<rss; i++)
    {
        printf("\n\t%d\t\t",rsa[i]);
        npf=0;
        for(j=0;j<n;j++) //Checking for the page in FRAME ARRAY
        {
            if(fa[j]==rsa[i])
            {
                npf = 1;
                for(k=0;k<n;k++)
                ta[k]++;
                ta[j]=0;
                printf("\t\t\t\tNO");
                break;
            }
        }
        if(npf==0) // if page fault occurs
        {
            pfc++;
            cp=0;
            
            for(j=1;j<n;j++)
                if(ta[cp]<ta[j])
                    cp=j; //cp->current position
            fa[cp] = rsa[i];
            
            for(k=0;k<n;k++)
                ta[k]++;
            
            ta[cp]=0;
            
            for(j=0;j<n;j++)
                printf("%d\t",fa[j]);
            printf("\tYES");
        }
    }
    printf("\nTotal no of pagefaults: %d",pfc);
    return 0;
}

//5. First In First Out Program
#include <stdio.h>
#include <conio.h>
int main()
{
    int n, rss, fa[20], rsa[50]; //n-No_of_Frames
    //rss->Reference_String_Size::fa->Frame_Array
    //rsa->Reference_String_Array::ta->Temporary_Array
    int i,j,k,pfc=0,npf, cp=0;
    //cp->Current_Position :: ff->Frames_Filled ::pfc->Page_Fault_Count
    //npf:NO_Page_Faults [0-False, 1-True]
    printf("Enter number of frames: ");
    scanf("%d", &n);
    printf("Enter number of pages in reference string: ");
    scanf("%d", &rss);
    printf("Enter Reference string:\n");
    for(i=0; i<rss; i++)
        scanf("%d",&rsa[i]);
    for(i=0;i<n;i++)
        fa[i]=-1;
    printf("\nCURRENT_PAGE\t\tPAGES_IN_FRAME\t\tPAGE_FAULT_OCCURED?\n");
    for(i=0; i<rss; i++)
    {
        printf("\n\t%d\t\t",rsa[i]);
        npf=0;
        for(j=0;j<n;j++) //Checking for the page in FRAME ARRAY
        {
            if(fa[j]==rsa[i])
            {
                npf = 1;
                printf("\t\t\t\tNO");
                break;
            }
        }
        if(npf==0) // if page fault occurs
        {
            pfc++;
            fa[cp] = rsa[i];
            cp=(cp+1)%n;
            for(j=0;j<n;j++)
               printf("%d\t",fa[j]);
            printf("\tYES");
        }
    }
    printf("\nTotal no of pagefaults: %d",pfc);
    return 0;
}

//Aim: Simulate the File Allocation Strategies
//6. Sequential Program
#include<stdio.h>
#include<conio.h>
struct fileTable
{
    char name[20];
    int sb, nob;
}ft[30];
void main()
{
    int i, j, n;
    char s[20];
    clrscr();
    printf("Enter no of files :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter file name %d :",i+1);
        scanf("%s",ft[i].name);
        printf("Enter starting block of file %d :",i+1);
        scanf("%d",&ft[i].sb);
        printf("Enter no of blocks in file %d :",i+1);
        scanf("%d",&ft[i].nob);
    }
    printf("\nEnter the file name to be searched-- ");
    scanf("%s",s);
    for(i=0;i<n;i++)
        if(strcmp(s, ft[i].name)==0)
            break;
    if(i==n)
        printf("\nFile Not Found");
    else
    {
        printf("\nFILE NAME START BLOCK NO OF BLOCKS BLOCKS OCCUPIED\n");
        printf("\n%s\t\t%d\t\t%d\t",ft[i].name,ft[i].sb,ft[i].nob);
        for(j=0;j<ft[i].nob;j++)
        printf("%d, ",ft[i].sb+j);
    }
    getch();
}

//7. Indexed Program
#include<stdio.h>
#include<conio.h>
struct fileTable
{
    char name[20];
    int nob, blocks[30];
}ft[30];
void main()
{
    int i, j, n;
    char s[20];
    clrscr();
    printf("Enter no of files :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter file name %d :",i+1);
        scanf("%s",ft[i].name);
        printf("Enter no of blocks in file %d :",i+1);
        scanf("%d",&ft[i].nob);
        printf("Enter the blocks of the file :");
        for(j=0;j<ft[i].nob;j++)
            scanf("%d",&ft[i].blocks[j]);
    }
    printf("\nEnter the file name to be searched-- ");
    scanf("%s",s);
    for(i=0;i<n;i++)
        if(strcmp(s, ft[i].name)==0)
            break;
    if(i==n)
        printf("\nFile Not Found");
    else
    {
        printf("\nFILE NAME NO OF BLOCKS BLOCKS OCCUPIED");
        printf("\n %s\t\t%d\t",ft[i].name,ft[i].nob);
        for(j=0;j<ft[i].nob;j++)
            printf("%d, ",ft[i].blocks[j]); 
    }
    getch();
}

//8. Linked Program
#include<stdio.h>
#include<conio.h>
struct fileTable
{
    char name[20];
    int nob;
    struct block *sb;
}ft[30];
struct block
{
    int bno;
    struct block *next;
};
void main()
{
    int i, j, n;
    char s[20];
    struct block *temp;
    clrscr();
    printf("Enter no of files :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter file name %d :",i+1);
        scanf("%s",ft[i].name);
        printf("Enter no of blocks in file %d :",i+1);
        scanf("%d",&ft[i].nob);
        ft[i].sb=(struct block*)malloc(sizeof(struct block));
        temp = ft[i].sb;
        printf("Enter the blocks of the file :");
        scanf("%d",&temp->bno);
        temp->next=NULL;
        for(j=1;j<ft[i].nob;j++)
        {
            temp->next = (struct block*)malloc(sizeof(struct block));
            temp = temp->next;
            scanf("%d",&temp->bno);
        }
        temp->next = NULL;
    }
    printf("\nEnter the file name to be searched -- ");
    scanf("%s",s);
    for(i=0;i<n;i++)
        if(strcmp(s, ft[i].name)==0)
            break;
    if(i==n)
        printf("\nFile Not Found");
    else
    {
        printf("\nFILE NAME NO OF BLOCKS BLOCKS OCCUPIED");
        printf("\n %s\t\t%d\t",ft[i].name,ft[i].nob);
        temp=ft[i].sb;
        for(j=0;j<ft[i].nob;j++)
        {
            printf("%d ? ",temp->bno);
            temp = temp->next;
        }
    }
    getch();
}