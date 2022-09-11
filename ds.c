#include<stdio.h>  
#include<stdlib.h>                 //can be optimised by dma and n pointer

void opt1(int *arr,int n)              //traverse function   
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i));
    }
}

void opt2(int *arr,int n)               //insert function
{
    int item2,i;
    int pos2;
    printf("Enter value and position\n");
    scanf("%d%d",&item2,&pos2);
    for(i=n;i>=pos2-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos2-1]=item2;
    for(i=0;i<n+1;i++)
    {
        printf("%d\t",arr[i]);
    }
    
}
void opt3(int *arr,int n)                 // delete function
{
    int item3,pos3,i;
    printf("Enter position of element to be deleted");
    scanf("%d",&pos3);
    for(i=pos3-1;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d\t",arr[i]);
    }

}
void opt4(int *arr,int n)                 //search function                                                                                   
{                                           // can use binary search
    int item4,pos4=-1,i;
    printf("Enter item to be located");
    scanf("%d",&item4);
    for(i=0;i<n;i++) 
    {
        if(arr[i]==item4)
        {
            pos4=i;
            printf("%d is located at %d\n",item4,pos4+1);

        }

    }
    if(pos4==-1)
    printf("Element not found");
    

}
void opt5(int *arr,int n)
{
    int pos5,i,j,temp;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
     int n,a,i;
     int c;
     printf("Enter size of array you want to create");
     scanf("%d",&n);
     int *arr;
     arr=(int *)malloc(n*sizeof(int));
while(1)   
  {
    
     printf("Enter number of elements");
     scanf("%d",&n);
     arr=realloc(arr,n*sizeof(int));
     printf("Enter elements\n");
     for(i=0;i<n;i++)
     {
        scanf("%d",&arr[i]);
     }
  
      printf("Menu\n");
      printf("Choose the prefered operation\n");
      printf("1.Traverse\n2.Insertion\n3.Deletion\n4.Searching\n5.Sorting");
      scanf("%d",&a);
      switch(a)
      { 
        case 1:
        opt1(arr,n);
        break;
        case 2:
        opt2(arr,n);
        break;
        case 3:
        opt3(arr,n);
        break;
        case 4:
        opt4(arr,n);
        break;
        case 5:
        opt5(arr,n);
        break;
        default:
        printf("Invalid Option");
        break;
      }
      printf("\nDo you want another try\n");
      printf("Type 1 for Yes and 0 for No\n");
      scanf("%d",&c);
      if(c==0)
      {
        break;
      }
    
  }
  free(arr);
}
