#include<stdio.h>
int main()
{
    int n,m,allocated[50][50],max[50][50],available[50],need[50][50],finished[50],i,j;
    printf("Enter the Number of Processes: ");
    scanf("%d",&n);
    printf("Enter the Number of Resources: ");
    scanf("%d",&m);
    printf("Enter Resource allocatuin matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }
    printf("Enter max matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter instasnces avilable for each resources");
    for(i=0;i<m;i++){
    scanf("%d",&available[i]);}




//need matrix calculation
    for(i=0;i<n;i++)
    {   
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocated[i][j];
        }        
    }

    // finished[i] assigned to 0/
    for(i=0;i<n;i++)
    {
        finished[i]=0;
    }

    int k,y=0,seq[n],index=0;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(finished[i]==0)
            {
                int flag=1;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                {
                    seq[index++]=i;
                    finished[i]=1;
                    for(y=0;y<m;y++)
                      available[y]+=allocated[i][y];
                }
            }
        }
    }
    int flag=1;
    for(i=0;i<n;i++)
    {
        if(finished[i]==0)
        {
            flag=0;
            printf("No safe sequence");
            break;
        }
    }
    if(flag==1)
    {
        printf("safe sequence:\n");
        for(i=0;i<n;i++)
            printf("P%d->",seq[i]);
            printf("P%d",seq[n-1]);
    }

}
