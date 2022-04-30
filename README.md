# Comparison of shared_ptr and scoped_refptr
There is a smart pointer in Chromium called scoped_refptr
  
## Common to std::shared_ptr and scoped_refptr
std::shared_ptr and std::scoped_refptr have something in common in that they provide shared ownership. Also, both smartpointers are allocated memory in the heap to point to the objects they own.
  
## Difference between std::shared_ptr and scoped_refptr
std::shared_ptr additionally holds a pointer to a control block that does reference counting. On the other hand, scoped_refptr uses inheritance to do reference counting.
Therefore, std::shared_ptr will make one more malloc() call compared to scoped_refptr.

## Performance Comparison
After all, scoped_refptr is a smart pointer that improves performance by reducing malloc calls to one. This project compares the performance of keltion::shared_ptr, which mimics std::shared_ptr, and keltion::scoped_refptr, which mimics scoped_refptr.
  
## Result
<img width="50%" src="https://user-images.githubusercontent.com/76467273/162622655-ee3b4245-adb3-442d-ac9e-0263ff927ee9.png"/>
