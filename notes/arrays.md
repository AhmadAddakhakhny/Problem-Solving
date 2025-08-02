### Types of Array problems
> 1. Range problems: specific (start, end) subarray is required.  
> Techniques used: prefix/postfix sum, fixed-size, variable-size sliding window  
> 2. Two pointers problems: searching for something between two indices.  
> 3. Ad-hoc problems: no pattern, require observation.

### Prefix Sum (prod)
> A given array, its prefix sum array: pre[i] = sum A[0] + .... + A[i]  
> Remark: if the array elements are positive, then the prefix array is sorted. (Binary search can be used)  
> Similar concept, suffix sum  
> example array[] = {5,2,7,1,0,3,2}  
> prefix array[] = {5,7,14,15,15,18,20}  
