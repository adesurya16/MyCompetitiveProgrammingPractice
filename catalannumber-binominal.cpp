// A Binomial coefficient based function to find nth catalan 
// number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
	// Calculate value of 2nCn 
	unsigned long int c = binomialCoeff(2*n, n); 

	// return 2nCn/(n+1) 
	return c/(n+1); 
} 

// Driver program to test above functions 
int main() 
{ 
	for (int i = 0; i < 10; i++) 
		cout << catalan(i) << " "; 
	return 0; 
} 