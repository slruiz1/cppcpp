#include <iostream>

struct blockIdx {
	int x=0;
	int y=0;
} blockIdx;

struct {
	int x=0;
	int y=0;
} blockDim;

struct {
	int x=0;
	int y=0;
} threadIdx;

// -----------------------------------------------------------
/*__global__*/
void PictureKernel(float* d_Pin, float* d_Pout, int n,int m) {
	// Calculate the row # of the d_Pin and d_Pout element to process
	const int Row = blockIdx.y * blockDim.y + threadIdx.y;

	// Calculate the column # of the d_Pin and d_Pout element to process
	const int Col = blockIdx.x * blockDim.x + threadIdx.x;
	// each thread computes one element of d_Pout if in range
	if (Row < m && Col < n) {
		d_Pout[Row * n + Col] = 2 * d_Pin[Row * n + Col];
	}
} 

// Matrix multiplication on the (CPU) host (Tile Width)
void MatrixMulOnHost(double* M, double* N, double* P, int Width) {
	for (int i = 0; i < Width; ++i) {
		for (int j = 0; j < Width; ++j) {
			double sum = 0;
			for (int k = 0; k < Width; ++k) {
				double a = M[i * Width + k];
				double b = N[k * Width + j];
				sum += a * b;
			}
			P[i * Width + j] = sum;
		}
	}
}

/*__global__*/
void MatrixMulKernel(float* d_M, float* d_N, float* d_P, int Width) {
	// Calculate the row index of the d_P element and d_M
	int Row = blockIdx.y*blockDim.y+threadIdx.y;
	// Calculate the column index of d_P and d_N
	int Col = blockIdx.x*blockDim.x+threadIdx.x;
	if (Row < Width && Col < Width) {
		float Pvalue = 0;
		// each thread computes one element of the block sub-matrix
		for (int k = 0; k < Width; ++k) {
			Pvalue += d_M[Row*Width+k] * d_N[k*Width+Col];
		}
		d_P[Row*Width+Col] = Pvalue;
	}
}

int main()
{
	// each row has 32-bit integers ...
        int array[3][4] = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}
        };

        // Print the array elements and their memory addresses
        // Q: Given an 2D array assume that we are reading it element in row order and column order which would be better/faster?
        // A: row order, iterate thru rows first reading memory sequentially
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 4; ++j) {
                        std::cout << "row[" << i << "], col[" << j << "] = " << array[i][j]
                                << " Address: " << &array[i][j] << std::endl;
                }
        }
	printf (">>> Iterate by col first...\n");
        for (int j = 0; j < 4; ++j) {
        	for (int i = 0; i < 3; ++i) {
                        std::cout << "row[" << i << "], col[" << j << "] = " << array[i][j]
                                << " Address: " << &array[i][j] << std::endl;
                }
        }

        return 0;
}
