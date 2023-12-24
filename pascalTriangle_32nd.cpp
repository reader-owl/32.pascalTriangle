#include <iostream>

/*
                    Q. Pascal's triangle

                explanation -  pascal's triangle -                  1               // (a)^1 = a                                // or just 1
                                                                  1   1             // (a + b)^1 = a + b                        // there is 1 on the sides, 
                                                                1   2   1           // (a + b)^2 = a^2 + 2ab + b^2              // there is 1 on the sides, in middle 1+1 = 2
                                                              1   3   3   1         // (a + b)^3 = a^3 + 3a^2.b + 3a.b^2 + b^3  // there is 1 on the sides, in middle 1+2 = 3 and 2+1 = 3
                                                            1   4   6   4   1       // similarly..                              // there is 1 on the sides , 1+3 = 4, 3+3 = 6, 3+1 = 4
                                                          1   5   10  10  5   1                                                 // there is 1 on the sides , 1+4 = 5, 4+6 = 10, 6+4 = 10, 4+1 = 5

                        there will be some questions related to pascal's triangle
                            1) Given Row & Column, find the element at that place
                                    Row = 5, Column = 3
                                    Answer - 6

                            2) Print any n-th row of the pascal triangle
                                    N = 5
                                    Answer -  1 4 6 4 1

                            3) Given N, print the entire triangle
                                    N = 6
                                    Answer -  we have to print the above entire above triangle


                1) lets solve the first question -  first approach will be to print entire triangle and get the value at R & C, which we will be using in Q.3)

                        for this question we will be using Combination (from permutation and combination)
                        we will do is - (R - 1) C (C - 1)  - 'R-1' combination of 'C-1'
                                        we also know   nCr =  n! / (r! * (n - r)!)

                                by combinations we can also deduce that -  7C2 =  7! / (2! * (5!))
                                                                               =  (7 * 6 * 5!) / (2! * 5!)
                                                                               =  (7 * 6) / (2 * 1)

                                                                    also  10C3 =  10! / (3! * 7!)
                                                                               =  (10 * 9 * 8) / (3 * 2 * 1)

                                            by these two we can observe that the digits remain in numerator to multiply is same as 
                                                factorial nmbr remains in denominator
                                            but we have to arrange it in a manner that it won't collide while multiplying
                                                    we do like for  10C3 -  (10/1) * (9/2) * (8/3)

         code
int nCr(int n, int r)
{
    long long res = 1;
    for(int i = 0; i < r; i++)
    {
        res = res * (n-i);
        res = res / (i + 1);
    }
    return res;
}

                TC - O(r)
                SC - O(1)


                 2) Print any n-th row of the pascal triangle -  we know that the nmbr of the elements is equal to the Row nmbr
                                                                like in 3rd Row there are 3 elements, in 6th Row there are 6 elements
                                                                                N-th row -> N elements

        pseudo code
for(c = 1; c <= n; c++)         // for column
{
    print(func nCr(n-1, c1))
}

                TC - O(n * r)

                    Optimal sol -  lets take 6th row and we can say that -  1  = 5C0 -> (5! / (0! * 5!))        // index 0
                                                                            5  = 5C1 -> (5! / (1! * 4!))        // index 1
                                                                            10 = 5C2 -> (5! / (2! * 3!))        // index 2
                                                                            10 = 5C3 -> (5! / (3! * 2!))        // index 3
                                                                            5  = 5C4 -> (5! / (4! * 1!))        // index 4
                                                                            1  = 5C5 -> (5! / (5! * 0!))        // index 5

                                we can say that -  ans = (row - column) / column

        pseudo code
ans = 1
print(ans)
for(i = 1; i<n; i++)
{
    ans = ans * (n-i)
    ans = ans / (i)
    print(ans)
}

                TC - O(N)
                SC - O(1)


                    3) Given N, print the entire triangle  -   we have to print -  1
                                                                                   1   1
                                                                                   1   2   1
                                                                                   1   3   3   1
                                                                                   1   4   6   4   1
                                                                                   1   5   10  10  5   1
                                            gonna use - (r-1)C(c-1)

        pseudo code
for(row=1->n)
{
    tempList = []
    for(col=1->row)
    {
        tempList.add(nCr(row-1, col-1));
    }
    ans.add(tempList);
}
return (ans)


                TC - O(n * n * n)
                     O(n^3)



                Optimal sol -  

        Actual code
// to print entire row
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);                        // 1 at the starting
    for(int col = 1; col < row; col++)          // column goes to the row
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// to print entire triangle
vector<vector<int>> pascalTriangle(int N)
{
    vector<vector<int>> ans;
    for(int i = 1; i <= N; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

                TC - O(N^2)
*/

int main()
{
    std::cout << "Hello World!\n";
}