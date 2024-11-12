#include<stdio.h>
#include<stdlib.h>






int* twosum(int* nums, int numsSize, int target, int* returnSize)
{

    Hashmap map;
    initmap(&map);

    *returnSize =2;
    int* result = (int *) malloc(2 * sizeof(int) );

    for(int i=0; i<numsSize; i++){
      int complement = target - nums[i];

      

    
    }
  




}
int main()
{
	int nums[] = {2,7,11,15};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int target = 9;

	int returnSize;

	// two sum
	
	int* result = twoSum(nums, 4, target, &returnSize);


	if(returnSize == 2){
	 printf("the indices --> [%d %d]\n",result[0],result[1]);
	}
	else{
	 printf("no match found \n");
	}



	free(result);

return 0;
}
