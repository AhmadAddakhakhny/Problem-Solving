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
> Note: prefix sum shall be stored in an array or hash-table, depend on the case.  

### Fixed size sliding window
> Each two consecutive windows have a huge overlap.
> implementation: 1. build your window_sum in a separate loop, then start a new loop to 

### Variable size sliding window
> The window's length isn't fixed and need to be maintained (maximize/minimize) according to a condition (sum, frequency, count, length, etc.)  
> Remark: elements should be contiguous! AKA (subarray)  
##### Technique structure (usually O(n)):
1. start with a single window (e.g. start=end=0)
2. keep expanding its end for as long as possible (acc. to some criteria)
3. Once expansion shall not be possible, shrink the **start side** (start += 1) step by step until facing a valid window (acc. to some criteria). note: the challenge is to find the rule for shrink
4. Go to point 2.
