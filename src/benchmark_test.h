#ifndef INCLUDE_BENCHMARK_TEST_H
#define INCLUDE_BENCHMARK_TEST_H

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("\ntime %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

char *load_all_benchmark_tests(void);

#endif // INCLUDE_BENCHMARK_TEST_H