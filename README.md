# Test for Runs Up and Down

Test for Runs Up and Down is a two phase test for random
number generators.  The first phase calculates a Z-score
based on runs up and down.  The second phase calculates a
chi square test based on the length of all runs, both up
and down.

See the repository "Test for Runs Above and Below the Mean"
for information about that type of runs test.

The tests in this repository are applied against a variety
of random number generators, some weak and some strong.
The purpose of this repository is to show how the runs
test is performed, and what types of generators pass or
fail the test.  Dieharder random number generators are
not included in this repository.

For tests against dieharder random number generators, see
the repository "Template".

The inspiration for this repository is an online document
at Bucknell University by Professor Xiannong Meng.
Professor Meng has not updated his document since October
of 2002.  The programs in this repository illustrate how
the runs test is performed using the C language.

https://www.eg.bucknell.edu/~xmeng/Course/CS6337/Note/master/node44.html

Thanks to Dr. Meng for pointing us in the right direction for
this test.

The nomenclature that I use in the programs follows his
notation as much as possible.  Dr. Meng uses the subscript
alpha for variables used in the runs up and down test.

Example of ten samples.

The following is a list of ten samples.

	0.01
	0.14
	0.43
	0.76
	0.67
	0.71
	0.66
	0.88
	0.90
	0.40

The first  run is a run up   of length 3.
The second run is a run down of length 1.
The third  run is a run up   of length 1.
The fourth run is a run down of length 1.
The fifth  run is a run up   of length 2.
The sixth  run is a run down of length 1.

In this example there are

	4 runs of length 1
	1 run  of length 2
	1 run  of length 3

In a large test of ten million samples, the total number
of runs follows a normal distribution.  The length of
runs follows a chi square distribution.

Random number generators used in this test.

eegl64

The eegl64 random number generator is explained in the repository
"eegl64".  That is a random number generator based on a 64 bit
LFSR with a Bays Durham shuffle.  The period length of the eegl64
generator approximates 1.2 * 16^61036 generations.  That is a long
period length, that never terminates, or wraps around.  The eegl64
generator passes the runs up and down test.

----------------

Fibonacci

The fibonacci random number generator illustrates how a weak
random number generator fails both phases of the runs up and
down test.

The fibonacci generator is computed in the gen_dbl() function
in the runsfibo.c program.

fibonum1 = fibonum2
fibonum2 = fibonum3
fibonum3 = fibonum1 + fibonum2
fraction = fibonum3 / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

LFSR

The LFSR random number generator illustrates how a weak
random number generator fails both phases of the runs up
and down test.

The LFSR generator is computed in the gen_dbl() function in the
runslfsr.c program.  See the macro MYLFSR at the beginning of
the program for the algorithm used in the LFSR generator.  The
LFSR generator used is a 64 bit linear feedback shift register
with a period length of 2^64.

MYLFSR;
fraction = lfsr / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

RANDU

The RANDU random number generator illustrates how a weak
random number generator is able to pass Z-score part of
the runs up and down test and fail the chi square test.

The RANDU generator is computed in the gen_dbl() function
in the ruruns.c program.  RANDU is a 32 bit generator with
a period length of 2^30.

seed *= 65539;
fraction = seed / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

Sine Wave Generator

The sine random number generator illustrates how a weak
random number generator is able to pass the runs up and down
test.

The sine generator is computed in the gen_dbl() function
in the runsine.c program.  The sine generator has a long
enough period length to complete the test.

/* generate a uniform number between zero and PI */
radian = eeglunif(ee) * M_PI;
sinx = sin(radian);

sinx is a pseudo random number with a sine distribution
ranging from zero to one.

----------------

GNU Scientific Library Generators

The GSL generators illustrate how a variety of strong random
number generators perform well in the runs up and down test.

The GSL generators are computed in the gen_dbl() function
in the runsgsl.c program.  The GSL generators have a long
enough period length to complete the test.

fraction = gsl_rng_uniform(rng);

fraction is a strong random number with a uniform distribution
ranging from zero to one.

The following GSL generators fail the runs up and down test.
These same generators also fail the runs test above and below
the mean.  Randu is a weak generator and is expected to fail
the test.  However the random32 group of generators is puzzling,
because other groups of random??? generators pass the test.  For
example, the random256 group passes the test.

random32-bsd
random32-glibc2
random32-libc5
randu

----------------

If you have a random number generator that you want to include
in this repository, you are welcome to submit your generator for
inclusion.

Read the INSTALL and TESTING documents for more information
about how to use this repository.
