
# SAT-Solver-Applications-to-Concurrency-and-Tiling-Problems
[(Back to top)](#table-of-contents)
SAT-Solver_Applications-to-Concurrency-and-Tiling-Problems is a project focused on determining the satisfiability or unsatisfiability of logical formulations arising from concurrency scenarios and domino-tiling problems, using the Lingeling SAT solver.

## Table of Contents
- [SAT-Solver-Applications-to-Concurrency-and-Tiling-Problems](#sat-solver-applications-to-concurrency-and-tiling-problems)
- [Table of Contents](#table-of-contents)
- [Brief Overview](#brief-overview)
- [Data Sources](#data-sources)
- [History](#history)
- [Results](#results)
- [Extension](#extension)
## Brief Overview
[(Back to top)](#table-of-contents)

The project entailed developing clause formulations for applications such as Concurrency and Tiling Problems, and using the Lingeling SAT solver to evaluate the satisfiability or unsatisfiability of these clause sets. The work involved encoding each problem into propositional logic, generating the appropriate clauses, and verifying their correctness using the Lingeling SAT solver.
In the first part, the clauses are generated manually, whereas in the second part, the clauses are produced automatically using C++ programs that construct the SAT encoding based on the blocks being removed.
In addition to clause generation and verification, the project also involved tuning the elim parameter of Lingeling to analyze how different elimination settings affect the performance of the SAT solver across various scenarios.
## Data Sources
[(Back to top)](#table-of-contents)

To access the problem statements, refer to the book The Art of Computer Programming.

To download or explore the Lingeling SAT solver, visit:
http://www.satlive.org/solvers/

To obtain the benchmark instances used in this project, use:
https://satcompetition.github.io/2021/downloads.html
## History
[(Back to top)](#table-of-contents)

SAT solving has evolved significantly since SAT was first shown to be NP-complete by Stephen Cook in 1971. Early approaches based on simple backtracking were replaced by powerful algorithms such as DPLL and modern CDCL techniques, enabling large-scale practical solving. Over time, SAT solvers like Lingeling have incorporated advanced optimizations, making them effective tools for analyzing complex problems such as concurrency verification and tiling constraints.
## Results
[(Back to top)](#table-of-contents)

In the first part, the generated clauses confirm that no two processes can enter the critical section simultaneously. The initial setup also guarantees the absence of starvation and deadlock.
In the second part, the SAT solver verifies that if two blocks of the same color are removed, it becomes impossible to tile the grid completely with dominos; otherwise, a valid tiling exists.
For the bonus part, experiments showed that for the given benchmark data, the setting elim = 0 delivered better performance compared to elim = 5 and elim = 10.

## Extension
[(Back to top)](#table-of-contents)

The algorithm designed for handling the removal of up to two blocks can be extended to support any number of removed blocks by introducing an additional loop and maintaining an appropriate flag.
