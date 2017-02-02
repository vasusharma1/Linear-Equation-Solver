# Linear-Equation-Solver
C++ console application to produce optimal solution to a linear equation's unknown values.
reference/motivation: https://arxiv.org/ftp/arxiv/papers/1308/1308.4675.pdf 
note: Currently input is not present, there is a default equation written inside code and can be changed as per use
Steps to use it:
1.> intially populate with number of chromosomes
2.> wait for the output.
3.> current equation is: 
      in mathematical form:- a+2b+3c+10d=30
      in code:- ((chromosome[i][j])+(2*(chromosome[i][j+1]))+(3*(chromosome[i][j+2]))+(10*(chromosome[i][j+3]))-30)
