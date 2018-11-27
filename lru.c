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