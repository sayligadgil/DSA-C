#include <stdio.h>
int LinearSearch(int arr[],int size,int target)
{
for (int i=0;i<size;i++)
{
 if(arr[i]==target)
 {
  return i;
 }
}
return -1;
}
int main()
{
 int n;
 printf("Enter the number of elements of the array:");
 scanf("%d", &n);

 int arr[n];
 printf("Enter the elements in the array:");
 for(int i=0;i<n;i++)
 scanf("%d", &arr[i]);

 int key;
 printf("Enter the element to search:");
 scanf ("%d", &key);

 int result=LinearSearch(arr,n,key);

 if(result != -1){
        printf("Element found at index %d\n", result);
 }else{
        printf("Element not found in the array\n");
}
return 0;
}

