# Python3 program to multiply two matrices


def mulMat(mat1, mat2, R1, R2, C1, C2):
    # List to store matrix multiplication result
    result = [[0]*C2 for _ in range(R1)]

    for i in range(0, R1):
        for j in range(0, C2):
            for k in range(0, R2):
                result[i][j] += mat1[i][k] * mat2[k][j]

    print("Multiplication of given two matrices is:")
    for i in range(0, R1):
        for j in range(0, C2):
            print(result[i][j], end=" ")
        print("\n", end="")


# Driver code
if __name__ == '__main__':
    R1 = int(input())
    R2 = int(input())
    C1 = int(input())
    C2 = int(input())

    # First matrix. M is a list
    mat1 = [[0]*C1 for _ in range(R1)]
    for row in range(R1):
        for col in range(C1):
            mat1[row][col] = int(input())

    # Second matrix. N is a list
    mat2 = [[0]*C2 for _ in range(R2)]
    for row in range(R2):
        for col in range(C2):
            mat2[row][col] = int(input())

    if C1 != R2:
        print("The number of columns in Matrix-1 must be equal to the number of rows in " + "Matrix-2", end='')
        print("\n", end='')
        print("Please update MACROs according to your array dimension in #define section", end='')
        print("\n", end='')
    else:
        # Call matrix_multiplication function
        mulMat(mat1, mat2, R1, R2, C1, C2)
