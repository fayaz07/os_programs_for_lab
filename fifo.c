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